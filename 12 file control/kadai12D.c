#include	<stdio.h>
#include	<string.h>

/*15jn0108 Onogaki Kaichi*/

#define SIZE 100

void write(FILE *output);

int main(void)
{
	FILE *output;
	
	output = fopen("./kadai12 files/kadai12D.txt", "w");
	
	if(output != NULL){
		write(output);
		fclose(output);
	}
	else
	{
		printf("Failed open file.\n");
	}
	
	return 0;
}

void write(FILE *output)
{
	char name[SIZE];
	
	printf("名前入力(終了はEND)-->");
	scanf("%s", name);
	while(strcmp(name, "END")){
		fputs(name, output);
		fputc('\n', output);
		printf("名前入力(終了はEND)-->");
		scanf("%s", name);
	}
}