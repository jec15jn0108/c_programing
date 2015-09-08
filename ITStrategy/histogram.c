#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

#define  DATA_TXT    "data.txt"
#define OUTPUT_TXT  "output.txt"

#define NUM      1024
#define SPACE    ' '
#define SPACE_SIZE  4

/* ヒストグラムを書く                */
/* 15JN0108 Onogaki Kaichi		  */
/* Char Code = UTF-8            */

typedef struct {
  int min;  //最小値
  int max;  //最大値
} min_max_t;

typedef struct {
  FILE *inputp;            //data.txt(入力ファイル)のポインタ
  FILE *tmp_data;          //tmpfile(データ一時退避ファイル)のポインタ
  FILE *outputp;           //output.txt(出力ファイル)のポインタ
} files_t ;

/*Prototype Declaration*/
void      histogram_main(files_t *files);
int       open_files(files_t *files);
void      create_files(void);
void      error_msg(int flag);
int       read_data(files_t *files, min_max_t *min_max, int *range);
void      initialize_cnt(int i_max, int cnt[]);
void      aggregate(FILE *tmp_data,int cnt[], int *cnt_max, int range, int redunce, int i_max);
void      make_histogram(int i_max, int cnt_max, int cnt[], char histogram[][NUM]);
void      initialize_histogram(int i_max, int cnt_max, char histogram[][NUM]);
void      writer(char ch, int num, FILE *outputp);
void      draw_histogram(FILE *outputp, int i_max, int cnt_max, int cnt[], char histogram[][NUM]);
void      axis_label(FILE *outputp, int min, int range, int i_max);
void      close_files(files_t *files);

