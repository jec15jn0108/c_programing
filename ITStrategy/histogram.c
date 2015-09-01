#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define  DATA_TXT    "data.txt"
#define OUTPUT_TXT  "output.txt"

#define NUM      1000
#define SPACE    ' '
#define SPACENUM  4

/* �q�X�g�O����������             */
/* 15JN0108 Onogaki Kaichi		  */

typedef struct {
  int min;  //�ŏ��l
  int max;  //�ő�l
} min_max_t;

typedef struct {
  FILE *inputp;            //data.txt(���̓t�@�C��)�̃|�C���^
  FILE *tmp_data;          //tmpfile(�f�[�^�ꎞ�ޔ��t�@�C��)�̃|�C���^
  FILE *outputp;           //output.txt(�o�̓t�@�C��)�̃|�C���^
} files_t ;

/*Prototype Declaration*/
void      histogram_main(void);
int       open_files(files_t *files, int *range);
void      create_files(void);
void      error_msg(void);
int       read_data(files_t *files, min_max_t *min_max);
void      initialize_cnt(int i_max, int *cnt);
void      initialize_histogram(int i_max, int cnt_max, char histogram[][NUM]);
void      aggregate(FILE *tmp_data,int *cnt, int *cnt_max, int range, int redunce, int i_max);
void      make_histogram(int i_max, int cnt_max, int cnt[], char histogram[][NUM]);
void      writer(char ch, int num, FILE *outputp);
void      draw_histogram(FILE *outputp, int i_max, int cnt_max, int cnt[], char histogram[][NUM]);
void      axis_label(FILE *outputp, int min, int range, int i_max);
void      close_files(files_t *files);


/**** main program ***********************************************************************/
int main(void)
{
  histogram_main();
  return 0;
}

/******************************************************************************************************/
void histogram_main(void)
{
  int         flag;                         //�t�@�C�����J�������E�f�[�^�����͂���Ă��邩�̔��f
  int         range;                        //�f�[�^����؂�range
  int         redunce;                      //�ŏ�����Y��0�ɍ��킹��
  int         i_max;                        //���̐�
  int         cnt[NUM];                     //�K�����Ƃ̕p�x
  int         cnt_max;                      //�ő�p�x
  char        histogram[NUM][NUM];          //
  min_max_t   min_max;                      //
  files_t     files;                        //3�̃t�@�C��

  //3�̃t�@�C�����J���@�Ȃ���΍��
  flag = open_files(&files, &range);

  /*�f�[�^�̍ő�l�E�ŏ��l�����߂�*/
  /*�f�[�^���ꎞ�o�C�i���t�@�C���ɏ����o��*/
  if(flag == 1){
    flag = read_data(&files, &min_max);
  }

  if(flag){
    //���̐�(cnt�̎g�p��)�����߂�(i_max)
    i_max = (min_max.max / range * range - min_max.min / range * range) / range + 1;

    //�ŏ�����Y��0�ɍ��킹��
    redunce = min_max.min / range;

    //cnt�̏�����
    initialize_cnt(i_max, cnt);

    // fclose(files.tmp_data);
    // files.tmp_data = fopen(TMP_DATA, "rb");
    // if(files.tmp_data == NULL){
    //   MessageBox(NULL, TEXT("�G���[���������܂���"),
    //       TEXT("�q�X�g�O����"), MB_OK);
    // }
    //return tmpfile!
    rewind(files.tmp_data);

    //�f�[�^�̏W�v
    aggregate(files.tmp_data, cnt, &cnt_max, range, redunce, i_max);

    //�q�X�g�O�����̍쐬
    make_histogram(i_max, cnt_max, cnt, histogram);

    //�q�X�g�O�����`�揈��
    draw_histogram(files.outputp, i_max, cnt_max, cnt, histogram);
    axis_label(files.outputp, min_max.min, range, i_max);

    MessageBox(NULL, TEXT("[output.txt]���o�͂��܂����B"),
        TEXT("Histogram"), MB_OK);
  }
  close_files(&files);
}

