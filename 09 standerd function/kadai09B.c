#include <stdio.h>
#include <string.h>

/* 15jn0108 Onogaki kaichi*/

int main(void)
{
	char m1[20];
	char m2[20];
	
	printf("文字列1入力-->");
	scanf("%s", m1);
	fflush(stdin);
	printf("文字列2入力-->");
	scanf("%s", m2);
	
	printf("結果:");
	
	if( strcmp(m1, m2) == 0)
	{
		printf("2つの文字列は同じです\n");
	}
	else
	{
		printf("2つの文字列は違います\n");
	}
	
	
	return 0;

}
