#include "lab1.h"

void readMatrix(char fileName[STRINGSIZE])
{
	int nums[MATSIZE][MATSIZE];
	int i, j;
	FILE *fp = fopen(fileName, "r");
	for (i = 0; i < MATSIZE; i++)
	{
		for (j = 0; j < MATSIZE; j++)
		{
			fscanf(fp, "%d", &(nums[i][j]));
		}
	}
	fclose(fp);
	printMatrix(nums);
}
