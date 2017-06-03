// check the char is the same as the other one in two words
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

int main()
{
	char acString1[MAX_LEN], acString2[MAX_LEN];
	int iStringSum1[MAX_LEN] = {0}, iStringSum2[MAX_LEN] = {0};
	int i = 0;
	int iTemp = 0;
	printf ("Enter First Word:\n?");
	scanf("%s", acString1);
	printf ("Enter Sencond Word:\n?");
	scanf("%s", acString2);

	printf ("%s, %s\n", acString1, acString2);

	if (strlen(acString1) != strlen(acString2))
	{
		printf ("Never be match\n");
		return -1;
	}

	for (i = 0; i < strlen(acString1); i++)
	{
		iTemp = (int) acString1[i];
		iStringSum1[iTemp] ++;
		iTemp = (int) acString2[i];
		iStringSum2[iTemp] ++;
	}

	for (i = 0; i < MAX_LEN; i++)
	{
		//printf("%d, %d\n", iStringSum1[i], iStringSum2[i]);
		if (iStringSum1[i] != iStringSum2[i])
		{
			printf("This is fail to re-consist a new word\n");
			return -1;
		}
	}

	printf("This is OK to re-consist a new word\n");

	return 0;
}
