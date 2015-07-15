#include <stdio.h>
#include <string.h>

/* 15jn0108 Onogaki kaichi*/

int main(void)
{
	char m1[1000];
	char m2[1000];
	char tmp;
	int i;
	int cnt;
	int m2idx;
	double packed;
	
	printf("“ü—Í•¶š—ñ(m1)-->");
	scanf("%s",m1);
	fflush(stdin);
	
	i = 0;
	m2idx = 0;
	while(m1[i] != '\0'){
		tmp = m1[i];
		cnt = 0;
		while(m1[i] == tmp){
			i++;
			cnt++;
		}
		
		if(cnt > 1){
			sprintf(&m2[m2idx],"@%d",cnt);
			while(cnt >= 10){
				m2idx++;
				cnt /= 10;
			}
			m2idx += 2;
		}
		sprintf(&m2[m2idx],"%c",tmp);
		m2idx++;
	}
	m2[m2idx] = '\0';
	
	printf("ˆ³k•¶š—ñ(m2):%s\n",m2);
	
	packed = (double)strlen(m2) / strlen(m1) * 100;
	
	printf("ˆ³k”ä:%.1f%\n",packed);
	
	
	
	return 0;

}
