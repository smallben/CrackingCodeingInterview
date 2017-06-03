#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024
#define SPACE_LEN 3 //strlen(%20)

int main()
{
	char acBuf[1024], *acNewString = NULL;
	int iStringLen = 0;
	int iNewStringLen = 0;
	int iSpaceNum = 0;
	int i = 0;


	printf ("Enter the String:\n");
	//scanf("%s", acBuf);
	fgets (acBuf, MAX_LEN, stdin);
	iStringLen = strlen(acBuf);

	for (i = 0; i < iStringLen; i++) 
	{
		if (acBuf[i] == ' ')
		{
			iSpaceNum ++;
		}
	}

	//printf ("%d\n", iStringLen);
	iNewStringLen = (iStringLen - iSpaceNum) + (SPACE_LEN * iSpaceNum); //remove space + new space len

	acNewString = (char*) malloc(sizeof (char) * (iNewStringLen + 1));
	//assert (malloc)
	
	acNewString[iNewStringLen] = '\0';
	//printf ("%d\n", iNewStringLen);

	for (i = iStringLen - 1; i >= 0; i--)
	{
		if (acBuf[i] == ' ')
		{
			acNewString[iNewStringLen - 1] = '0';
			acNewString[iNewStringLen - 2] = '2';
			acNewString[iNewStringLen - 3] = '%';
			iNewStringLen = iNewStringLen - 3;
			//printf ("%d\n", iNewStringLen);
		}
		else
		{
			iNewStringLen --; //len - i = index
			//printf ("%d\n", iNewStringLen);
			acNewString[iNewStringLen] = acBuf[i];
		}
	}

	printf ("%s => \n%s\n", acBuf, acNewString);
	return 0;
}
