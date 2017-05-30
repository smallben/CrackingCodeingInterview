#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_MAX (1*11)
#define CAT_STRING_MAX 5
#define CAT_STRING_LENGTH 6
#define STRING_NUM 3

typedef struct string_data {
	//for big data could extent this array size or items
	char acString1[STRING_MAX];
	char acString2[STRING_MAX];
	char acString3[STRING_MAX];
	char acStringAnswer[STRING_MAX * STRING_NUM];
	int iFinalFlag;
	int iStringIndex;
} TStringData;


int AppendString(char *pBuffer, TStringData *pSentence)
{
	int iLen = strlen(pBuffer);

	//printf ("len: %d\n", iLen);

	char *pTempString = NULL;
	switch (pSentence->iStringIndex)
	{
		case 1:
			pTempString = pSentence->acString1;
			break;
		case 2:
			pTempString = pSentence->acString2;
			break;
		case 3:
			pTempString = pSentence->acString3;
			break;
		default:
			break;
		
	}

	if ((pSentence->iFinalFlag + iLen) > (STRING_MAX - 1))
	{
		pSentence->iStringIndex++;
		pTempString += STRING_MAX;
		pSentence->iFinalFlag = 0;
	}

	//always use the same memory block
	snprintf (pTempString + pSentence->iFinalFlag, STRING_MAX, "%s", pBuffer);
	pSentence->iFinalFlag += iLen;

	return 0;
}

int ToString(TStringData *pSentence)
{
	snprintf (pSentence->acStringAnswer, STRING_MAX * STRING_NUM, "%s%s%s", pSentence->acString1, pSentence->acString2, pSentence->acString3);
	return 0;
}

char acBuffer[CAT_STRING_MAX][CAT_STRING_LENGTH] = {"aaaaa", "bbbbb", "ccccc", "ddddd", "eeeee"};

int main()
{
	TStringData *Sentence = (TStringData *) malloc (sizeof (TStringData));

	int i = 0;

	//init
	Sentence->iFinalFlag = 0;
	Sentence->iStringIndex = 1;
	for (i = 0; i < STRING_NUM; i++)
	{
		memset ((Sentence->acString1 + (i * STRING_MAX)), '\0', STRING_MAX);
	}
	memset (Sentence->acStringAnswer, '\0', STRING_MAX * STRING_NUM);


	if (Sentence == NULL)
	{
		printf ("The malloc failed\n");
	}

	for (i = 0; i < CAT_STRING_MAX; i++)
	{
		AppendString(acBuffer[i], Sentence);
	}

	ToString(Sentence);

	printf ("1: %s, 2: %s, 3: %s\n", Sentence->acString1, Sentence->acString2, Sentence->acString3);
	printf ("Answer: %s\n", Sentence->acStringAnswer);


	return 0;
}
