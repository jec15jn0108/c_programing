#include	<stdio.h>

/*15jn0108 Onogaki Kaichi*/

int main(void)
{
	int in_num;
	char in_str[50];
	int i;
	
	FILE *kadai12A_txt;
	
	kadai12A_txt = fopen("./kadai12 files/kadai12A.txt","r");
	if(kadai12A_txt != NULL)
	{
		printf("®” •¶š—ñ\n");
	
		for(i = 0; i < 2; i++)
		{
			fscanf(kadai12A_txt, "%d %s", &in_num, in_str);
			printf("%4d %s\n", in_num, in_str);
		}
	}
	
	fclose(kadai12A_txt);
	
	return 0;
}