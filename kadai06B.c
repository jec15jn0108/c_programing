#include <stdio.h>

int main(void)
{
	int month;
	
	printf("月入力-->");
	scanf("%d",&month);

	
	switch(month)
	{
		case 1:
		case 3:
		case 7:
		case 8:
		case 10:
		case 12:
			printf("\n日数:31日\n");
			break;
		
		case 2:
			printf("\n日数:28日\n");
			break;
			
		case 4:
		case 6:
		case 9:
		case 11:
			printf("\n日数:30日\n");
			break;
			
		default:
			printf("月の入力エラー");
			break;
	}
	
	return 0;

}
