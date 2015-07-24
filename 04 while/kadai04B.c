#include <stdio.h>

int main(void)
{
	int		num;
	int		max = 0;

	printf("®”“ü—Í-->");
	scanf("%d",&num);
	
	while(num > -1)
	{
		
		if(num > max)
		{
			max = num;
		}
		
		printf("®”“ü—Í-->");
		scanf("%d",&num);
		
	}
	
	printf("Å‘å’l:%d\n",max);
	
	return 0;

}
