#include	<stdio.h>

/* 15jn0108 onogaki kaichi */

void quick_sort(int array[], int left, int right);
void swap(int *dat1, int *dat2);

///////////////////////////////////////////////////

int main(void)
{
	int array[8];
	int i;
	
	for(i = 0; i < 8; i++)
	{
		printf("®”[%d]:-->",i);
		scanf("%d",&array[i]);
	}
	
	quick_sort(array, 0, i);
	
	printf("––ƒ\[ƒgŒã––\n");
	for(i = 0; i < 8; i++)
	{
		printf("Œ‹‰Ê[%d]:%d\n", i, array[i]);
	}
	
	return 0;
}

////////////////////////////////////////////////////

void quick_sort(int array[], int left, int right)
{
	int left_h, right_h;
	int pivot;
	
	left_h = left;
	right_h = right;
	pivot = array[left];
	
	while( left < right )
	{
		while(array[left] < pivot && left < right)
		{
			left++;
		}
		while(array[right] > pivot && left < right)
		{
			right--;
		}
		
		if( left < right )
		{
			swap(&array[left], &array[right]);
		}
	}
	
	array[left] = pivot;
	
	pivot = left;
	left = left_h;
	right = right_h;
	
	if( left < pivot )
	{
		quick_sort(array, left, pivot - 1);
	}
	if( pivot < right )
	{
		quick_sort(array, pivot + 1, right);
	}
	
}

//////////////////////////////////////////////////

void swap(int *dat1, int *dat2)
{
	int tmp;
	
	tmp = *dat1;
	*dat1 = *dat2;
	*dat2 = tmp;
}