#include <stdio.h>

/* 15jn0108 Onogaki kaichi*/

int main(void)
{
	char moji[30];
	char serch, replace;
	int  i = 0;
	
	printf("文字列入力-->");
	scanf("%s",moji);
	fflush(stdin);
	printf("検索文字-->");
	scanf("%c",&serch);
	fflush(stdin);
	printf("置換文字-->");
	scanf("%c",&replace);
	
	while( moji[i] != '\0')
	{
		if( moji[i] == serch )
		{
			moji[i] = replace;
		}
		
		i++;
	}
	
	printf("結果文字列:%s",moji);
	
	
	return 0;

}
