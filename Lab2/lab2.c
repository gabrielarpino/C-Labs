#include "lab2.h"

void initMatrix(int ***mat,int n)
/*initMatrix dynamically allocates a square matrix (nxn) and stores 0 into all entries*/
{
	int a,b;
	
/*Initialize a double pointer pointing to dynamically allocated memory space that stores n single pointers*/
	int **matrix = (int **)malloc(sizeof(int*)*(unsigned long)n);
	
/*Iterate through rows*/
	for (a = 0; a < n; a++)
	{	
/*Every pointer is pointing to a memory space allocated for storing n integer entries*/
		matrix[a] = (int*)malloc(sizeof(int)*(unsigned long)n);
		
/*Iterate through columns*/
		for (b = 0; b < n; b++)
		{
/*0 is stored in all entries*/		
			matrix[a][b] = 0;
		}
	}
	*mat = matrix;
}

void freeMatrix(int n, int ** matrix)
/*freeMatrix frees a square matrix (nxn)*/
{
	int a;
	
/*Free each 1D array pointed to by a single pointer*/
	for (a = 0; a < n; a++)
	{
		free(matrix[a]);
	}
/*Free double pointer*/
	free(matrix);
}

int **readMatrix(char * filename)
/* readMatrix reads the contents of a data file and stores the contents in a dynamically allocated 2D array (a square matrix of size MATSIZE) which is returned*/
{
	int ** matrix;
	int a, b;

/*Create a double pointer that points to a 2D array*/
	initMatrix(&matrix, MATSIZE);

/*Open file, read contents and store in 2D array*/
	FILE *fp = fopen(filename, "r");
	for (a = 0; a < MATSIZE; a++)
	{
		for (b = 0; b < MATSIZE; b++)
		{
			fscanf(fp, "%d", &matrix[a][b]);
		}
	}
	fclose(fp);
	return matrix;
}	

void printMatrix(int n, int ** A)
/*printMatrix prints the values of the square matrix of size n and frees the matrix*/
{
	int a,b;

/*Print the matrix*/
	for (a = 0; a < n; a++)
	{
		for (b = 0; b < n; b++)
		{
			printf("%d ", A[a][b]);
		}
		printf("\n");
	}
/*Free the matrix*/
	freeMatrix(n, A);
}

int **sum(int ** A, int ** B, int x1, int y1, int x2, int y2, int n)
/* sum function performs matrix addition on two sub-matrices (one from matrix A and one from B)
 of size n and returns the pointer to this new matrix (double pointer). Assume called 
 coordinates lie within and do not exceed the boundaries of matrix A and B*/
{
	int i, j, k, m;
	int matrix1[n][n], matrix2[n][n], ** sumMatrix;
	initMatrix(&sumMatrix, n);
	
/*Iterate through rows*/
	for (i = 0; i < n; i++)
	{
/*Iterate through columns*/
		for (j = 0; j < n; j++)
		{
/*Create sub-matricies from base coordinates of A and B*/ 
			matrix1[i][j] = A[x1 + i][y1 + j];
			matrix2[i][j] = B[x2 + i][y2 + j];
		}
	}
/*Iterate through rows*/
	for (k = 0; k < n; k++)
	{
/*Iterate through columns*/
		for (m = 0; m < n; m++)
		{
/*Perform matrix addition*/
			sumMatrix[k][m] = matrix1[k][m] + matrix2[k][m];
		}
	}
	return sumMatrix;	
}

int **sub(int **A, int **B, int x1, int y1, int x2, int y2, int n)
/* sub function performs matrix subtraction on two sub-matrices (sub-matrix from A subtract sub-matrix
 from B) of size nxn and returns the pointer to this new matrix (double pointer). Assume called coordinates
lie within and do not exceed the boundaries of matrix A and B*/
{
	int a, b, c, d;
	int matrix1[n][n], matrix2[n][n], **subMatrix;
	initMatrix(&subMatrix,n);
	
/*Iterate through rows*/
	for (a = 0; a < n; a++)
	{
/*Iterate through columns*/
		for (b = 0; b < n; b++)
		{
/*Create sub-matrices from base coordinates of A and B*/
			matrix1[a][b] = A[x1 + a][y1 + b];
			matrix2[a][b] = B[x2 + a][y2 + b];
		}
	}
/*Iterate through rows*/
	for (c = 0; c < n; c++)
	{
/*Iterate through columns*/
		for (d = 0; d < n; d++)
		{
/*Perform matrix subtraction*/
			subMatrix[c][d] = matrix1[c][d] - matrix2[c][d];
		}
	}
	return subMatrix;	
}
