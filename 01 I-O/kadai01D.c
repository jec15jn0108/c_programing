#include <stdio.h>

int main(void)
{
	char 	initial;
	double	hight;
	int		date;
	
	printf("���Ȃ��̃C�j�V����-->");
	scanf("%c",&initial);
	printf("���Ȃ��̐g��-->");
	scanf("%lf",&hight);
	printf("�����̓��t-->");
	scanf("%d",&date);
	
	printf("�C�j�V����:%c\n",initial);
	printf("�g��:%fcm\n",hight);
	printf("�����̓��t:%d��\n",date);
	
	return 0;

}
