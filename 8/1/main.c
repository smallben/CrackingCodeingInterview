//Check the ASCII char is different char in one word
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIFFERENT_CHAR 256
#define MAX_STRING_LEN 1024

int main()
{
	char acString[MAX_STRING_LEN];
	int iStringIndex[MAX_DIFFERENT_CHAR];
	int i = 0;
	int iTempCharToInt = 0;
	printf ("Please Enter a string:\n?");

	scanf("%s", acString);

	if (strlen(acString) > MAX_DIFFERENT_CHAR)
	{
		//The meaningful string will not be over 256 char
		printf ("Duplicated alph.\n");
		return -1;
	}

	memset (iStringIndex, 0, MAX_DIFFERENT_CHAR);

	for (i = 0; i < strlen(acString); i++)
	{
		iTempCharToInt = (int) acString[i];
		iStringIndex[iTempCharToInt] ++;

		if (iStringIndex[iTempCharToInt] > 1)
		{
			printf ("Duplcated alph.\n");
			return -1;
		}
	}

	printf("Pass word\n");

	return 0;
}
