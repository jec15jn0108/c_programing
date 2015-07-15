#include <stdio.h>

/* 15jn0108 Onogaki kaichi*/

int main(void)
{
	char moji[30];
	char kmoji[15], gmoji[15];
	int i, g = 0, k = 0;
	
	printf("•¶š—ñ“ü—Í-->");
	scanf("%s",moji);
	
	for( i = 0; moji[i] != '\0'; i++)
	{
		if( i % 2 == 0)
		{
			gmoji[g] = moji[i];
			g++;
		}
		else
		{
			kmoji[k] = moji[i];
			k++;
		}
	}
	gmoji[g] = '\0';
	kmoji[k] = '\0';
	
	printf("\n‹ô”—v‘f:%s\n",gmoji);
	printf("Šï”—v‘f:%s\n",kmoji);

	return 0;

}
