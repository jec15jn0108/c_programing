#include <stdio.h>
#include <string.h>

/* 15jn0108 Onogaki kaichi*/

int main(void)
{
	char m1[20];
	char m2[20];
	
	printf("������1����-->");
	scanf("%s", m1);
	fflush(stdin);
	printf("������2����-->");
	scanf("%s", m2);
	
	printf("����:");
	
	if( strcmp(m1, m2) == 0)
	{
		printf("2�̕�����͓����ł�\n");
	}
	else
	{
		printf("2�̕�����͈Ⴂ�܂�\n");
	}
	
	
	return 0;

}
