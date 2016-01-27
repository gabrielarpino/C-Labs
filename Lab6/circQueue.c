#include <stdio.h>
#include <stdlib.h>
#include "lab6.h"

void initQueue(struct Queue ** qPtr)
{
	struct Queue * Q = (struct Queue *)malloc(sizeof(struct Queue));
	Q->currSize = 0;
	Q->front = 0;
	Q->rear = 0;
	*qPtr = Q;
}

int isEmpty(struct Queue * Q)
{
	if (Q->currSize == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

void enqueue(struct Queue * Q, struct Data d)
{
	Q->queueArray[Q->rear].data=d;
	Q->rear=(Q->rear+1)%MaxQueueSize;
	Q->currSize++;
}

void dequeue(struct Queue * Q, struct Data *d)
{
	if (!isEmpty(Q)) {
		*d=Q->queueArray[Q->front].data;
		Q->front = (Q->front+1)%MaxQueueSize;
		Q->currSize--;
	}
}

void freeQueue(struct Queue * q)
{
	free(q);
}

