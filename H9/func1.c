#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;
#define INFINITY 1000000
#define MaxVertexNum 10  /* maximum number of vertices */
typedef int Vertex;      /* vertices are numbered from 0 to MaxVertexNum-1 */
typedef int WeightType;

typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode MGraph;

MGraph ReadG(){
	int v, e,i;
	int v1,v2,w;
	MGraph m;
	m=(MGraph)malloc(sizeof (struct GNode));
	scanf("%d%d",&v,&e);
	m->Ne=e;
	m->Nv=v;
	for(i=0;i<e;i++){
		scanf("%d%d%d",&v1,&v2,&w);
		m->G[v1][v2]=w;
	}
	return m;
}

void ShortestDist( MGraph Graph, int dist[], int count[], Vertex S );

int main()
{
    int dist[MaxVertexNum], count[MaxVertexNum];
    Vertex S, V;
    MGraph G = ReadG();
    scanf("%d", &S);
    ShortestDist( G, dist, count, S);
    for ( V=0; V<G->Nv; V++ )
        printf("%d ", dist[V]);
    printf("\n");
    for ( V=0; V<G->Nv; V++ )
        printf("%d ", count[V]);
    printf("\n");

    return 0;
}


void ShortestDist( MGraph Graph, int dist[], int count[], Vertex S ){
	int i;
	bool checked[Graph->Nv];
	int smallest_dist;
	int p;
	
	for(i=0;i<Graph->Nv;i++){
		dist[i]=1e5;
		count[i]=0;
		checked[i]=false;
	}
	dist[S]=0;
	count[S]=1;
	
	while(true){
		smallest_dist=1e5; 
		p=1e5;
		for(i=0;i<Graph->Nv;i++){
			if(!checked[i] && dist[i]<smallest_dist){
				smallest_dist=dist[i];
				p=i;
			}
		}
		if(p==1e5)
			break;
		
		checked[p]=true;
		
		for(i=0;i<Graph->Nv;i++){
			if(!checked[i]&&Graph->G[p][i]>0){
				if(Graph->G[p][i]+dist[p]<dist[i])
					{
						dist[i]=Graph->G[p][i]+dist[p];
					}
			}
		}
	}
	
	for(i=0;i<Graph->Nv;i++)
		if(dist[i]==1e5)
			dist[i]=-1;
			
	for(i=0;i<Graph->Nv;i++){
		checked[i]=false;
	}
	
	while(true){
		smallest_dist=1e5; 
		p=1e5;
		for(i=0;i<Graph->Nv;i++){
			if(!checked[i] && dist[i]<smallest_dist){
				smallest_dist=dist[i];
				p=i;
			}
		}
		
		if(p==1e5)
			break;
		
		checked[p]=true;
		
		for(i=0;i<Graph->Nv;i++){
			if(!checked[i]&&Graph->G[p][i]>0){
				if(Graph->G[p][i]+dist[p]==dist[i])
					{
						count[i]=count[p]+count[i];
					}
			}
		}
	}
	
}
