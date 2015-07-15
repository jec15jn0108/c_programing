#include	<stdio.h>
#include	<string.h>

/*15jn0108 Onogaki Kaichi*/

int sub1(void);
int sub2(void);

int main(void)
{
	int indat;
	int eveCnt;
	int oddCnt;
	
	printf("数値入力-->");
	scanf("%d",&indat);
	while(indat > -1)
	{
		if(indat % 2 == 0)
		{
			eveCnt = sub2();
		}
		else
		{
			oddCnt = sub1();
		}
		printf("数値入力-->");
		scanf("%d",&indat);
	}
	
	printf("\nsub1:%d回(奇数)\n", oddCnt);
	printf("sub2:%d回(偶数)\n", eveCnt);
	return 0;
}

////////////////////////////
int sub1(void)
{
	static int oddCnt = 0;
	return ++oddCnt;
}

int sub2(void)
{
	static int eveCnt = 0;
	return ++eveCnt;
}
