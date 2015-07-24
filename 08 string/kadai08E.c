#include <stdio.h>

/* 15jn0108 Onogaki kaichi*/

int main(void)
{
	
	char moji[] = "BCDXEFGHIJKLMNOWPQRSZTUVAY";
	
	char startMoji;
	char endMoji;
	int start;
	int i;
	
	printf("moji:%s\n",moji);
	printf("開始位置-->");
	scanf("%c",&startMoji);
	fflush(stdin);
	printf("終了位置-->");
	scanf("%c",&endMoji);
	
	printf("\n表示:");
	
	for(start = 0; moji[start] != startMoji; start++);
	
	for( i = start; moji[i] != endMoji; i++)
	{
		if( moji[i] == '\0' )
		{
			i = 0;
		}
		
		printf("%c",moji[i]);
		
	}
	
	printf("%c\n",moji[i]);
	
	
	return 0;

}
