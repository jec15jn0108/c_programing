#include	<stdio.h>

void SortDisp(int dt1, int dt2);

int	main(void)
{
	int	num1;
	int	num2;
	int larger;
	
	printf("���l1����-->");
	scanf("%d", &num1);
	printf("���l2����-->");
	scanf("%d", &num2);
	
	SortDisp(num1, num2);
	
	return 0;
}

void SortDisp(int dt1, int dt2)
{
	int *minp = &dt1;
	int *notMinp = &dt2;
	
	if(dt1 > dt2){
		minp = &dt2;
		notMinp = &dt1;
	}
	printf("���l1:%d\n",*minp);
	printf("���l2:%d\n",*notMinp);
	return;
}