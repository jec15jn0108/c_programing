#include <stdio.h>

int main(void)
{
	char str ;
	
	printf("��������-->");
	scanf("%c",&str);
	
	printf("�ϊ���:");
	
	if (str >= 'A' && str <='Z')
	{
		str+= 32;
		printf("%c\n",str);
	}
	else if (str >= 'a' && str <= 'z')
	{
		str-= 32;
		printf("%c\n",str);
	}
	else
	{
		printf("�ϊ��ł��Ȃ�\n");
	}
	return 0;

}
