#include	<stdio.h>

/*15jn0108 Onogaki Kaichi*/

#define SIZE 100

int main(void)
{
	FILE *input;
	FILE *output;
	char no[SIZE];
	char name[SIZE];
	int  score;
	char check;
	
	if((input = fopen("./kadai12 files/Kadai12Eln.dat", "rb")) == NULL){
		//Failed open input file
	}
	else if((output = fopen("./kadai12 files/Kadai12Out.dat", "wb")) == NULL){
		//Failed open output file
		fclose(input);
	}
	else{
		//Success open all file
		while( fscanf(input, "%s %s %d %c", no, name, &score, &check) != EOF ){
			if(score < 60 || check == 'x'){
				fprintf(output, "%s %s %d %c\n", no, name, score, check);
			}
		}
		fclose(input);
		fclose(output);
	}
	
	return 0;
}