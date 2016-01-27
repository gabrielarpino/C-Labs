#include "lab3.h"

struct functionCall * createStructArray(int n)
{
	struct functionCall * ptr;
	ptr = (struct functionCall *)malloc(sizeof(struct functionCall)*(unsigned long)n);
	return ptr;
}

void assignValues(struct functionCall * array, int index, int currentValueRes, int recursiveCallNumber, int exp )
{
	array[index].currentValueRes = currentValueRes;
	array[index].recursiveCallNumber = recursiveCallNumber;
	array[index].exp = exp;
}

void initArray(struct functionCall * array, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		array[i].currentValueRes = 0;
		array[i].recursiveCallNumber = 0;
		array[i].exp = 0;
	}
}

void recordRecursiveCalls(struct functionCall * array, int exp, int base)
{
	int i, res = 1, currentValue, recursiveCallNumber;
	
	for (i = exp; i >= 0; i--)
	{
		currentValue = res;
		res *= base;
		recursiveCallNumber = i+1;
		assignValues(array, i, currentValue, recursiveCallNumber, exp-i);
	}
}

void printArray(struct functionCall * array, int n)
{
	int i;
	for (i = 0; i < n; i ++)
	{
		printf("%d ", array[i].currentValueRes);
		printf("%d ", array[i].recursiveCallNumber);
		printf("%d ", array[i].exp);
		printf("\n");
	}
}

void freeArray(struct functionCall * array)
{
	free(array);
}
