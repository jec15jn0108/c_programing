#include <stdio.h>
#include <string.h>

/* 15jn0108 Onogaki kaichi*/

int main(void)
{
	char str[50];
	char serch[20];
	int i;
	
	printf("���������-->");
	scanf("%s",str);
	fflush(stdin);
	printf("�������������-->");
	scanf("%s",serch);	
	
	i = 0;
	while(str[i] != '\0')
	{
		if(strncmp(&str[i], serch, strlen(serch)) == 0)
		{
			printf("��v�ꏊ:%d\n",i);
		}
		i++;
	}
	
	
	return 0;

}
