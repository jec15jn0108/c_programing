#include <stdio.h>
#include <ctype.h>

/* 15jn0108 Onogaki kaichi*/

int main(void)
{
	char str[20];
	char alpha[20];
	char other[20];
	int i, j, k;
	
	printf("���������-->");
	scanf("%s",str);
	
	i = j = k = 0;
	while(str[i] != '\0')
	{
		if(isalpha(str[i]) != 0)
		{
			alpha[j++] = str[i];
		}
		else
		{
			other[k++] = str[i];
		}
		i++;
	}
	alpha[j] = '\0';
	other[k] = '\0';
	
	printf("\n�p��:%s\n",alpha);
	printf("���̑�:%s\n",other);
	
	return 0;

}
