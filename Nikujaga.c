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
		printf("にくじゃが");
		if(i % 8 == 0){
			printf("ベーコン");
			if(i % 32 == 0){
				printf("ずんだ");
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