#include <stdio.h>

/* 15jn0108 Onogaki kaichi*/

int main(void)
{
	char moji[30];
	char serch, replace;
	int  i = 0;
	
	printf("���������-->");
	scanf("%s",moji);
	fflush(stdin);
	printf("��������-->");
	scanf("%c",&serch);
	fflush(stdin);
	printf("�u������-->");
	scanf("%c",&replace);
	
	while( moji[i] != '\0')
	{
		if( moji[i] == serch )
		{
			moji[i] = replace;
		}
		
		i++;
	}
	
	printf("���ʕ�����:%s",moji);
	
	
	return 0;

}
