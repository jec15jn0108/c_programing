#include <stdio.h>

int main(void)
{
	int 	point;
	
	printf("�_������-->");
	scanf("%d",&point);
	
	if( point < 0 )
	{
		printf("�_���̓��̓G���[(0����)�ł�\n");
	}
	else if( point > 100 )
	{
		printf("�_���̓��̓G���[(100�𒴂���)�ł�\n");
	}
	else if( point >= 60 )
	{
		printf("���i�ł�\n");
	}
	else
	{
		printf("�s���i�ł�\n");
	}
	
	return 0;

}
