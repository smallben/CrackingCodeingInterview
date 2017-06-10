// This is for the compress the string. for the aabbbcc to a2b3c2. The string is more less than original.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

char *compress(char *pBuf)
{
	int iLen = strlen(pBuf);
	//This is mean the compress cannot exceed the original length
	char *pCompress = (char *)malloc (sizeof (char) * (iLen + 1));
	//assert (malloc)
	int iCount = 0;
	int i = 0;
	char cTempCheck = *pBuf;
	int iCatLen = 0;
	printf ("Orig len: %d, Check Char: %c\n", iLen, cTempCheck);

	while (i < iLen)
	{
		if (cTempCheck == *(pBuf + i))
		{
			iCount ++;
			i++;
		}
		else
		{
			if (strlen(pCompress) + 2 >= iLen)
			{
				return pBuf;
			}
			iCatLen += snprintf (pCompress + iCatLen, iLen + 1, "%c%d", cTempCheck, iCount);
			cTempCheck = *(pBuf + i);
			iCount = 0;
		}
	}

	//this is for the i == iLen to break;
	if (strlen(pCompress) + 2 >= iLen)
	{
		return pBuf;
	}
	iCatLen = snprintf (pCompress + iCatLen, iLen + 1, "%c%d", cTempCheck, iCount);

	return pCompress;
}

int main()
{
	char acBuf[MAX_LEN];
	char acAnswer[MAX_LEN];

	memset (acBuf, '\0', MAX_LEN);

	printf ("Enter the testing case:\n?");
	scanf ("%s", acBuf);

	printf ("Orig: %s\n", acBuf);

	snprintf (acAnswer, MAX_LEN, "%s", compress(acBuf));
	
	printf ("Compress: %s\n", acAnswer);

	return 0;
}
