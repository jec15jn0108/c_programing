#include <stdio.h>

int main(void)
{
	int incOrExp, amount, balance = 0;
	
	printf("���x,���z==>");
	while(scanf("%d,%d",&incOrExp, &amount) != EOF)
	{
		if(incOrExp == 0)
		{
			balance += amount;
		}
		else
		{
			balance -= amount;
		}
		
		printf("���x,���z==>");
	}
	
	printf("�c��:%d�~\n",balance);
	
	return 0;

}
