#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

#define DATA_TXT    "data.txt"
#define OUTPUT_TXT  "output.txt"

#define NUM           1024
#define SPACE         ' '
#define SPACE_SIZE    4
#define LABEL_LINE    3
#define LABEL_FORMAT  " %4d"
#define ROW_SPACE     6
#define ROW_FORMAT    "%6d"

// Error Code
#define FILE_NOTHING  -1
#define OPEN_ERROR    -2
#define RANGE_ERROR   -3
#define DATA_NOTHING  -4
#define DATA_ERROR    -5
#define OTHER_ERROR   -6

/* Make Histogram!                */
/* Input data in data.txt         */
/* Output histogram to output.txt */
/*                                */
/* 15JN0108 Onogaki Kaichi        */
/* Char Code = UTF-8              */

typedef struct {
  int min;                //最小値
  int max;                //最大値
} min_max_t;

typedef struct {
  FILE *inputp;            //data.txt(入力ファイル)のポインタ
  FILE *tmp_data;          //tmpfile(データ一時退避ファイル)のポインタ
  FILE *outputp;           //output.txt(出力ファイル)のポインタ
} files_t ;

/*Prototype Declaration*/
int       histogram_main(files_t *files);
int       open_files(files_t *files);
void      create_file(void);
void      error_msg(int flag);
int       read_data(files_t *files, min_max_t *min_max, int *range);
int       *initialize_cnt(int cnt[], int i_max);
int       aggregate(FILE *tmp_data,int cnt[], int *cnt_max, int range, int redunce, int i_max);
int       make_histogram(int i_max, int cnt_max, int cnt[], char histogram[][NUM]);
int       initialize_histogram(int i_max, int cnt_max, char histogram[][NUM]);
void      writer(char ch, int num, FILE *outputp);
int       draw_histogram(FILE *outputp, int i_max, int cnt_max, int cnt[], char histogram[][NUM]);
int       axis_label(FILE *outputp, int min, int range, int i_max);
void      close_files(files_t *files);

