#include <stdio.h>

int main(void)
{
	int	i, indat, cnt[5] = {0, 0, 0, 0, 0};
	
	printf("��������-->");
	
	while(scanf("%d", &indat) != EOF)
	{
		cnt[indat / 10]++;
		
		printf("��������-->");
		
	}
	
	printf("\n���������ʁ�����\n");
	
	for(i = 0; i < 5; i++)
	{
		printf("�z��[%d]:%d��\n",i,cnt[i]);
	}
	
	
	return 0;

}
