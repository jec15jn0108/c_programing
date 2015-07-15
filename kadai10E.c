#include	<stdio.h>
#include	<ctype.h>

int main(void)
{
	int		array[10], goukei, i, cnt;
	int		*pa;
	double	heikin;
	
	pa = array;
	goukei = 0;
	for(i = 0; i < 10; i++){
		printf("®”“ü—Í[%d]-->", i);
		scanf("%d", pa + i);
		goukei += *(pa + i);
	}
	
	heikin = (double)goukei / i;
	
	printf("\n•½‹Ï:%.1f\n", heikin);

	cnt = 0;
	for(i = 0; i < 10; i++){
		if(*(pa + i) < heikin){
			printf("[%d]:%d\n", i, *(pa + i));
			cnt++;
		}
	}
	
	printf("Œ”:%d", cnt);
	
	
	return 0;
}