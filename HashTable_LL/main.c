#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// To execute C, please define "int main()"
#define ARRAY_LEN  11 // Using the prime number to make the insert value could put anywhere averagely

#define TEST_COUNT 10
#define TEST_DATA_LEN 15

typedef struct hash_table {
    char key[TEST_DATA_LEN];
    char value[TEST_DATA_LEN];
    struct hash_table *pNext;
} THash_Table;

const char cConstTestString[TEST_COUNT][TEST_DATA_LEN] = {"Amy Wang", "0912555691", "Taste Ts", "0923777996", "Yes Man", "034559211", "No Way", "0225993211", "Middle Brave", "055912453"};

int HashTable_Insert(THash_Table *ptHashTable_LinkedList)
{
  int i = 0;
  int iIndex = 0;
  THash_Table *tTempData = NULL;
  THash_Table *ptHashTable_Loop = NULL;
  if (ptHashTable_LinkedList == NULL)
  {
    printf ("The address memory is NULL\n");
    return -1;
  }
  
  for (i = 0; i < TEST_COUNT; i += 2)
  {
    iIndex = (int) cConstTestString[i][0];
    iIndex = iIndex % ARRAY_LEN;
    printf ("%d, %c => index: %d, %s\n", i, cConstTestString[i][0], iIndex, (ptHashTable_LinkedList + iIndex)->key);
    
    //printf("%02X\n", ptHashTable_LinkedList + iIndex);
    
    if (strlen((ptHashTable_LinkedList + iIndex)->key) > 0)
    {
      printf ("Value is existed\n");
      //represent the node has data
      tTempData = malloc(sizeof (THash_Table));
      snprintf (tTempData->key, TEST_DATA_LEN, "%s", cConstTestString[i]);
      snprintf (tTempData->value, TEST_DATA_LEN, "%s", cConstTestString[i + 1]);
      tTempData->pNext = NULL;
      
      ptHashTable_Loop = ptHashTable_LinkedList + iIndex;
      
      while (ptHashTable_Loop->pNext != NULL)
      {
        ptHashTable_Loop = ptHashTable_Loop->pNext;
      }
      
      ptHashTable_Loop->pNext = tTempData;
      
    }
    else
    {
      printf ("Value is not existed\n");
      snprintf (ptHashTable_LinkedList[iIndex].key, TEST_DATA_LEN, "%s", cConstTestString[i]);
      snprintf (ptHashTable_LinkedList[iIndex].value, TEST_DATA_LEN, "%s", cConstTestString[i + 1]);
      ptHashTable_LinkedList[iIndex].pNext = NULL;
    }
    
    ptHashTable_Loop = NULL;
    
    tTempData = NULL;
  }
  
  return 0;
}

int HashTable_LookUp()
{
  return 0;
}

int HashTable_Display(THash_Table *ptHashTable_LinkedList)
{
  if (ptHashTable_LinkedList == NULL)
  {
    printf ("The address memory is NULL\n");
    return -1;
  }
  
  int i = 0;
  int iCount = 0;
  THash_Table *pTempNode = NULL;
  
  for (i = 0; i < ARRAY_LEN; i ++)
  {
    pTempNode = ptHashTable_LinkedList + i;
    if (strlen (pTempNode->key) > 0)
    {
      printf("[%d] %s, %s\n", i, pTempNode->key, pTempNode->value);
      while (pTempNode->pNext != NULL)
      {
        iCount++;
        pTempNode = pTempNode->pNext;
        printf("[%d - %d] %s, %s\n", i, iCount, pTempNode->key, pTempNode->value);
      }
    }
    pTempNode = NULL;
  }
  return 0;
}

int HashTable_Init(THash_Table **pptHashTable_LinkedList)
{
  int i = 0;
  if (*pptHashTable_LinkedList != NULL || pptHashTable_LinkedList == NULL)
  {
    printf ("Fail to get address is NULL or already create a address memory\n");
    return -1;
  }
  *pptHashTable_LinkedList = malloc (sizeof (THash_Table) * ARRAY_LEN);
  if (*pptHashTable_LinkedList == NULL)
  {
    printf ("malloc failed\n");
    return -1;
  }
  
  //initial
  for (i = 0; i < ARRAY_LEN ; i++)
  {
    memset (((*pptHashTable_LinkedList) + i)->key, '\0', TEST_DATA_LEN);
    memset (((*pptHashTable_LinkedList) + i)->value, '\0', TEST_DATA_LEN);
    ((*pptHashTable_LinkedList) + i)->pNext = NULL;
    
    //printf("%02X\n", (*pptHashTable_LinkedList) + i);
  }
  
  return 0;
}

int main() 
{
  int i = 0;
  int iRet = 0;
  THash_Table *tHashTable_LinkedList = NULL;
  
  printf ("Testing data :\n");
  for (i = 0; i < TEST_COUNT; i += 2) 
  {
      printf (" %s (%s)\n", cConstTestString[i], cConstTestString[i+1]);
  }
  
  iRet = HashTable_Init(&tHashTable_LinkedList);
  if (iRet != 0)
  {
    printf ("Faile to init\n");
  }
  
  iRet = HashTable_Insert(tHashTable_LinkedList);
  if (iRet != 0)
  {
    printf ("Failed to insert");
  }
  
  iRet = HashTable_Display(tHashTable_LinkedList);
  if (iRet != 0)
  {
    printf ("Failed to insert");
  }
  
  return 0;
}

