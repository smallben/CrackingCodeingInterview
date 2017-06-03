#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap (char *pA, char *pB)
{
	*pA ^= *pB;
	*pB ^= *pA;
	*pA ^= *pB;
}

int main()
{
	char acString[1024];
	int i = 0;
	int iLen = 0;
	printf ("Enter a string:\n?");
	scanf ("%s", acString);

	iLen = strlen(acString);

	printf ("Before Reverse: %s\n", acString);


	while (i < (iLen / 2))
	{
		swap (&(acString[i]), &(acString[iLen - 1 - i]));
		i++;
	}

	printf ("After Reverse: %s\n", acString);

	return 0;
}

