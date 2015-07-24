#include <stdio.h>

int main(void)
{
	int dat, rtn;
	
	printf("データ入力-->");
	scanf("%d", &dat);
	
	rtn = (dat >= 60) ? 1 : 0 ;
	
	if( rtn )
	{
		printf("合格\n");
	}
	else
	{
		printf("不合格\n");
	}
	
	
	return 0;

}
