#include <stdio.h>

int main(void)
{
	char str ;
	
	printf("文字入力-->");
	scanf("%c",&str);
	
	printf("変換後:");
	
	if (str >= 'A' && str <='Z')
	{
		str+= 32;
		printf("%c\n",str);
	}
	else if (str >= 'a' && str <= 'z')
	{
		str-= 32;
		printf("%c\n",str);
	}
	else
	{
		printf("変換できない\n");
	}
	return 0;

}
