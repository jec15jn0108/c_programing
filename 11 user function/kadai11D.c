#include	<stdio.h>

int MyLen( char *ss);

int	main(void)
{
	char moji[20];
	int charcnt;
	
	printf("文字列入力-->");
	scanf("%s", moji);
	
	charcnt = MyLen(moji);
	
	printf("文字数:%d", charcnt);
	
	return 0;
}

int MyLen( char *ss)
{
	int i;
	for(i = 0; *(ss + i) != '\0'; i++);
	return i;
}