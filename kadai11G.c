#include	<stdio.h>

/*15jn0108 Onogaki Kaichi*/

int Power(int x, int y);

int	main(void)
{
	int num1;
	int num2;
	int Multipli;
	
	printf("®”“ü—Í-->");
	scanf("%d",&num1);
	printf("®”“ü—Í-->");
	scanf("%d",&num2);
	
	Multipli = Power(num1, num2);
	
	printf("’l:%d\n", Multipli);
	
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