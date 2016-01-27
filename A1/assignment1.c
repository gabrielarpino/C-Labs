#include "assignment1.h"

void denseMatrixMult(int ** A, int ** B, int *** resultMatrix, int n)
{ 
	int ** Z;
	int ** smallA, ** smallB, ** result;
	int i, j;
	
	/*Initalize Zeros and Results*/
	initMatrix(&Z, n);
	initMatrix(&result, n);	

	int **M0, **M1, **M2, **M3, **M4, **M5, **M6;
	int **C00, **C01, **C10, **C11;

	/*Base Case when n = 1*/	
	if (n == 1)
	{
		result[0][0] = A[0][0]*B[0][0];
	}
	else
	{	/*Create Ms*/
		/*M0*/
		smallA = sum(A, A, 0, 0, n/2, n/2, n/2);
		smallB = sum(B, B, 0, 0, n/2, n/2, n/2);
		denseMatrixMult(smallA, smallB,&M0, n/2);
		freeMatrix(n/2, smallA);
		freeMatrix(n/2, smallB);

		/*M1*/
		smallA = sum(A, A, n/2, 0, n/2, n/2, n/2);
		smallB = sum(B, Z, 0, 0, 0, 0, n/2);
		denseMatrixMult(smallA, smallB, &M1, n/2);
		freeMatrix(n/2, smallA);
		freeMatrix(n/2, smallB);	
		
		/*M2*/
		smallA = sum(A, Z, 0, 0, 0, 0, n/2);
		smallB = sub(B, B, 0, n/2, n/2, n/2, n/2);
		denseMatrixMult(smallA, smallB, &M2, n/2);
		freeMatrix(n/2, smallA);
		freeMatrix(n/2, smallB);

		/*M3*/
		smallA = sum(A, Z, n/2, n/2, 0, 0, n/2);
		smallB = sub(B, B, n/2, 0, 0, 0, n/2);
		denseMatrixMult(smallA, smallB, &M3, n/2);
		freeMatrix(n/2, smallA);
		freeMatrix(n/2, smallB);

		/*M4*/
		smallA = sum(A, A, 0, 0, 0, n/2, n/2);
		smallB = sum(B, Z, n/2, n/2, 0, 0, n/2);
		denseMatrixMult(smallA, smallB, &M4, n/2);
		freeMatrix(n/2, smallA);
		freeMatrix(n/2, smallB);

		/*M5*/
		smallA = sub(A, A, n/2, 0, 0, 0, n/2);
		smallB = sum(B, B, 0, 0, 0, n/2, n/2);
		denseMatrixMult(smallA, smallB, &M5, n/2);
		freeMatrix(n/2, smallA);
		freeMatrix(n/2, smallB);

		/*M6*/
		smallA = sub(A, A, 0, n/2, n/2, n/2, n/2);
		smallB = sum(B, B, n/2, 0, n/2, n/2, n/2);
		denseMatrixMult(smallA, smallB, &M6, n/2);
		freeMatrix(n/2, smallA);
		freeMatrix(n/2, smallB);
		
		/*Create Cs*/
		/*C00*/
		smallA = sum(M0, M3, 0, 0, 0, 0, n/2);
		smallB = sub(M4, M6, 0, 0, 0, 0, n/2);
		C00 = sub(smallA, smallB, 0, 0, 0, 0, n/2);
		freeMatrix(n/2, smallA);
		freeMatrix(n/2, smallB);

		/*C01*/
		C01 = sum(M2, M4, 0, 0, 0, 0, n/2);

		/*C10*/
		C10 = sum(M1, M3, 0, 0, 0, 0, n/2);

		/*C11*/
		smallA = sub(M0, M1, 0, 0, 0, 0, n/2);
		smallB = sum(M2, M5, 0, 0, 0, 0, n/2);
		C11 = sum(smallA, smallB, 0, 0, 0, 0, n/2); 

		freeMatrix(n/2, smallA);
		freeMatrix(n/2, smallB);

		/*Inserting Cs into proper quadrants*/
		for (i = 0; i < n/2; i++)
		{
			for (j = 0; j < n/2; j++)
			{
				result[i][j] = C00[i][j];
			}
		}
		
		for (i = 0; i < n/2; i++)
		{
			for (j = n/2; j < n; j++)
			{
				result[i][j] = C01[i][j-(n/2)];
			}
		}
		
		for (i = n/2; i < n; i++)
		{
			for (j = 0; j < n/2; j++)
			{
				result[i][j] = C10[i-(n/2)][j];
			}
		}
		
		for (i = n/2; i < n; i++)
		{
			for (j = n/2; j < n; j++)
			{
				result[i][j] = C11[i-(n/2)][j-(n/2)];
			}
		}

		/*FREE Ms and Cs*/
		freeMatrix(n/2, M0);
		freeMatrix(n/2, M1);
		freeMatrix(n/2, M2);
		freeMatrix(n/2, M3);
		freeMatrix(n/2, M4);
		freeMatrix(n/2, M5);
		freeMatrix(n/2, M6);

		freeMatrix(n/2, C00);
		freeMatrix(n/2, C01);
		freeMatrix(n/2, C10);
		freeMatrix(n/2, C11);
	}

	/*Free zero*/
	freeMatrix(n, Z);
	/*Assign result*/
	*resultMatrix = result;
}
int **sum(int ** A, int ** B, int x1, int y1, int x2, int y2, int n)
/*Performs matrix addition of two sub-matrices and returns the pointer to this matrix*/
{
	int i, j, k, m;
	int matrix1[n][n], matrix2[n][n], **sumMatrix;
	initMatrix(&sumMatrix, n);

	/*Iterate through rows and columns to make new matrices that are denoted by the indices*/
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			matrix1[i][j] = A[x1 + i][y1 + j];
			matrix2[i][j] = B[x2 + i][y2 + j];
		}
	}
	
	/*Iterate through rows and columns of new matrices and perform matrix addition*/
	for (k = 0; k < n; k++)
	{
		for (m = 0; m < n; m++)
		{
			sumMatrix[k][m] = matrix1[k][m] + matrix2[k][m];
		}
	}
	return sumMatrix; 
}

int **sub(int **A, int **B, int x1, int y1, int x2, int y2, int n)
/*Performs matrix subtraction of two sub-matrices and return the pointer to this matrix*/
{
        int i, j, k, m;
        int matrix1[n][n], matrix2[n][n], **subMatrix;
        initMatrix(&subMatrix, n);

	/*Iterate through rows and columns to make new matrices that are denoted by the indices*/
        for (i = 0; i < n; i++)
        {
                for (j = 0; j < n; j++)
                {
                        matrix1[i][j] = A[x1 + i][y1 + j];
                        matrix2[i][j] = B[x2 + i][y2 + j];
                }
        }
	
	/*Iterate through rows and columns of new matrices and perform matrix subtraction*/
        for (k = 0; k < n; k++)
        {
                for (m = 0; m < n; m++)
                {
                        subMatrix[k][m] = matrix1[k][m] - matrix2[k][m];
                }
        }
        return subMatrix;
}

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
}
