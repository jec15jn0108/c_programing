#include <stdio.h>

int main(void)
{
	int	num	;
	int	i	;
	
	for( i = 0; i < 5; i++ )
	{
		printf("整数入力-->");
		scanf("%d",&num);
		
		printf("結果:%d\n",num);
	}
	
	return 0;

}
