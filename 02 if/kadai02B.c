#include <stdio.h>

int main(void)
{
	int		a, b ;
	
	printf("a����̓��_-->");
	scanf("%d",&a);
	printf("b����̓��_-->");
	scanf("%d",&b);
	
	if(a > b)
	{
		printf("a����̏���\n");
	}
	else if(a < b)
	{
		printf("b����̏���\n");
	}
	else
	{
		printf("��������\n");
	}
	
	return 0;

}
