#include	<stdio.h>

/*15jn0108 Onogaki Kaichi*/

int main(void)
{
	FILE *source_c;
	
	char file_name[100];
	char line[1024];
	char *ret;
	
	printf("ƒtƒ@ƒCƒ‹–¼“ü—Í-->");
	scanf("%s",file_name);
	
	source_c = fopen(file_name, "r");
	
	if(source_c != NULL)
	{
		while( fgets(line, 1024, source_c) )
		{
			printf("%s", line);
		}
	}
	else
	{
		printf("Failed open the file.\n");
	}
	
	fclose(source_c);
	return 0;
}