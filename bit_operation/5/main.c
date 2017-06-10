// Calculate the bit pattern. How many bits change could achieve the int A to int B.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ToBinary(int iNumber)
{
	int i = 0;
	int iTemp = 0;

	while (iNumber != 0)
	{
		if (iNumber & 0x1 == 1)
		{
			iTemp += pow(10, i);
		}
		i++;
		iNumber >>= 1;
	}

	return iTemp;
}

int main()
{
	int iNumber1 = 0, iNumber2 = 0;
	int iTemp = 0;
	int iCount = 0;

	printf ("Enter A number:\n?");
	scanf("%d", &iNumber1);
	printf ("Enter B number:\n?");
	scanf("%d", &iNumber2);

	printf ("%d, %d\n", iNumber1, ToBinary(iNumber1));

	printf ("%d, %d\n", iNumber2, ToBinary(iNumber2));

	iTemp = iNumber1 ^ iNumber2;

	while (iTemp != 0)
	{
		if (iTemp & 0x1 == 1)
		{
			iCount++;
		}
		iTemp >>= 1;
	}

	printf ("%d\n", iCount);


	return 0;
}
