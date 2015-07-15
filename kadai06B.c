#include <stdio.h>

int main(void)
{
	int month;
	
	printf("Œ“ü—Í-->");
	scanf("%d",&month);

	
	switch(month)
	{
		case 1:
		case 3:
		case 7:
		case 8:
		case 10:
		case 12:
			printf("\n“ú”:31“ú\n");
			break;
		
		case 2:
			printf("\n“ú”:28“ú\n");
			break;
			
		case 4:
		case 6:
		case 9:
		case 11:
			printf("\n“ú”:30“ú\n");
			break;
			
		default:
			printf("Œ‚Ì“ü—ÍƒGƒ‰[");
			break;
	}
	
	return 0;

}
