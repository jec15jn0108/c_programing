#include	<stdio.h>

/*15jn0108 Onogaki Kaichi*/

int Power(int x, int y);

int	main(void)
{
	int num1;
	int num2;
	int Multipli;
	
	printf("整数入力-->");
	scanf("%d",&num1);
	printf("整数入力-->");
	scanf("%d",&num2);
	
	Multipli = Power(num1, num2);
	
	printf("値:%d\n", Multipli);
	
	return 0;
}
/////////////////
int Power(int x, int y)
{
	int result = 1;	
	
	if(y > 0){
		result = x * Power(x, --y);
	}
	
	return result;
}