#include <stdio.h>

int main(void)
{
	int small, large;
	int i;
	
	printf("����1(��)����-->");
	scanf("%d",&small);
	
	printf("����2(��)����-->");
	scanf("%d",&large);	
	
	printf("����:");
	
	for(i = small; i <= large; i++ )
	{
		printf("%d ",i);
	}
	
	printf("\n");
	
	return 0;

}
