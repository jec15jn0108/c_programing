#include <stdio.h>

int main(void)
{
	int		a, b, max;
	
	printf("•Ï”a‚Ì“ü—Í-->");
	scanf("%d",&a);
	printf("•Ï”b‚Ì“ü—Í-->");
	scanf("%d",&b);
	
	if(a > b)
	{
		max = a;
	}
	else
	{
		max = b;
	}
	
	printf("max‚Ì’l:%d\n",max);
	
	return 0;

}
