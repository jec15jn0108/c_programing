#include <stdio.h>

int main(void)
{
	int small, large;
	int i;
	
	printf("®”1(¬)“ü—Í-->");
	scanf("%d",&small);
	
	printf("®”2(‘å)“ü—Í-->");
	scanf("%d",&large);	
	
	printf("Œ‹‰Ê:");
	
	for(i = small; i <= large; i++ )
	{
		printf("%d ",i);
	}
	
	printf("\n");
	
	return 0;

}
