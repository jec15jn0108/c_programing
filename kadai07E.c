#include <stdio.h>

int main(void)
{
	int	i, indat, cnt[6] = {0, 0, 0, 0, 0, 0};
	
	do
	{
		printf("®”“ü—Í-->");
		scanf("%d",&indat);
		
		cnt[indat - 1]++;
		
	}while(indat >= 1 && indat <= 6);
	
	printf("\n");
	
	for(i = 0; i < 6; i++)
	{
		printf("%d:%d‰ñ\n",i + 1,cnt[i]);
	}
	
	
	return 0;

}
