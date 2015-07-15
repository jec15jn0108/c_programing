#include <stdio.h>

/* 15jn0108 Onogaki kaichi*/

int main(void)
{
	char moji[30];
	char serch, replace;
	int  i = 0;
	
	printf("•¶Žš—ñ“ü—Í-->");
	scanf("%s",moji);
	fflush(stdin);
	printf("ŒŸõ•¶Žš-->");
	scanf("%c",&serch);
	fflush(stdin);
	printf("’uŠ·•¶Žš-->");
	scanf("%c",&replace);
	
	while( moji[i] != '\0')
	{
		if( moji[i] == serch )
		{
			moji[i] = replace;
		}
		
		i++;
	}
	
	printf("Œ‹‰Ê•¶Žš—ñ:%s",moji);
	
	
	return 0;

}
