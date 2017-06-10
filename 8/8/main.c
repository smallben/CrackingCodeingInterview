// Find the rotate string from the the original string
// Such as: cdeab is abcde rotate string.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

int isSubString(char *pS1, char *pS2)
{
	int iS1Len = strlen(pS1);
	int iS2Len = strlen(pS2);
	if (iS1Len != iS2Len)
	{
		return 0;
	}

	char *pTempString = NULL;
	int iTempLen = iS1Len * 2 + 1;
	int i = 0, j = 0;
	int iFirst = 1, iPoint = 0, iFlag = 0;
	pTempString = (char *) malloc (sizeof (char) * iTempLen);
	snprintf (pTempString, iTempLen, "%s%s", pS1, pS1);

	while (i < iS1Len * 2)
	{
		if (iFlag != 0)
		{
			i = iPoint + 1;
			j = 0;
			iFirst = 1;
			iFlag = 0;
		}
		if (pTempString[i] == pS2[j])
		{
			if (iFirst == 1)
			{
				iFirst = 0;
				iPoint = i;
			}
			j++;
		}
		else
		{
			if (iFirst != 1) // First means continous mode for checking string
			{
				iFlag = 1;
			}
		}

		if (j == iS2Len)
		{
			return 1;
		}
		i++;
	}
	return 0;
}


int main()
{
	char acString1[MAX_LEN];
	char acString2[MAX_LEN];

	memset (acString1, '\0', MAX_LEN);
	memset (acString2, '\0', MAX_LEN);

	printf ("Enter original string:\n?");
	scanf ("%s", acString1);

	printf ("Enter rotate string:\n?");
	scanf ("%s", acString2);

	if (isSubString(acString1, acString2))
	{
		printf ("%s is %s's substring\n", acString2, acString1);
	}
	else
	{
		printf ("No relationship\n");
	}
	return 0;
}
