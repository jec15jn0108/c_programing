#include <stdio.h>

int main(void)
{
	int small, large;
	int i;
	
	printf("整数1(小)入力-->");
	scanf("%d",&small);
	
	printf("整数2(大)入力-->");
	scanf("%d",&large);	
	
	printf("結果:");
	
	for(i = small; i <= large; i++ )
	{
		printf("%d ",i);
	}
	
	printf("\n");
	
	return 0;

}
