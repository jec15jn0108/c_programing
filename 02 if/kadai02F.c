#include <stdio.h>

int main(void)
{
	int year ;
	printf("�N����-->");
	scanf("%d",&year);
	
	printf("����:");
	
	if( year % 4 != 0 )
	{
		printf("���N\n");
	}
	else if ( year % 100 != 0 )
	{
		printf("�[�N\n");
	}
	else if ( year % 400 != 0 )
	{
		printf("���N\n");
	}
	else
	{
		printf("�[�N\n");
	}
	
	return 0;

}
