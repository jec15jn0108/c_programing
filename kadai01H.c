#include <stdio.h>

int main(void)
{
	double	num;
	
	printf("実数入力-->");
	scanf("%lf",&num);
	
	num += 0.5;
	
	printf("四捨五入後:%d",(int)num);
	
	return 0;

}
