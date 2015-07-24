#include <stdio.h>

int main(void)
{
	int 	kamoku1,kamoku2,sum;
	double	ave;
	printf("‰È–Ú‚P‚Ì“_”-->");
	scanf("%d",&kamoku1);
	printf("‰È–Ú‚Q“_”-->");
	scanf("%d",&kamoku2);
	
	sum = kamoku1 + kamoku2 ;
	ave = (double)sum / 2 ;
	
	printf("‚Q‰È–Ú‚Ì‡Œv:%d\n",sum);
	printf("‚Q‰È–Ú‚Ì•½‹Ï:%f\n",ave);
	
	return 0;

}
