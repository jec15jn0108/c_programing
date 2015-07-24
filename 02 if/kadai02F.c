#include <stdio.h>

int main(void)
{
	int year ;
	printf("年入力-->");
	scanf("%d",&year);
	
	printf("結果:");
	
	if( year % 4 != 0 )
	{
		printf("平年\n");
	}
	else if ( year % 100 != 0 )
	{
		printf("閏年\n");
	}
	else if ( year % 400 != 0 )
	{
		printf("平年\n");
	}
	else
	{
		printf("閏年\n");
	}
	
	return 0;

}
