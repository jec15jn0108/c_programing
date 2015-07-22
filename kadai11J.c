#include	<stdio.h>

/*15jn0108 Onogaki Kaichi*/

void CurrencyEdit(int price, char *edit);

int main(void)
{
	int unit;
	int quan;
	int price;
	int sum;
	char edit_price[50];
	
	
	printf("’P‰¿,”—Ê-->");
	scanf("%d,%d", &unit, &quan);
	sum = 0;
	while(unit != 0 && quan != 0)
	{
		price = unit * quan;
		CurrencyEdit(price, edit_price);
		printf("‹àŠz:%s\n", edit_price);
		
		sum += price;
		printf("’P‰¿,”—Ê-->");
		scanf("%d,%d", &unit, &quan);
	}
	
	CurrencyEdit(sum, edit_price);
	printf("‡Œv‹àŠz:%s\n",edit_price);
	
	return 0;
}
///////////////////////////////

void CurrencyEdit(int price, char *edit)
{
	int idx;
	int i;
	int level;
	
	sprintf(edit, "\\%d", price);
	
	for(idx = 0; edit[idx] != '\0'; idx++){
	}
	
	level = 1;
	while( (price / 1000) > 0 )
	{
		for(i = 0; i < 4 * level; i++)
		{
			edit[idx - i + 1] = edit[idx - i];
		}
		edit[idx - i + 1] = ',';
		price = price / 1000;
		idx++;
		level++;
	}
}
