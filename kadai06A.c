#include <stdio.h>

int main(void)
{
	int num;
	
	printf("®”n‚Ì“ü—Í-->");
	scanf("%d",&num);
	
	switch(num)
	{
		case 1:
			printf("\nABC\n");
			break;
		
		case 2:
			printf("\nDEF\n");
			break;
			
		default:
			printf("\nXXX\n");
			break;
	}
	
	return 0;

}
