#include <stdio.h>
#include <string.h>

/* 15jn0108 Onogaki kaichi*/

int main(void)
{
	char str[50];
	char serch[20];
	int i;
	
	printf("•¶š—ñ“ü—Í-->");
	scanf("%s",str);
	fflush(stdin);
	printf("ŒŸõ•¶š—ñ“ü—Í-->");
	scanf("%s",serch);	
	
	i = 0;
	while(str[i] != '\0')
	{
		if(strncmp(&str[i], serch, strlen(serch)) == 0)
		{
			printf("ˆê’vêŠ:%d\n",i);
		}
		i++;
	}
	
	
	return 0;

}
