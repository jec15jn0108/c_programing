#include	<stdio.h>


int Max(int dt1, int dt2);

int	main(void)
{
	int	num1;
	int	num2;
	int larger;
	
	printf("数値1入力-->");
	scanf("%d", &num1);
	printf("数値2入力-->");
	scanf("%d", &num2);
	
	larger = Max(num1, num2);
	
	printf("\n大きい値:%d\n", larger);
	
	return 0;
}


int Max(int dt1, int dt2)
{
	int max;
	
	if(dt1 > dt2){
		max = dt1;
	}
	else{
		max = dt2;
	}
	
	return max;
}