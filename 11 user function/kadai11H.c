#include	<stdio.h>
#include	<string.h>

/*15jn0108 Onogaki Kaichi*/

char *StrMid(const char *ss, char *ch, int st, int cnt);

int	main(void)
{
	char	str[100];
	char 	getStr[100];
	char 	*getStrp;
	int 	start;
	int		get;
	
	printf("文字列入力-->");
	scanf("%s",str);
	printf("指定範囲(開始位置,取得数)-->");
	scanf("%d,%d", &start, &get);
	
	getStrp = StrMid(str, getStr, start, get);
	
	if(getStrp != NULL)
	{
		printf("取り出した文字列:%s\n", getStrp);
	}
	else
	{
		printf("＊＊指定範囲外エラー＊＊\n");
	}
	
	return 0;
}
//////////////////////////

char *StrMid(const char *ss, char *ch, int st, int cnt)
{	
	int i;
	
	if( (st + cnt) <= (int)strlen(ss) )
	{
		for(i = 0; i < cnt; i++)
		{
			ch[i] = ss[st + i];
		}
		ch[i] = '\0';
	}
	else
	{
		ch = NULL;
	}
	
	return ch;
}