#include "lab1.h"

void add(int matrix1[MATSIZE][MATSIZE], int matrix2[MATSIZE][MATSIZE] )
{
	int sumM[MATSIZE][MATSIZE];
	int i, j;
	
	for (i = 0; i < MATSIZE; i++)
	{
		for (j = 0; j < MATSIZE; j++)
		{
			sumM[i][j] = (matrix1[i][j] + matrix2[i][j]);
		}
	}

	printMatrix(sumM);
}

void sub(int matrix1[MATSIZE][MATSIZE], int matrix2[MATSIZE][MATSIZE] )
{
	int diffM[MATSIZE][MATSIZE];
	int i, j;

	for (i = 0; i < MATSIZE; i++)
	{
		for (j = 0; j < MATSIZE; j++)
		{
			diffM[i][j] = matrix1[i][j] - matrix2[i][j];
		}
	}
	printMatrix(diffM);
}

void mult(int matrix1[MATSIZE][MATSIZE], int matrix2[MATSIZE][MATSIZE] )
{
	int i, j, k;
	int product,sum;
	int multipliedM[MATSIZE][MATSIZE];

	for (i = 0; i < MATSIZE; i++)
	{	
		for (j = 0; j < MATSIZE; j++)
		{
			sum = 0;
			for (k = 0; k < MATSIZE; k++)
			{
				product = matrix1[i][k]*matrix2[k][j];
				sum = sum + product;
			}
			multipliedM[i][j] = sum;
		}
	}
	printMatrix(multipliedM);	
}

void matrixOperation(char filename1[STRINGSIZE], char filename2[STRINGSIZE], int operation)
{

	int mat1[MATSIZE][MATSIZE];
	int mat2[MATSIZE][MATSIZE];
	int i, j, a, b, c;
	FILE *fp = fopen(filename1, "r");
	FILE *fp1 = fopen(filename2, "r");



	for (i=0; i<MATSIZE; i++)
	{
		for (j=0; j<MATSIZE; j++)
		{
			fscanf(fp, "%d", &(mat1[i][j]));
		}
	}	
	
	for (a=0; a<MATSIZE; a++)
	{
		for (b=0; b<MATSIZE; b++)
		{	
			fscanf(fp1, "%d", &(mat2[a][b]));
		}
	}

	fclose(fp);
	fclose(fp1);

	{
		switch (operation) {
			case ADD:
				add(mat1, mat2);
				break;
			case SUBTRACT:
				sub(mat1, mat2);
				break;
			case MULTIPLY:
				mult(mat1, mat2);
				break;
			default:
				break;
		}
	}

}
