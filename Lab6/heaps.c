#include <stdio.h>
#include <stdlib.h>
#include "lab6.h"

struct Heap * initMinHeap()
{
	struct Heap* h = (struct Heap*)malloc(sizeof(struct Heap));
	h->count = 0;
	return h;
}

void insertMinHeap(struct Heap * h, struct Data d)
{
	int childI = h->count +1;
	int parentI = childI/2;
	while (parentI>0) {

		if (h->heapArray[parentI].data.data > d.data) {

			h->heapArray[childI] = h->heapArray[parentI];
			childI = parentI;
			parentI = parentI/2;
		}
		else {
			h->heapArray[childI].data = d;
			h->count ++;
			return;
		}
	}
	h->heapArray[childI].data = d;
	h->count++;
}

struct Data removeMinHeap(struct Heap * h)
{
	struct Data res = h->heapArray[1].data;
	h->heapArray[1] = h->heapArray[h->count];
	h->count = h->count -1;
	int parentI = 1;
	int childI = 2*parentI;
	struct Data t;
	while (childI <= h->count) {
		if (childI < h->count) {
			if (h->heapArray[childI].data.data > h->heapArray[childI+1].data.data) {
				childI++;
			}
		}
		if (h->heapArray[parentI].data.data > h->heapArray[childI].data.data) {
			t = h->heapArray[parentI].data;
			h->heapArray[parentI] = h->heapArray[childI];
			h->heapArray[childI].data = t;
		}
		parentI = childI;
		childI = childI*2;
	}	
	return res;
}



void freeMinHeap(struct Heap * h)
{
	free(h);
}
