#include <stdio.h>
#include <string.h>

/* 15jn0108 Onogaki kaichi*/

int main(void)
{
	char m1[20];
	char m2[10];
	
	printf("�ϐ�m1����-->");
	scanf("%s", m1);
	fflush(stdin);
	printf("�ϐ�m2����-->");
	scanf("%s", m2);
	
	strcat(m1, m2);
	
	printf("����m1:%s\n",m1);
	
	return 0;

}
