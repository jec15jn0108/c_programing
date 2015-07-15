#include	<stdio.h>
#include	<string.h>

char *MojiSearch(char *m, char *s);

int	main(void)
{
	char moji[] = "ABCDEFGHJABFGHSKL";	/*�����Ώە�����*/
	char search[32];
	char *pSearched;
	
	printf("����������-->");
	scanf("%s", search);
	
	pSearched = MojiSearch(moji, search);

	printf("�����ʒu:");
	if(pSearched != NULL){
		printf("%s\n", pSearched);
	} else{
		printf("���������������͂���܂���ł���\n");
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
		return (m + i);
	} else{
		return NULL;
	}
}
