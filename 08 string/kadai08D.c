#include <stdio.h>

/* 15jn0108 Onogaki kaichi*/

int main(void)
{
	char m1[30];
	char m2[30];
	char deleteWord;
	int i;
	int j;
	
	printf("文字列入力(m1)-->");
	scanf("%s",m1);
	fflush(stdin);
	printf("削除文字-->");
	scanf("%c",&deleteWord);
	
	m2[0] = '\0';
	
	for( i = 0; m1[i] != '\0'; i++)
	{
		if( m1[i] != deleteWord )
		{
			for( j = 0; m2[j] != '\0'; j++);
			m2[j] = m1[i];
			m2[j + 1] = '\0';
		}
	}
	
	printf("\n結果文字列(m2):%s\n",m2);
	
	return 0;

}
