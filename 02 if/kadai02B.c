#include <stdio.h>

int main(void)
{
	int		a, b ;
	
	printf("a‚³‚ñ‚Ì“¾“_-->");
	scanf("%d",&a);
	printf("b‚³‚ñ‚Ì“¾“_-->");
	scanf("%d",&b);
	
	if(a > b)
	{
		printf("a‚³‚ñ‚ÌŸ‚¿\n");
	}
	else if(a < b)
	{
		printf("b‚³‚ñ‚ÌŸ‚¿\n");
	}
	else
	{
		printf("ˆø‚«•ª‚¯\n");
	}
	
	return 0;

}
