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
	
	printf("���������-->");
	scanf("%s",str);
	printf("�w��͈�(�J�n�ʒu,�擾��)-->");
	scanf("%d,%d", &start, &get);
	
	getStrp = StrMid(str, getStr, start, get);
	
	if(getStrp != NULL)
	{
		printf("���o����������:%s\n", getStrp);
	}
	else
	{
		printf("�����w��͈͊O�G���[����\n");
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