#include <stdio.h>

int main(void)
{
	int dat, rtn;
	
	printf("�f�[�^����-->");
	scanf("%d", &dat);
	
	rtn = (dat >= 60) ? 1 : 0 ;
	
	if( rtn )
	{
		printf("���i\n");
	}
	else
	{
		printf("�s���i\n");
	}
	
	
	return 0;

}
