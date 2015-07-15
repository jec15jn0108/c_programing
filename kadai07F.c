#include <stdio.h>

int main(void)
{
	int	i, indat, cnt[5] = {0, 0, 0, 0, 0};
	
	printf("®”“ü—Í-->");
	
	while(scanf("%d", &indat) != EOF)
	{
		cnt[indat / 10]++;
		
		printf("®”“ü—Í-->");
		
	}
	
	printf("\n–––Œ‹‰Ê–––\n");
	
	for(i = 0; i < 5; i++)
	{
		printf("”z—ñ[%d]:%dŒ\n",i,cnt[i]);
	}
	
	
	return 0;

}
