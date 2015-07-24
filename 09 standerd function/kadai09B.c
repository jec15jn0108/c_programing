#include <stdio.h>
#include <string.h>

/* 15jn0108 Onogaki kaichi*/

int main(void)
{
	char m1[20];
	char m2[20];
	
	printf("•¶Žš—ñ1“ü—Í-->");
	scanf("%s", m1);
	fflush(stdin);
	printf("•¶Žš—ñ2“ü—Í-->");
	scanf("%s", m2);
	
	printf("Œ‹‰Ê:");
	
	if( strcmp(m1, m2) == 0)
	{
		printf("2‚Â‚Ì•¶Žš—ñ‚Í“¯‚¶‚Å‚·\n");
	}
	else
	{
		printf("2‚Â‚Ì•¶Žš—ñ‚Íˆá‚¢‚Ü‚·\n");
	}
	
	
	return 0;

}
