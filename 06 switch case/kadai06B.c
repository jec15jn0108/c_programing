#include <stdio.h>

int main(void)
{
	int month;
	
	printf("������-->");
	scanf("%d",&month);

	
	switch(month)
	{
		case 1:
		case 3:
		case 7:
		case 8:
		case 10:
		case 12:
			printf("\n����:31��\n");
			break;
		
		case 2:
			printf("\n����:28��\n");
			break;
			
		case 4:
		case 6:
		case 9:
		case 11:
			printf("\n����:30��\n");
			break;
			
		default:
			printf("���̓��̓G���[");
			break;
	}
	
	return 0;

}
