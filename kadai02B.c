#include <stdio.h>

int main(void)
{
	int		a, b ;
	
	printf("aさんの得点-->");
	scanf("%d",&a);
	printf("bさんの得点-->");
	scanf("%d",&b);
	
	if(a > b)
	{
		printf("aさんの勝ち\n");
	}
	else if(a < b)
	{
		printf("bさんの勝ち\n");
	}
	else
	{
		printf("引き分け\n");
	}
	
	return 0;

}