/**** main program **************************************************************/
int main(void)
{
  files_t files;
  int     ret;

  //3つのファイルを開く　なければ作る
  if((ret = open_files(&files)) == 1){
    if(histogram_main(&files)){
      error_msg(OTHER_ERROR);
    }
    close_files(&files);
  } else if(ret == 0){
    error_msg(OPEN_ERROR);
  } else{
    create_file();
  }

  return EXIT_SUCCESS;
}
/********************************************************************************/
int histogram_main(files_t *files)
{
  int         range;                        //データを区切る範囲
  int         redunce;                      //最小級を添字0に合わせる
  int         i_max;                        //級の数
  int         cnt[NUM];                     //階級ごとの頻度
  int         cnt_max;                      //最大頻度
  char        histogram[NUM][NUM];          //ヒストグラム
  min_max_t   min_max;                      //最小・最大数値
  int         ret = 0;

  //データにエラーがなければtrue
  if((ret = read_data(files, &min_max, &range)) > 0){
    ret = 0;
    //級の数(cntの使用数)を求める(i_max)
    i_max = (min_max.max / range * range - min_max.min / range * range) / range + 1;

    //最小級を添字0に合わせる
    redunce = min_max.min / range;

    //return tmpfile!
    rewind(files->tmp_data);

    //データの集計
    if(aggregate(files->tmp_data, cnt, &cnt_max, range, redunce, i_max)){
      /*  ↑集計       描画↓    */
      //ヒストグラムの作成
      if(make_histogram(i_max, cnt_max, cnt, histogram)){
        //ヒストグラム描画処理
        if(draw_histogram(files->outputp, i_max, cnt_max, cnt, histogram)){
          if(axis_label(files->outputp, min_max.min, range, i_max)){
            MessageBox(NULL, TEXT("Successful!\nCreated histogram in [output.txt]."),
              TEXT("Successful Create Histogram"), MB_OK);
            ret = 1;
          }
        }
      }
    }
  }

  return ret;
}
/********************************************************************************/
//3つのファイルを開く
int open_files(files_t *files)
{
  int open_flag = 0;

  if ((files->inputp = fopen(DATA_TXT, "r")) == NULL) {
    /*Failed open data.txt*/
    open_flag = -1;
  } else if ((files->tmp_data = tmpfile()) == NULL ){
    /*Failed open data.bin*/
    fclose(files->inputp);
  } else if ((files->outputp = fopen(OUTPUT_TXT, "w")) == NULL) {
    /*Failed open output.txt*/
    fclose(files->inputp);
    fclose(files->tmp_data);

  } else {
    /*Successful open all files*/
    open_flag = 1;
  }
  return open_flag;
}
/********************************************************************************/
//data.txtを作る
void create_file(void)
{
  FILE *inputp;

  inputp = fopen(DATA_TXT, "w");
  fprintf(inputp, "ClassWidth:\n");
  MessageBox(NULL, TEXT("Created [data.txt].\n[Format]\n1st Line:[ClassWidth:(Class Width)]\n2nd line later:[(data)]"),
      TEXT("Histogram"), MB_OK);
  fclose(inputp);
}
/********************************************************************************/
void error_msg(int error_code)
{
  if(error_code == DATA_NOTHING){
    MessageBox(NULL, TEXT("ERROR!!\nThere is NO DATA in [data.txt]\n[Format]\n1st Line:[ClassWidth:(Class Width)]\n2nd line later:[(data)]"),
      TEXT("Histogram ERROR"), MB_OK);
  } else if(error_code == DATA_ERROR){
    MessageBox(NULL, TEXT("ERROR!!\nThere is typing error in [data.txt]\n[Format]\n1st Line:[ClassWidth:(Class Width)]\n2nd line later:[(data)]"),
      TEXT("Histogram ERROR"), MB_OK);
  } else if(error_code == OPEN_ERROR){
    MessageBox(NULL, TEXT("ERROR!!\nFailed open Files!"),
      TEXT("Histogram ERROR"), MB_OK);
  } else if(error_code == RANGE_ERROR){
    MessageBox(NULL, TEXT("ERROR!!\nClass Width is NOTHING or 0!\n[Format]\n1st Line:[ClassWidth:(Class Width)]\n2nd line later:[(data)]"),
      TEXT("Histogram ERROR"), MB_OK);
  } else if(error_code == OTHER_ERROR){
    MessageBox(NULL, TEXT("ERROR!!\nOops! Sorry, it occurs some processing error...\nPlease check files and run one more time"),
      TEXT("Histogram ERROR"), MB_OK);
  }
}
/********************************************************************************/
//データを一時ファイルに書き込み・データの最大値、最小値を求める
int read_data(files_t *files, min_max_t *min_max, int *range)
{
  int indat;
  int ret;
  int data_flag;

  if (fscanf(files->inputp, "ClassWidth:%d", range) != EOF || *range != 0){
    ret = fscanf(files->inputp, "%d", &indat);           //1stData
    if(ret != 0 && ret != EOF){
      min_max->min = indat;
      min_max->max = indat;
      fwrite(&indat, sizeof(int), 1, files->tmp_data);
      data_flag = 1;

      ret = fscanf(files->inputp, "%d", &indat);        //2ndData on and after
      while(ret != 0 && ret != EOF){
        min_max->min = fmin(min_max->min, indat);
        min_max->max = fmax(min_max->max, indat);

        fwrite(&indat, sizeof(int), 1, files->tmp_data);
        ret = fscanf(files->inputp, "%d", &indat);
      }
      if(ret == 0){
        data_flag = DATA_ERROR;
      }

    } else{
      data_flag = DATA_NOTHING;
    }

  } else{
    data_flag = RANGE_ERROR;
  }

  if(data_flag < 0){
    error_msg(data_flag);
    data_flag = 0;
  }

  return data_flag;
}
/********************************************************************************/
int *initialize_cnt(int cnt[], int i_max)
{
  int i;

  for (i = 0; i < i_max + 1; i++){
    cnt[i] = 0;
  }
  return cnt;
}
/********************************************************************************/
int aggregate(FILE *tmp_data,int cnt[], int *cnt_max, int range, int redunce, int i_max)
{
  int indat;
  int i;
  int ret = 0;

  //cntの初期化
  initialize_cnt(cnt, i_max);

  while (fread(&indat, sizeof(int), 1, tmp_data)){
    cnt[indat / range - redunce]++;
  }

  *cnt_max = 0;
  for(i = 0; i < i_max; i++){
    if(*cnt_max < cnt[i]){
      *cnt_max = cnt[i];
    }
  }

  if(*cnt_max > 0 && *cnt_max < NUM){
    ret = 1;
  }

  return ret;
}
/********************************************************************************/
int make_histogram(int i_max, int cnt_max, int cnt[], char histogram[][NUM])
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

  return i;
}
/********************************************************************************/
int initialize_histogram(int i_max, int cnt_max, char histogram[][NUM])
{
  int i;
  int j;

  for (i = 0; i < i_max + 1; i++){
    for (j = 0; j <= cnt_max; j++){
      histogram[i][j] = SPACE;
    }
  }
  return i;
}
/********************************************************************************/
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
/********************************************************************************/
int draw_histogram(FILE *outputp, int i_max, int cnt_max, int cnt[], char histogram[][NUM])
{
  int i, j;
  int low_next;

  // Row
  for (j = cnt_max ; j >= 0; j--){
    if (j % 5 == 0){
      fprintf(outputp, ROW_FORMAT, j);
    } else{
      writer(SPACE, ROW_SPACE, outputp);
    }
    fprintf(outputp, "_|");

    low_next = 0;
    // Column
    for (i = 0; i < i_max; i++){
      if(low_next == 0){
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

      if(cnt[i] > cnt[i + 1]){
        writer(histogram[i][j], 1, outputp);
        low_next = 1;
      } else{
        low_next = 0;
      }
    }
    fprintf(outputp, "\n");
  }
  return i;
}
/********************************************************************************/
int axis_label(FILE *outputp, int min, int range, int i_max)
{
  int i, j;

  while (min > 10000){
    min = min / 1000;
    range = range / 1000;
  }
  for(i = 0; i < LABEL_LINE; i++){
    writer(SPACE, ROW_SPACE + 2, outputp);
    for (j = 0; j < i_max; j++){
      if(i == 0){
        fprintf(outputp, LABEL_FORMAT, min / range * range + range * j);
      } else if(i == 1){
        writer(SPACE, SPACE_SIZE - 1, outputp);
        fprintf(outputp, "| ");
      } else if(i == 2){
        fprintf(outputp, LABEL_FORMAT, min / range * range + range * (j + 1) - 1);
      }
    }
    fprintf(outputp, "\n");
  }
  return i;
}
/********************************************************************************/
//Close files.
void close_files(files_t *files)
{
  fclose(files->inputp);
  fclose(files->tmp_data);
  fclose(files->outputp);
}
