#include <stdio.h>
#include <string.h>

/* 15jn0108 Onogaki kaichi*/

int main(void)
{
	char m1[50];
	char m2[50];
	int i;
	
	printf("•¶Žš—ñ(m1)-->");
	scanf("%s",m1);
	fflush(stdin);
	printf("íœ•¶Žš—ñ(m2)-->");
	scanf("%s",m2);
	
	i = 0;
	while(m1[i] != '\0')
	{
		if(strncmp(&m1[i], m2, strlen(m2)) == 0)
		{
			strcpy(&m1[i], &m1[i + strlen(m2)]);
		}
		else
		{
			i++;
		}
	}
	
	printf("Œ‹‰Ê•¶Žš—ñ(m1):%s",m1);
	
	
	
	return 0;

}
