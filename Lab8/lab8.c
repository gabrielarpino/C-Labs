#include "lab8.h"

struct flowNetwork * initFlowNetwork(){
      
	struct flowNetwork * F = (struct flowNetwork *)malloc(sizeof(struct flowNetwork));
        F->adjMatrix = initAdjMatrix();

        int i;

        for (i=0; i<NODES; i++){
                F->visitedNodes[i] = 0;
                F->parent[i] = -1;
        }

        return F;
}

void deleteFlowNetwork(struct flowNetwork * fN){
	deleteAdjMatrix(fN->adjMatrix);
        free(fN);
}

int breadthFirstPathSearch(struct flowNetwork * fN, int s, int t){
	
	struct Queue *Q;
	int a, i;
	struct Data * start = (struct Data *)malloc(sizeof(struct Data));
	
	start->vertex = s;

	initQueue(&Q);
	enqueue(Q, *start); 

	
	while(isQueueEmpty(Q) != 1){
		dequeue(Q,start);
		
		a = start->vertex;
		fN->visitedNodes[a] = 1;
		
		for (i = 0; i<NODES; i++){
			if(fN->adjMatrix[a][i].flowCap != 0){
				if(fN->visitedNodes[i] == 0 && (fN->adjMatrix[a][i].flowCap - fN->adjMatrix[a][i].flow)>0){
					fN->parent[i] = a;
					start->vertex = i;
					enqueue(Q, *start);
					fN->visitedNodes[i] = 1;
				}
			}
		}
	}
	free(start);
	free(Q);
	
	if (fN->visitedNodes[t] == 0){
		return 0;
	}
	return 1; 		

}
