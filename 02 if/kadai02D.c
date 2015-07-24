#include <stdio.h>

int main(void)
{
	int mon ;
	printf("ŒŽ‚ð“ü—Í-->");
	scanf("%d",&mon);
	
	printf("Œ‹‰Ê:");
	
	if (mon < 1 || mon > 12)
	{
		printf("ŒŽ‚Ì“ü—ÍƒGƒ‰[\n");
	}
	else if (mon >= 3 && mon <= 5)
	{
		printf("‹Gß‚Ít\n");
	}
	else if (mon >= 6 && mon <= 8)
	{
		printf("‹Gß‚Í‰Ä\n");
	}
	else if (mon >= 9 && mon <= 11)
	{
		printf("‹Gß‚ÍH\n");
	}
	else
	{
		printf("‹Gß‚Í“~\n");
	}
	
	return 0;

}
