#include <stdio.h>
#include <stdlib.h>

#define MaxVertices 10  /* maximum number of vertices */


int Graph[MaxVertices][MaxVertices];
int Visited[MaxVertices];
int counter;

int Queue[MaxVertices];
int head=0, tail=0;

void DFS(int nv,int r){
	int i;
	Visited[r]=1;
	printf("%d ",r);
	for(i=0;i<nv;i++){
		if(Visited[i]||Graph[r][i]==0)
			continue;
		DFS(nv,i);
	}	
}

void BSF(int nv){
	int r,i;
	while(head<tail){
		r=Queue[head++];
		printf("%d ",r);
		counter++;
		for(i=0;i<nv;i++){
			if(Visited[i]==0&&Graph[r][i]==1){
				Queue[tail++]=i;
				Visited[i]=1;
			}
		}
	}
}

int main(){
	FILE * stream;

	int nv, ne,i,v1,v2,j;
	scanf("%d%d",&nv,&ne);
	for(i=0;i<nv;i++){
		for(j=0;j<nv;j++){
				Graph[i][j]=0;
			}
		}
	for(i=0;i<ne;i++){
		scanf("%d%d",&v1,&v2);
		Graph[v1][v2]=1;
		Graph[v2][v1]=1;
	}
	for(i=0;i<nv;i++){
		Visited[i]=0;
	}
	for(i=0;i<nv;i++){
		if(Visited[i]==0)
			{
				printf("{ ");
				DFS(nv,i);
				printf("}\n");
			}
	}
	for(i=0;i<nv;i++){
		Visited[i]=0;
	}
	counter=0;
	for(i=0;i<nv;i++){
		if(Visited[i]==0){
			Visited[i]=1;
			head=0;
			tail=0;
			printf("{ ");
			Queue[tail++]=i;
			BSF(nv);
			printf("}");
			if(counter<nv)
				printf("\n");
		}
	}
	return 0;
}
