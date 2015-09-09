#include	<stdio.h>
#include	<stdlib.h>
#include	<ctype.h>

/*15jn0108 Onogaki Kaichi*/

#define SIZE 		1024
#define SUBJECT		2
#define FILE_NAME 	"./kadai12 files/kadai12h.dat"

int aggregate(FILE *input);
void write(char *st_no, char *st_name, int score[], int ave);

int main()
{	
	FILE	*input;
	
	if( (input = fopen(FILE_NAME, "rb")) != NULL )
	{
		aggregate(input);
	}
	else
	{
		printf("Failed open file!\n");
	}
	
	return 0;
}

int aggregate(FILE *input)
{
	char 	header[] = "学籍番号　氏名　　　　科目１　科目２　　平均\n";
	char	class_tmp;
	char	class_num;
	char	student_no[SIZE];
	char	student_name[SIZE];
	int		score[SUBJECT];
	int		sum;
	int		ave;
	double	class_ave[SUBJECT];
	int		i;
	
	printf(header);
	
	while( fscanf(input, "%c ", &class_num) != EOF )
	{
		class_tmp = class_num;
		while(class_num == class_tmp)
		{
			sum = 0;
			fscanf(input, "%s ", student_no);
			fscanf(input, "%s ", student_name);
			for(i = 0; i < SUBJECT; i++){
				fscanf(input, "%d ", &score[i]);
				sum += score[i];
			}
			ave = sum / SUBJECT;
			
			write(student_no, student_name, score, ave);
			
			if(fscanf(input, "%c ", &class_num) ==EOF)
			{
				break;
			}
		}
	}
	
	return;
}

void write(char *st_no, char *st_name, int score[], int ave)
{
	int i;
	
	printf("%6s    %10s", st_no, st_name);
	
	for(i = 0; i < SUBJECT; i++)
	{
		printf(" %3d", score[i]);
	}
	
	printf("   %3d\n", ave);
	
}
	