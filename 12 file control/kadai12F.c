#include	<stdio.h>
#include	<string.h>

/*15jn0108 Onogaki Kaichi*/

#define SIZE 		256
#define LOCATION 	"./kadai12 files/"
#define FIELD_SIZE 	3

int read_field(FILE *input);


int main(int argc, char *argv[])
{
	FILE *input;
	char file_name[SIZE];
	char location[SIZE] = LOCATION;	
	int flag;
	
	sprintf(file_name, "%s", strcat(location,argv[1]));
	if((input = fopen(file_name, "rb")) == NULL){
		//Failed open input file
		printf("ERROR:Failed open input file!!");
	}
	else{
		//Success open all file
		flag = read_field(input);
		if(flag == 0){
			printf("ERROR:Failed read your field!!");
		}
		fclose(input);
	}
	
	return 0;
}

int read_field(FILE *input)
{
	char buf[SIZE];
	int field;
	int score; 
	int cnt;
	int sum;
	int i;
	int ret = 0;
	
	printf("フィールド入力-->");
	scanf("%d", &field);
	if(field > 0 && field <= FIELD_SIZE){
		field--;
		printf("データ:");
		cnt = 0;
		sum = 0;
		while(fscanf(input, "%s", buf) != EOF){
			for(i = 0; i < FIELD_SIZE; i++){
				fscanf(input, "%d ", &score);
				if(i == field){
					printf("%3d ",score);
					sum += score;
					cnt++;
				}
			}
		}
		printf("\n平均:%.1f\n", (double)sum / cnt);
		ret = 1;
	}
	
	return ret;
}