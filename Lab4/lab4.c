#include "lab4.h"

void insertNode(int d, struct Node ** lPtr)
{	
	struct Node * currNode = *lPtr, * prevNode = NULL;
	struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data=d;
	
	if (currNode == NULL)
	{
		*lPtr = newNode;
		newNode->next = NULL;
		return;
	}
	
	else
	{
		while (currNode != NULL && (currNode->data) < d)
		{
			prevNode = currNode;
			currNode = currNode->next;
		}		
			
		if (prevNode == NULL) /*start*/
		{
			newNode->next = *lPtr;
			*lPtr = newNode;
		}

		else if (currNode == NULL)  /* end ?? */
		{
			prevNode->next = newNode;
			newNode->next = NULL;	
		}				
	
		else 
		{
			newNode->next = currNode;
			prevNode->next = newNode;
		}

		/*Encounter number greater than d*/
		
		/*While loop -- don't encounter*/

		/*Curr = null insert at end*/

	}
}
	
void deleteNode(int d, struct Node ** lPtr)
{
	struct Node * currNode = *lPtr, * prevNode = NULL;
	while (currNode != NULL)	
	{
		if (currNode->data==d)
		{
			if (prevNode == NULL)
			{
				*lPtr = currNode->next;
			}
			else
			{
				prevNode->next=currNode->next;
			}
			free(currNode);
			return;
		}
		prevNode = currNode;
		currNode = currNode->next;
	}
}

void printList(struct Node * L)
{
	struct Node * currNode = L;
	if (currNode != NULL)
	{
		while(currNode != NULL)
		{
			printf("%d ", currNode->data);
			currNode = currNode->next;
		}
		printf("\n");
	}
}	

struct Node ** createTable(int buckets)
{
	struct Node ** newtable = (struct Node**)malloc(sizeof(struct Node*)*(unsigned long) buckets);
	int i;
	
	for (i = 0; i < buckets; i++)
	{
		newtable[i] = NULL;
	}
	return newtable;
}

int findHash(int key, int buckets)
{
	int Hash = key%buckets;
	return Hash;
}

void insertTable(int key, int buckets, struct Node ** tablePtr)
{
	int spot = findHash(key, buckets);
	insertNode(key, &tablePtr[spot]);
}

void freeTable(struct Node ** tablePtr, int buckets)
{
	int i;
	struct Node * moment1, * moment2;
	for (i = 0; i < buckets; i++)
	{
		moment1 = tablePtr[i];
		while(moment1 != NULL)
		{
			moment2 = moment1;
			moment1 = moment1->next;
			free(moment2);
		}
	}
	free(tablePtr);
}


