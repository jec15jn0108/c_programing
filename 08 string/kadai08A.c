#include <stdio.h>

/* 15jn0108 Onogaki kaichi*/

int main(void)
{
	char moji[20];
	int i;
	
	printf("���������-->");
	scanf("%s",moji);
	
	for( i = 0; moji[i] != '\0'; i++);
	
	printf("\n������:%d\n",i);
	
	return 0;

}
