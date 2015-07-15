#include <stdio.h>

int main(void)
{
	int 	point;
	
	printf("点数入力-->");
	scanf("%d",&point);
	
	if( point < 0 )
	{
		printf("点数の入力エラー(0未満)です\n");
	}
	else if( point > 100 )
	{
		printf("点数の入力エラー(100を超える)です\n");
	}
	else if( point >= 60 )
	{
		printf("合格です\n");
	}
	else
	{
		printf("不合格です\n");
	}
	
	return 0;

}
