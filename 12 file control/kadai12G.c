#include	<stdio.h>
#include	<stdlib.h>
#include	<ctype.h>

/*15jn0108 Onogaki Kaichi*/

#define SIZE 		1024
#define FILE_NAME 	"./kadai12 files/kadai12G.dat"

void decompression(FILE *output);
int input_str(char str[]);
void write(FILE *output, char instr[]);

int main()
{
	FILE *output;
	
	if((output = fopen(FILE_NAME, "wb")) == NULL)
	{
		printf("Failed open file.\n");
	}
	else
	{
		decompression(output);
		fclose(output);
	}
	
	return 0;
}

void decompression(FILE *output)
{
	char instr[SIZE];
	
	while(input_str(instr) != EOF)
	{
		write(output, instr);
	}
}

int input_str(char str[])
{
	int ret;
	
	printf("•¶Žš—ñ“ü—Í-->");
	ret = scanf("%s", str);
	return	ret;
}

void write(FILE *output, char str[])
{
	int num;
	int i;
	int j;
	
	i = 0;
	while(str[i] != '\0')
	{
		num = 1;
		if(isdigit(str[i]))
		{
			num = atoi(&str[i]);
			while(isdigit(str[i]))
			{
				i++;
			}
		}
		
		for(j = 0; j < num; j++)
		{
			fprintf(output, "%c", str[i]);
		}
		i++;
		
	}
	fprintf(output, "\n");
}