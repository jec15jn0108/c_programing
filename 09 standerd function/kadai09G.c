#include <stdio.h>
#include <string.h>

/* 15jn0108 Onogaki kaichi*/

int main(void)
{
	char m1[50];
	char m2[50];
	char m3[50];
	int i, j;
	int m1Len;
	int m2Len;
	int m3Len;
	int diffe;
	
	printf("編集用文字列入力(m1)-->");
	scanf("%s",m1);
	fflush(stdin);
	printf("対象文字列(m2)-->");
	scanf("%s",m2);
	fflush(stdin);
	printf("置換文字列(m3)-->");
	scanf("%s",m3);
	printf("\n");
	
	m2Len = strlen(m2);
	m3Len = strlen(m3);
	
	diffe = m2Len - m3Len;
	
	i = 0;
	while(m1[i] != '\0')
	{
		m1Len = strlen(m1);
		if(strncmp(&m1[i], m2, m2Len) == 0)
		{
			if( m2Len < m3Len)
			{
				for(j = m1Len; j > i; j--)
				{
					m1[j - diffe] = m1[j];
				}
			}
			else
			{
				strcpy(&m1[i],&m1[i + diffe]);
			}
			strncpy(&m1[i], m3, m3Len);
		}
		i++;
	}
	m1[i] = '\0';
	
	printf("編集後(m1):%s\n",m1);
	
	
	
	return 0;

}
