#include <stdio.h>

int main(void)
{
	int		num;
	int		max = 0;

	printf("��������-->");
	scanf("%d",&num);
	
	while(num > -1)
	{
		
		if(num > max)
		{
			max = num;
		}
		
		printf("��������-->");
		scanf("%d",&num);
		
	}
	
	printf("�ő�l:%d\n",max);
	
	return 0;

}
