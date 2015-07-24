#include	<stdio.h>
#include	<ctype.h>

int main(void)
{
	int		array[8];
	int		*pa;
	int		min;
	int		work;
	int 	i, j;
	
	pa = array;
	
	for(i = 0; i < 8; i++){
		printf("®”[%d]-->", i);
		scanf("%d", pa + i);
	}
	printf("\n––ƒ\[ƒgŒã––\n");
	
	for(i = 0; i < (8 - 1); i++){
		 min = i;
		 
		 for(j = (i + 1); j < 8; j++){
		 	
			if(*(pa + j) < *(pa + min)){
				min = j;
			}
		 }
		 
		 if(min != i){
		 	work = *(pa + i);
			*(pa + i) = *(pa + min);
			*(pa + min) = work;
		 }
	}
	
	for(i = 0; i < 8; i++){
		printf("Œ‹‰Ê[%d]:%d\n", i, *(pa + i));
	}

	return 0;
}