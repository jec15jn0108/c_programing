#include <stdio.h>
#include <string.h>

/* 15jn0108 Onogaki kaichi*/

int main(void)
{
	char str[50];
	char serch[20];
	int i;
	
	printf("文字列入力-->");
	scanf("%s",str);
	fflush(stdin);
	printf("検索文字列入力-->");
	scanf("%s",serch);	
	
	i = 0;
	while(str[i] != '\0')
	{
		if(strncmp(&str[i], serch, strlen(serch)) == 0)
		{
			printf("一致場所:%d\n",i);
		}
		i++;
	}
	
	
	return 0;

}
