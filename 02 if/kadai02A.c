#include <stdio.h>

int main(void)
{
	int		a, b, max;
	
	printf("�ϐ�a�̓���-->");
	scanf("%d",&a);
	printf("�ϐ�b�̓���-->");
	scanf("%d",&b);
	
	if(a > b)
	{
		max = a;
	}
	else
	{
		max = b;
	}
	
	printf("max�̒l:%d\n",max);
	
	return 0;

}
