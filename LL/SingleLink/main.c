#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

#define MAX_LEN 512

typedef struct _node {
	int iKey;
	char acName[512];
	struct _node *pNext;
} TNode;

int gTerminated = 0;

void sig_handler (int signo)
{
	if (signo == SIGINT)
	{
		gTerminated = 1;
	}
}

int Create (TNode **pptSingleList)
{
	if (pptSingleList == NULL)
	{
		printf ("variable is not declared\n");
		return -1;
	}

	*pptSingleList = malloc (sizeof (TNode));
	//asset (malloc)
	
	printf ("%x\n", *pptSingleList);

	return 0;
}

int Insert (TNode *ptSingleList, int *piFlag, int iKey, char *pBuf)
{
	TNode *pTemp = NULL;
	//asset (ptSingleList)
	if (*piFlag == 1)
	{
		ptSingleList->iKey = iKey;
		snprintf (ptSingleList->acName, MAX_LEN, "%s", pBuf);
		ptSingleList->pNext = NULL;
		*piFlag = 0;
	}
	else
	{
		pTemp = malloc (sizeof (TNode));
		pTemp->iKey = iKey;
		snprintf (pTemp->acName, MAX_LEN, "%s", pBuf);
		pTemp->pNext = NULL;

		while (ptSingleList->pNext != NULL)
		{
			ptSingleList = ptSingleList->pNext;
		}

		ptSingleList->pNext = pTemp;
	}

	return 0;
}

int LinkedListLen (TNode *ptSingleList)
{
	int iLen = 0;
	
	while (ptSingleList != NULL)
	{
		iLen ++;
		ptSingleList = ptSingleList->pNext;
	}

	
	return iLen;
}

int Display (TNode *ptSingleList)
{
	int i = 0;
	while (ptSingleList != NULL)
	{
		printf ("[%d] %d, %s\n", i, ptSingleList->iKey, ptSingleList->acName);
		i++;
		ptSingleList = ptSingleList->pNext;
	}
	return 0;
}

int main ()
{
	TNode *ptSingleList = NULL;

	int iKey = 0;
	char acBuf[MAX_LEN];
	int iFlag = 0;
	int i = 0;

	signal (SIGINT, sig_handler);

	Create (&ptSingleList);
	iFlag = 1; //represent the linked list is empty

	while (!gTerminated)
	{
		printf ("Enter Key: \n?");
		scanf("%d", &iKey);
		printf ("Enter Name: \n?");
		scanf("%s", acBuf);
		Insert (ptSingleList, &iFlag, iKey, acBuf);
		printf ("Leave Press CTRL+C\n");
		sleep(1);
		i++;
	}

	Display (ptSingleList);

	printf ("Total Len: %d\n", LinkedListLen(ptSingleList));

	return 0;
}
