#include	<stdio.h>

double Average(int *p, int cnt);

int	main(void)
{
	int indat[1000];
	int cnt;
	double ave;
	
	cnt = 0;
	printf("®”[%d]-->", cnt);
	scanf("%d", &indat[cnt]);
	while(indat[cnt] > -1){
		cnt++;
		printf("®”[%d]-->", cnt);
		scanf("%d", &indat[cnt]);
	}
	
	ave = Average(indat, cnt);
	
	if(cnt){
		printf("•½‹Ï:%.1f\n", ave);
	} else{
		printf("ƒf[ƒ^–³‚µ\n");
	}
	
	return 0;
}

///////////////

double Average(int *p, int cnt)
{
	int sum;
	int i;
	double ave;
	
	sum = 0;
	for(i = 0; i < cnt; i++){
		sum += *(p + i);
	}
	
	if(cnt){
		ave = (double)sum / cnt;
		return ave;
	} else{
		return 0;
	}
	
}
