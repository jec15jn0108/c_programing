#include <stdio.h>

int main(void)
{
	char str ;
	
	printf("•¶š“ü—Í-->");
	scanf("%c",&str);
	
	printf("•ÏŠ·Œã:");
	
	if (str >= 'A' && str <='Z')
	{
		str+= 32;
		printf("%c\n",str);
	}
	else if (str >= 'a' && str <= 'z')
	{
		str-= 32;
		printf("%c\n",str);
	}
	else
	{
		printf("•ÏŠ·‚Å‚«‚È‚¢\n");
	}
	return 0;

}
