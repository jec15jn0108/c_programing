#include <stdio.h>

/* 15jn0108 Onogaki kaichi*/

int main(void)
{
	char moji[20];
	int i;
	
	printf("•¶š—ñ“ü—Í-->");
	scanf("%s",moji);
	
	for( i = 0; moji[i] != '\0'; i++);
	
	printf("\n•¶š”:%d\n",i);
	
	return 0;

}
