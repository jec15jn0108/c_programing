#include <stdio.h>

/* 15jn0108 Onogaki kaichi*/

int main(void)
{
	char moji[20];
	int i;
	
	printf("文字列入力-->");
	scanf("%s",moji);
	
	for( i = 0; moji[i] != '\0'; i++);
	
	printf("\n文字数:%d\n",i);
	
	return 0;

}
