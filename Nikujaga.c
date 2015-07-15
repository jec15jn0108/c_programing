#include	<stdio.h>
#include	<windows.h>

#define	BEET 470

void enter(void)
{
	printf("\n");
}


int	main(void)
{
	int i;
	
	i = 1;
	while(1){
		printf("Ç…Ç≠Ç∂Ç·Ç™");
		if(i % 8 == 0){
			printf("ÉxÅ[ÉRÉì");
			if(i % 32 == 0){
				printf("Ç∏ÇÒÇæ");
				i = 0;
			}
			enter();
		}
		else if( i % 4 == 0){
			enter();
		}
		Sleep(BEET);
		i++;
	}
	
}