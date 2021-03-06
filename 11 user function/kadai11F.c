#include	<stdio.h>
#include	<string.h>

char *MojiSearch(char *m, char *s);

int	main(void)
{
	char moji[] = "ABCDEFGHJABFGHSKL";	/*検索対象文字列*/
	char search[32];
	char *pSearched;
	
	printf("検索文字列-->");
	scanf("%s", search);
	
	pSearched = MojiSearch(moji, search);

	printf("検索位置:");
	if(pSearched != NULL){
		printf("%s\n", pSearched);
	} else{
		printf("検索したい文字はありませんでした\n");
	}
	
	return 0;
}
//////////////////////
char *MojiSearch(char *m, char *s)
{
	int i;
	int mLen, sLen;
	
	mLen = (int)strlen(m);
	sLen = (int)strlen(s);
	
	i = 0;
	while(strncmp((m + i), s, sLen) && i < mLen){
		i++;
	}
	
	if( i != mLen){
		m += i;
	} else{
		m = NULL;
	}
	
	return m;
}
