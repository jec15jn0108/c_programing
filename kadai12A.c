#include	<stdio.h>

/*15jn0108 Onogaki Kaichi*/

int main(void)
{
	int num_tmp;
	char str_tmp[100];
	int i;
	
	FILE *kadai_txt;
	
	fopen(kadai_txt, "w");
	
	for( i = 0; i < 2; i++)
	{
		printf("整数データ-->");
		scanf("%d", &num_tmp);
		printf("文字列データ-->");
		scanf("%s", str_tmp);
		
		fprintf(kadai_txt, "%d %s\n", num_tmp, str_tmp);
	}
	
	return 0;
}