/**** main program ***********************************************************************/
int main(void)
{
  files_t files;

  //3つのファイルを開く　なければ作る
  if(open_files(&files)){
    histogram_main(&files);
    close_files(&files);
  }

  return 0;
}
/******************************************************************************************************/
void histogram_main(files_t *files)
{
  int         range;                        //データを区切るrange
  int         redunce;                      //最小級を添字0に合わせる
  int         i_max;                        //級の数
  int         cnt[NUM];                     //階級ごとの頻度
  int         cnt_max;                      //最大頻度
  char        histogram[NUM][NUM];          //ヒストグラム
  min_max_t   min_max;                      //

  //データにエラーがなければtrue
  if(read_data(files, &min_max, &range)){

    //級の数(cntの使用数)を求める(i_max)
    i_max = (min_max.max / range * range - min_max.min / range * range) / range + 1;

    //最小級を添字0に合わせる
    redunce = min_max.min / range;

    //cntの初期化
    initialize_cnt(i_max, cnt);

    //return tmpfile!
    rewind(files->tmp_data);

    //データの集計
    aggregate(files->tmp_data, cnt, &cnt_max, range, redunce, i_max);

    /*  ↑集計       描画↓    */

    //ヒストグラムの作成
    make_histogram(i_max, cnt_max, cnt, histogram);

    //ヒストグラム描画処理
    draw_histogram(files->outputp, i_max, cnt_max, cnt, histogram);
    axis_label(files->outputp, min_max.min, range, i_max);

    MessageBox(NULL, TEXT("Successful!\nCreated histogram in [output.txt]."),
        TEXT("Successful Create Histogram"), MB_OK);
  }
}
/******************************************************************************************************/
//3つのファイルを開く
int open_files(files_t *files)
{
  int open_flag = 0;

  if ((files->inputp = fopen(DATA_TXT, "r")) == NULL) {
    /*Failed open data.txt*/
    create_files();
  } else if ((files->tmp_data = tmpfile()) == NULL ){
    /*Failed open data.bin*/
    fclose(files->inputp);
  } else if ((files->outputp = fopen(OUTPUT_TXT, "w")) == NULL) {
    /*Failed open output.txt*/
    fclose(files->inputp);
    fclose(files->tmp_data);
  } else {
    open_flag = 1;
    /*Successful open all files*/
  }
  return open_flag;
}
/******************************************************************************************************/
//data.txtを作る
void create_files(void)
{
  FILE *inputp;

  inputp = fopen(DATA_TXT, "w");
  fprintf(inputp, "ClassWidth:\n");
  MessageBox(NULL, TEXT("Created [data.txt].\n[Format]\nFirst Line:[ClassWidth:(Class Width)]\nSecond line later:[(data)]"),
      TEXT("Histogram"), MB_OK);
  fclose(inputp);
}
/******************************************************************************************************/
void error_msg(int flag)
{
  if(flag == 0){
    MessageBox(NULL, TEXT("ERROR!!\nThere is NO DATA in [data.txt] or Class Width is 0.\n[Format]\nFirst Line:[ClassWidth:(Class Width)]\nSecond line later:[(data)]"),
      TEXT("Histogram ERROR"), MB_OK);
  } else if(flag == -1){
    MessageBox(NULL, TEXT("ERROR!!\nThere is typing error in [data.txt]\n[Format]\nFirst Line:[ClassWidth:(Class Width)]\nSecond line later:[(data)]"),
      TEXT("Histogram ERROR"), MB_OK);
  }
}
/******************************************************************************************************/
//データを一時ファイルに書き込み・データの最大値、最小値を求める
int read_data(files_t *files, min_max_t *min_max, int *range)
{
  int indat;
  int ret;
  int data_flag = 0;

  if (fscanf(files->inputp, "ClassWidth:%d", range) != EOF || *range != 0){
    ret = fscanf(files->inputp, "%d", &indat);           //FirstData
    if(ret != 0 && ret != EOF){
      min_max->min = indat;
      min_max->max = indat;
      fwrite(&indat, sizeof(int), 1, files->tmp_data);
      data_flag = 1;

      ret = fscanf(files->inputp, "%d", &indat);        //SecondData on and after
      while(ret != 0 && ret != EOF){
        min_max->min = fmin(min_max->min, indat);
        min_max->max = fmax(min_max->max, indat);

        fwrite(&indat, sizeof(int), 1, files->tmp_data);
        ret = fscanf(files->inputp, "%d", &indat);
      }

      if(ret == 0){
        data_flag = -1;
      }
    }
  }

  if(data_flag <= 0){
    error_msg(data_flag);
    data_flag = 0;
  }

  return data_flag;
}
/******************************************************************************************************/
void initialize_cnt(int i_max, int cnt[])
{
  int i;

  for (i = 0; i < i_max + 1; i++){
    cnt[i] = 0;
  }
  return;
}
/******************************************************************************************************/
void aggregate(FILE *tmp_data,int cnt[], int *cnt_max, int range, int redunce, int i_max)
{
  int indat;
  int i;

  while (fread(&indat, sizeof(int), 1, tmp_data)){
    cnt[indat / range - redunce]++;
  }

  *cnt_max = 0;
  for(i = 0; i < i_max; i++){
    if(*cnt_max < cnt[i]){
      *cnt_max = cnt[i];
    }
  }
}
/******************************************************************************************************/
void make_histogram(int i_max, int cnt_max, int cnt[], char histogram[][NUM])
{
  int i;
  int j;

  initialize_histogram(i_max, cnt_max, histogram);

  for (i = 0; i < i_max; i++){
    for (j = 0; j <= cnt_max; j++){
      if (cnt[i] > j){
        histogram[i][j] = '|';
      } else if (cnt[i] == j){
        histogram[i][j] = '_';
      }
    }
  }
}
/******************************************************************************************************/
void initialize_histogram(int i_max, int cnt_max, char histogram[][NUM])
{
  int i;
  int j;

  for (i = 0; i < i_max + 1; i++){
    for (j = 0; j <= cnt_max; j++){
      histogram[i][j] = SPACE;
    }
  }
}
/******************************************************************************************************/
void writer(char ch, int num, FILE *outputp)
{
  int i;

  if(ch == '_' && num <= 1){
    ch = SPACE;
  }

  for( i = 0; i < num; i++){
    fprintf(outputp, "%c", ch);
  }
}
/******************************************************************************************************/
void draw_histogram(FILE *outputp, int i_max, int cnt_max, int cnt[], char histogram[][NUM])
{
  int i, j;
  int flag;

  // Y軸
  for (j = cnt_max ; j >= 0; j--){
    if (j % 5 == 0){
      fprintf(outputp, "%6d", j);
    } else{
      writer(SPACE, 6, outputp);
    }
    fprintf(outputp, "_|");
    flag = 0;
    // X軸
    for (i = 0; i < i_max; i++){
      if(flag == 0){
        writer(histogram[i][j], 1, outputp);
      }

      if(histogram[i][j] != '_'){
        if (j != 0){
          writer(SPACE, SPACE_SIZE, outputp);
        } else{
          writer('_', SPACE_SIZE, outputp);
        }
      } else{
        writer('_', SPACE_SIZE, outputp);
      }
      flag = 0;

      if(cnt[i] > cnt[i + 1]){
        writer(histogram[i][j], 1, outputp);
        flag = 1;
      }
    }
    fprintf(outputp, "\n");
  }
}
/******************************************************************************************************/
void axis_label(FILE *outputp, int min, int range, int i_max)
{
  int i;

  while (min > 10000){
    min = min / 1000;
    range = range / 1000;
  }
  fprintf(outputp, "\n");
  writer(SPACE, 5, outputp);
  for (i = 0; i < i_max; i++){
    fprintf(outputp, "%5d", min / range * range + range * i);
  }
  fprintf(outputp, "\n");
  writer(SPACE, 5, outputp);
  for (i = 0; i < i_max; i++){
    fprintf(outputp, "   | ");
  }
  fprintf(outputp, "\n");
  writer(SPACE, 5, outputp);
  for (i = 0; i < i_max - 1; i++){
    fprintf(outputp, "%5d", min / range * range + range * (i + 1) - 1);
  }

}
/******************************************************************************************************/
//Close files.
void close_files(files_t *files)
{
  fclose(files->inputp);
  fclose(files->tmp_data);
  fclose(files->outputp);
}
