#include <stdio.h>

int main(void)
{
	char 	initial;
	double	hight;
	int		date;
	
	printf("あなたのイニシャル-->");
	scanf("%c",&initial);
	printf("あなたの身長-->");
	scanf("%lf",&hight);
	printf("今日の日付-->");
	scanf("%d",&date);
	
	printf("イニシャル:%c\n",initial);
	printf("身長:%fcm\n",hight);
	printf("今日の日付:%d日\n",date);
	
	return 0;

}
