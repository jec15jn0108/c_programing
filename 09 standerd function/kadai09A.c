#include <stdio.h>
#include <string.h>

/* 15jn0108 Onogaki kaichi*/

int main(void)
{
	char m1[20];
	char m2[10];
	
	printf("•Ï”m1“ü—Í-->");
	scanf("%s", m1);
	fflush(stdin);
	printf("•Ï”m2“ü—Í-->");
	scanf("%s", m2);
	
	strcat(m1, m2);
	
	printf("Œ‹‰Êm1:%s\n",m1);
	
	return 0;

}
