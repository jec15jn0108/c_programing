#include <stdio.h>

int main(void)
{
	int mon ;
	printf("�������-->");
	scanf("%d",&mon);
	
	printf("����:");
	
	if (mon < 1 || mon > 12)
	{
		printf("���̓��̓G���[\n");
	}
	else if (mon >= 3 && mon <= 5)
	{
		printf("�G�߂͏t\n");
	}
	else if (mon >= 6 && mon <= 8)
	{
		printf("�G�߂͉�\n");
	}
	else if (mon >= 9 && mon <= 11)
	{
		printf("�G�߂͏H\n");
	}
	else
	{
		printf("�G�߂͓~\n");
	}
	
	return 0;

}
