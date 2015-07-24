#include	<stdio.h>

int MyLen( char *ss);

int	main(void)
{
	char moji[20];
	int charcnt;
	
	printf("•¶š—ñ“ü—Í-->");
	scanf("%s", moji);
	
	charcnt = MyLen(moji);
	
	printf("•¶š”:%d", charcnt);
	
	return 0;
}

int MyLen( char *ss)
{
	int i;
	for(i = 0; *(ss + i) != '\0'; i++);
	return i;
}