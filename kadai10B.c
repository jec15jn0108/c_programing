#include	<stdio.h>

int main(void)
{
	char  moji[] = "ABCD";
	char  *mp;
	
	mp = moji;
	
	while(*mp != '\0'){
		printf("%c\n",*mp);
		mp++;
	}
	
	return 0;
}