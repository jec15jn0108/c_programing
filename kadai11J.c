#include	<stdio.h>

/*15jn0108 Onogaki Kaichi*/

void CurrencyEdit(int price, char *edit);

int main(void)
{
	int unit;
	int quan;
	int price;
	int sum;
	char editPrice[50];
	
	
	printf("’P‰¿,”—Ê-->");
	scanf("%d,%d", &unit, &quan);
	sum = 0;
	while(unit != 0 && quan != 0)
	{
		price = unit * quan;
		CurrencyEdit(price, editPrice);
		printf("‹àŠz:%s\n", editPrice);
		
		sum += price;
		printf("’P‰¿,”—Ê-->");
		scanf("%d,%d", &unit, &quan);
	}
	
	CurrencyEdit(sum, editPrice);
	printf("‡Œv‹àŠz:%s\n",editPrice);
}
///////////////////////////////

void CurrencyEdit(int price, char *edit)
{
	char editer[50];
	char 
	int work;
	int idx;
	idx = 0;
	
	sprintf(editer, "\\\\%d");
	while(work > 0)
	
	sprintf( 
}
