//clear the row and column to 0, when the element Matrix[row][col] = 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_MATRX(M, N) (M * N)

int main()
{
	int iRow = 0, iCol = 0;
	int *pMatrx = NULL;
	int *pRow = NULL;
	int *pCol = NULL;
	int i = 0;

	printf ("Enter the Row:\n?");
	scanf ("%d", &iRow);

	printf ("Enter the Column:\n?");
	scanf ("%d", &iCol);

	pMatrx = (int *) malloc (sizeof(int) * MAX_MATRX(iRow, iCol));
	pRow = (int *) malloc (sizeof(int) * iRow);
	pCol = (int *) malloc (sizeof(int) * iCol);

	//initize the matrix
	for (i = 0; i < MAX_MATRX(iRow, iCol); i++)
	{
		if (i % iCol == 0)
		{
			printf ("\n");
		}
		pMatrx[i] = (rand() % 10);
		printf ("%d ", pMatrx[i]);
	}

	//find the zero and mark it
	for (i = 0; i < MAX_MATRX(iRow, iCol); i++)
	{
		if (pMatrx[i] == 0)
		{
			pRow[i / iRow] = 1;
			pCol[i % iCol] = 1;
		}
	}

	//Set the row and col to zero
	for (i = 0; i < MAX_MATRX(iRow, iCol); i++)
	{
		if (pRow[i / iRow] == 1 || pCol[i % iCol] == 1)
		{
			pMatrx [i] = 0;
		}
	}

	printf ("\n");

	//display the answer
	for (i = 0; i < MAX_MATRX(iRow, iCol); i++)
	{
		if (i % iCol == 0)
		{
			printf ("\n");
		}
		printf ("%d ", pMatrx[i]);
	}
	return 0;
}
