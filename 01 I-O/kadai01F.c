#include <stdio.h>

int main(void)
{
	int 	kamoku1,kamoku2,sum;
	double	ave;
	printf("�ȖڂP�̓_��-->");
	scanf("%d",&kamoku1);
	printf("�ȖڂQ�_��-->");
	scanf("%d",&kamoku2);
	
	sum = kamoku1 + kamoku2 ;
	ave = (double)sum / 2 ;
	
	printf("�Q�Ȗڂ̍��v:%d\n",sum);
	printf("�Q�Ȗڂ̕���:%f\n",ave);
	
	return 0;

}
