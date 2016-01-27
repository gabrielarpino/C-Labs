#include "lab1.h"

void findDeterminant(char filename[STRINGSIZE])
/* Reads matrix from text file and stores it in 2 dimensional array
 and then calls the determinant function to compute the determinant*/
{
	int det=0;
	int s,t;
	int nums[MATSIZE][MATSIZE];
	
	FILE *fp = fopen(filename, "r");

	for (t = 0; t < MATSIZE; t++)
	{
		for (s = 0; s < MATSIZE; s++)
		{
/*Stores matrix in 2d array 'nums'*/
			fscanf(fp, "%d", &nums[t][s]);
		}
	}
	fclose(fp);
/*Calls determinant function*/
	det = determinant(MATSIZE, nums);
	printf("The determinant of the matrix in %s is %d\n", filename, det); 
}


int determinant(int n, int matrix[n][n] )
/* Computes the determinant of a square matrix*/
{
	int a, b, det, cskip, k;
	int smallmatrix[n-1][n-1];

/* Base Case: When the matrix is a single element*/
	if (n == 1)
	{
/*The determinant is itself*/
	return matrix[0][0];
	}

/*Base Case: When the number of rows/columns equals 2
 determinant is calculated as per Eq. 1 in Lab1 handout*/
	else if (n == 2)
	{
	det = (matrix[0][0]*matrix[1][1]) - (matrix[0][1]*matrix[1][0]);
	}

/*When the number of rows/columns is greater than 2
 the determinant is calculated as per Eq 2*/
	else
	{
	det = 0;
/*Iterate through the skipped column*/
		for (cskip = 0; cskip < n; cskip++)
		{
/*Iterate through rows*/
			for (a = 0; a < n-1; a++)
			{
				k = 0;
/*Iterate through columns*/
				for (b = 0; b < n; b++)
				{	
/*If the column isn't the skipped column*/
					if (b != cskip)
					{	
/*The value of the row increases by 1*/
						smallmatrix[a][k] = matrix[a+1][b];
						k++;
					}
					else
					{
						continue;
					}	
				}
			}
/*Implement Eq. 2*/
		det += pow(-1, cskip+2)*matrix[0][cskip]*determinant(n-1, smallmatrix);
		}		
	}	

	return det;
	}

