#include	<stdio.h>

/*15jn0108 Onogaki Kaichi*/

void read(FILE *input);

int main(void)
{
	FILE *input;
	
	input = fopen("./kadai12 files/kadai12A.txt","r");
	if(input != NULL)
	{
		read(input);
		fclose(input);
	}
	else
	{
		printf("Failed open File.");
	}
	
	return 0;
}

void read(FILE *input)
{
	int in_num;
	char in_str[50];
	int i;
	
	printf("®” •¶š—ñ\n");
	
	for(i = 0; i < 2; i++)
	{
		fscanf(input, "%d %s", &in_num, in_str);
		printf("%4d %s\n", in_num, in_str);
	}
}