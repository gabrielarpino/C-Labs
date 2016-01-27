#include "lab8.h"

struct Edge ** initAdjMatrix(){

	struct Edge ** E = (struct Edge **)malloc(sizeof(struct Edge *)*(NODES));
	int i, j;

	for (i = 0; i<NODES; i++){
		E[i] = (struct Edge *)malloc(sizeof(struct Edge)*(NODES));
	}
	
	for (i = 0; i<(NODES); i++){
		for (j=0; j<(NODES); j++){
			E[i][j].flow = 0;
			E[i][j].flowCap = 0;
 		}
	}

	return E;
}

void insertAdjMatrix(struct Edge ** aM, int vi, int vj, int flow, int flowCap){

	aM[vi][vj].flow = flow;
	aM[vi][vj].flowCap = flowCap;	
}

void deleteAdjMatrix(struct Edge ** aM){
	
	int i;
	
	for (i = 0; i<NODES; i++){
		free(aM[i]);
	}
	free(aM);
}

void printAdjMat(struct Edge ** aM){
	
	int i, j;
	for (i=0; i<NODES; i++){
		for (j=0; j<NODES; j++){
			if (aM[i][j].flowCap > 0){
				printf("Edge: (%d, %d) Flow: %d Max Cap: %d \n", i, j, aM[i][j].flow, aM[i][j].flowCap);
			}
		}
	}	
}
