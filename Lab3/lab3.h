#include <stdio.h>
#include <stdlib.h>

/*
 * Define the structure functionCall here
 */

struct functionCall{
	int currentValueRes;
	int recursiveCallNumber;
	int exp;
};

struct functionCall * createStructArray(int n);
void assignValues(struct functionCall * array, int index, int currentValueRes, int recursiveCallNumber, int exp);
void printArray(struct functionCall * array, int n);
void freeArray(struct functionCall * array);
void initArray(struct functionCall * array, int n);
void recordRecursiveCalls(struct functionCall * array, int exp, int base);
