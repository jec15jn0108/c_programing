#include <stdio.h>
#include <ctype.h>

/* 15jn0108 Onogaki kaichi*/

int main(void)
{
	char str[20];
	int cnt = 0;
	int i;
	
	printf("•¶š—ñ“ü—Í-->");
	scanf("%s",str);
	
	i = 0;
	while(str[i] != '\0')
	{
		if(isdigit(str[i]) != 0)
		{
			cnt++;
		}
		i++;
	}
	
	printf("\n”š:%d\n",cnt);
	printf("‚»‚Ì‘¼:%d\n",i - cnt);
	
	return 0;

}
