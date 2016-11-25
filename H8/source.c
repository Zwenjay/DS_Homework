#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;
#define MaxVertexNum 10  /* maximum number of vertices */
typedef int Vertex;      /* vertices are numbered from 0 to MaxVertexNum-1 */

typedef struct AdjVNode *PtrToAdjVNode;

struct AdjVNode{
    Vertex AdjV;
    PtrToAdjVNode Next;
};

typedef struct Vnode{
    PtrToAdjVNode FirstEdge;
} AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;

struct GNode{  
    int Nv;
    int Ne;
    AdjList G;
};


typedef PtrToGNode LGraph;


LGraph ReadG(); /* details omitted */

bool TopSort( LGraph Graph, Vertex TopOrder[]);

int main()
{
    int i;
    Vertex TopOrder[MaxVertexNum];
    LGraph G = ReadG();

    if (TopSort(G, TopOrder)==true )
        for ( i=0; i<G->Nv; i++ )
            printf("%d ", TopOrder[i]);
    else
        printf("ERROR");
    printf("\n");
    return 0;
}

LGraph ReadG(){
	int v, e, a, b,i,j;
	scanf("%d%d",&v,&e);
	LGraph gn;

	PtrToAdjVNode tempNd;
	gn=(LGraph)malloc(sizeof(struct GNode));
	gn->Ne=e;
	gn->Nv=v;
	
	for(i=0;i<v;i++){
		gn->G[i].FirstEdge=(PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
		gn->G[i].FirstEdge->AdjV=-1;
		gn->G[i].FirstEdge->Next=NULL; 
	}

	for(i=0;i<e;i++){
		scanf("%d%d",&a,&b);
		tempNd=NULL;
		if (gn->G[a].FirstEdge->AdjV==-1){
			gn->G[a].FirstEdge->AdjV=a;
			gn->G[a].FirstEdge->Next=(PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
			gn->G[a].FirstEdge->Next->AdjV=b;
			gn->G[a].FirstEdge->Next->Next=NULL; 
		}
		else{
			tempNd=gn->G[a].FirstEdge;
			while(tempNd->Next!=NULL){
				tempNd=tempNd->Next;
			}
			tempNd->Next=(PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
			tempNd->Next->AdjV=b;
			tempNd->Next->Next=NULL;
		}
	}
	for(i=0;i<v;i++){
		if(gn->G[i].FirstEdge->AdjV==-1)
			gn->G[i].FirstEdge->AdjV=i;
	}
	return gn;
}


bool TopSort( LGraph Graph, Vertex TopOrder[]){
	int v=Graph->Nv;
	int begin=0, end=0,k=0;
	int q[MaxVertexNum];
	int i=0;
    int indegree[MaxVertexNum];  
    for(i=0;i<MaxVertexNum;i++)
        indegree[i]=0;  

	PtrToAdjVNode tempV; 
	
	for(i=0;i<v;i++){
		tempV=Graph->G[i].FirstEdge;

		while(tempV!=NULL){
			indegree[tempV->AdjV]++;
			tempV=tempV->Next;
		}
	}	
	
	for(i=0;i<v;i++){
		if(indegree[i]==0){
			q[end++]=i;
		}
	}
	
	while(end>begin){
		TopOrder[k++]=q[begin++];
		tempV=Graph->G[q[begin-1]].FirstEdge;
		while(tempV!=NULL){ 
			if(--indegree[tempV->AdjV]==0)
			{
				q[end++]=tempV->AdjV;
			}
			tempV=tempV->Next;
		}
	}
	if (k!=v) return false;
	else return true;
}


