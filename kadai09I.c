#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define DEBUG


/* 15jn0108 Onogaki kaichi*/

int main(void)
{
	int ans[4];
	int num[4];
	time_t t;
	int i;
	int j;
	int hitCnt;
	int blowCnt;
	int cnt;
	
	t = time(NULL);
	srand(t);
		
	for(i = 0; i < 4; ){
		ans[i] = rand() % 10;
		
		for (j = 0; j < i && ans[j] != ans[i]; j++) {
			;/* DoNothing!! */
		}
		
		if( i == j ){
			i++;
		}
		
	}
	
	#ifdef DEBUG
		for(i = 0; i < 4; i++){
			printf("%d",ans[i]);
		}
		printf("\n");
	#endif
	
	cnt = 1;
	hitCnt = 0;
	while( hitCnt < 4){
		hitCnt = 0;
		blowCnt = 0;
		
		printf("4���̐��������(%d���)-->", cnt498);
		scanf("%1d%1d%1d%1d",&num[0],&num[1],&num[2],&num[3]);
		
		for(i = 0; i < 4; i++){
			if( num[i] == ans[i] ){
				hitCnt++;
			} else{
				for(j = 0; j < 4; j++){
					if( num[i] == ans[j] && i != j){
						blowCnt++;
					}
				}
			}
		}
		
		if(hitCnt < 4){
			printf("�q�b�g:%d	�u���E:%d\n\n",hitCnt,blowCnt);
		}
		
		cnt++;
	}
	
	printf("* * �吳�� * *");
	
	return 0;	
}
