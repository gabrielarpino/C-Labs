#include "queue.h"

struct Queue initQueue()
{
	struct Queue q;	
	q.currSize = 0;
	q.front = NULL;
	q.rear = NULL;
	return q;
}

void enqueue(struct Queue *qPtr, struct Data d)
{
	struct Node * newNode;
	newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = d;
	newNode-> next = NULL;
	if (qPtr->rear==NULL) {
		qPtr->rear=newNode;
		qPtr->front=newNode;
	}
	else
	{
		qPtr->rear->next=newNode;
		qPtr->rear=newNode;
	}
	qPtr->currSize++;
}

struct Data dequeue(struct Queue *qPtr)
{
	struct Node * temp;
	struct Data res;
	temp = qPtr->front;
	res = temp -> data;
	if (qPtr->front==qPtr->rear) {
		qPtr->front=NULL;
		qPtr->rear=NULL;
	}
	else {
		qPtr->front=temp->next;
	}
	free(temp);
	qPtr->currSize--;
	return res;
}
void freeQueue(struct Queue *qPtr)
{
	while(qPtr->currSize != 0) {
		dequeue(qPtr);
	}
}