/******************************************************************************************************/
int open_files(files_t *files, int *range)
{
  int open_flag = 0;

  if ((files->inputp = fopen(DATA_TXT, "r")) == NULL) {
    /*Failed open data.txt*/
    create_files();
  }
    else if ((files->tmp_data = tmpfile()) == NULL ){
    /*Failed open data.bin*/
    fclose(files->inputp);
  }
  else if ((files->outputp = fopen(OUTPUT_TXT, "w")) == NULL) {
    /*Failed open output.txt*/
    fclose(files->inputp);
    fclose(files->tmp_data);
  }
  else {
    /*Successful open all files*/
    if (fscanf(files->inputp, "range:%d", range) == EOF || *range == 0){
      error_msg();
    }
    else{
      open_flag = 1;
    }
  }
  return open_flag;
}
/******************************************************************************************************/
//data.txt�����A�f�[�^�������̂��x��
void create_files(void)
{
  FILE *inputp;

  inputp = fopen(DATA_TXT, "w");
  fprintf(inputp, "range:\n");
  MessageBox(NULL, TEXT("[data.txt]��V�K�쐬���܂����B\n[����]\n1�s��:��؂�͈�\n2�s�ڈȍ~:���l(1���Ƃɉ��s)\n�������ɂ͖��Ή���\n"),
      TEXT("�q�X�g�O����"), MB_OK);
  fclose(inputp);
}
/******************************************************************************************************/
void error_msg(void)
{
  MessageBox(NULL, TEXT("[data.txt]�Ƀf�[�^�������A���̓~�X���L��A�܂���range��0�ł��B\n[����]\n1�s��:��؂�͈�\n2�s�ڈȍ~:���l(1���Ƃɉ��s)\n�������ɂ͖��Ή���\n"),
    TEXT("�q�X�g�O����"), MB_OK);
}
/******************************************************************************************************/
//�f�[�^���ꎞ�t�@�C���ɏ������݁E�f�[�^�̍ő�l�A�ŏ��l�����߂�
int read_data(files_t *files, min_max_t *min_max)
{
  int indat;
  int ret;
  int data_flag = 0;

  ret = fscanf(files->inputp, "%d", &indat);             //FirstData
  if(ret != 0 && ret != EOF){
    min_max->min = indat;
    min_max->max = indat;
    fwrite(&indat, sizeof(int), 1, files->tmp_data);
    data_flag = 1;

    ret = fscanf(files->inputp, "%d", &indat);          //SecondData on and after
    while(ret != 0 && ret != EOF){
      if (min_max->max < indat){
        min_max->max = indat;
      }
      if (min_max->min > indat){
        min_max->min = indat;
      }
      fwrite(&indat, sizeof(int), 1, files->tmp_data);
      ret = fscanf(files->inputp, "%d", &indat);
    }
    if(ret == 0){
      data_flag = 0;
    }
  }

  if(data_flag == 0){
    error_msg();
  }

  return data_flag;
}
/******************************************************************************************************/
void initialize_cnt(int i_max, int *cnt)
{
  int i;

  for (i = 0; i < i_max + 1; i++){
    cnt[i] = 0;
  }
  return;
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
void aggregate(FILE *tmp_data,int *cnt, int *cnt_max, int range, int redunce, int i_max)
{
  int indat;
  int i;

  while (fread(&indat, sizeof(int), 1, tmp_data)){
    cnt[indat / range - redunce] += 1;
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
      }
      else if (cnt[i] == j){
        histogram[i][j] = '_';
      }
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

  // Y��
  for (j = cnt_max ; j >= 0; j--){
    if (j % 5 == 0){
      fprintf(outputp, "%3d", j);
    }
    else{
      writer(SPACE, 3, outputp);
    }
    fprintf(outputp, "_|");

    flag = 0;
    // X��
    for (i = 0; i < i_max; i++){
      if(flag == 0){
        writer(histogram[i][j], 1, outputp);
      }

      if(histogram[i][j] != '_'){
        if (j != 0){
          writer(SPACE, SPACENUM, outputp);
        }
        else{
          writer('_', SPACENUM, outputp);
        }
      }
      else{
        writer('_', SPACENUM, outputp);
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