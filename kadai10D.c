#include	<stdio.h>
#include	<ctype.h>

int main(void)
{
	char	moji[20], num[20];
	char	*mp, *np;
	
	mp = moji;
	np = num;
	
	printf("•¶š—ñ“ü—Í-->");
	scanf("%s", moji);
	
	while(*mp != '\0'){
		if(isdigit(*mp)){
			*np = *mp;
			np++;
		}
		mp++;
	}
	*np = '\0';
	
	printf("”š•¶š—ñ:%s\n", num);
	
	return 0;
}