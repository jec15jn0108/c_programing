#include <stdio.h>
#include <ctype.h>

/* 15jn0108 Onogaki kaichi*/

int main(void)
{
	char str[20];
	int cnt = 0;
	int i;
	
	printf("文字列入力-->");
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
	
	printf("\n数字:%d\n",cnt);
	printf("その他:%d\n",i - cnt);
	
	return 0;

}
