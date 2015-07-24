#include	<stdio.h>

/*15jn0108 Onogaki Kaichi*/

int main(void)
{
	int num_tmp;
	char str_tmp[100];
	int i;
	
	FILE *txt_p;
	
	txt_p = fopen("./kadai12 files/kadai12A.txt", "w");
	if(txt_p != NULL)
	{
		for( i = 0; i < 2; i++)
		{
			printf("整数データ-->");
			scanf("%d", &num_tmp);
			printf("文字列データ-->");
			scanf("%s", str_tmp);
			
			fprintf(txt_p, "%d %s\n", num_tmp, str_tmp);
		}
	}
	
	fclose(txt_p);
	
	return 0;
}