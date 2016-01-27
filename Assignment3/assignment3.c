#include "assignment3.h"

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
	
	for(i = 0; i < NODES; i ++){
		fN->parent[i] = -1;
		fN->visitedNodes[i] = 0;
	}

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

void maximizeFlowNetwork(struct flowNetwork * fN, int s, int t){
	int b, c;
	int m, n;
	int minF = 0;

	struct Queue * Q;
	initQueue(&Q);
	struct Data * D = (struct Data *)malloc(sizeof(struct Data));
	
	while(breadthFirstPathSearch(fN, s, t) == 1)
	{
		minF = INF;
		c = t;
		b = fN->parent[c];
		
		while(c != s){
			m = fN->adjMatrix[b][c].flowCap - fN->adjMatrix[b][c].flow;
			if(minF > m){
				minF = m;
			}
			D->vertex = c;
			enqueue(Q, *D);
			c = b;
			b = fN->parent[b];
		}

	n = t;
	while(isQueueEmpty(Q) == 0)
	{
		dequeue(Q, D);
		m = fN->parent[D->vertex];
		fN->adjMatrix[m][n].flow += minF;
		fN->adjMatrix[n][m].flow -= minF;
		n = m;
	}
	}
	free(D);
	free(Q);
	
}
