#include	<stdio.h>

/*15jn0108 Onogaki Kaichi*/

void write(FILE output);

int main(void)
{
	FILE *txt_p;
	
	txt_p = fopen("./kadai12 files/kadai12A.txt", "w");
	if(txt_p != NULL)
	{
		write(txt_p);
		fclose(txt_p);
	}
	else
	{
		printf("Failed open file.\n");
	}
	
	return 0;
}

void write(FILE *output)
{
	int num_tmp;
	char str_tmp[100];
	int i;
	
	for( i = 0; i < 2; i++)
	{
		printf("�����f�[�^-->");
		scanf("%d", &num_tmp);
		printf("������f�[�^-->");
		scanf("%s", str_tmp);
		
		fprintf(output, "%d %s\n", num_tmp, str_tmp);
	}
	
}