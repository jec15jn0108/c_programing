#include <stdio.h>
#include <ctype.h>

/* 15jn0108 Onogaki kaichi*/

int main(void)
{
	char str[20];
	int cnt = 0;
	int i;
	
	printf("���������-->");
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
	
	printf("\n����:%d\n",cnt);
	printf("���̑�:%d\n",i - cnt);
	
	return 0;

}
