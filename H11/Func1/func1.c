#include <stdio.h>
#include <stdlib.h>

#define MaxVertices 10  /* maximum number of vertices */
typedef int Vertex;     /* vertices are numbered from 0 to MaxVertices-1 */
typedef struct VNode *PtrToVNode;
struct VNode {
    Vertex Vert;
    PtrToVNode Next;
};
typedef struct GNode *Graph;

struct GNode {
    int NumOfVertices;
    int NumOfEdges;
    PtrToVNode *Array;
};

PtrToVNode insert(PtrToVNode p,int x)    
{    
    p->Next=(PtrToVNode)malloc(sizeof(struct VNode));    
    p=p->Next;    
    p->Vert=x;    
    p->Next=NULL;    
    return p;    
}    
  
Graph ReadG()  
{  
    int i,j,m,n,x,y;    
    scanf("%d%d",&m,&n);     
    Graph p=(Graph)malloc(sizeof(struct GNode));    
    PtrToVNode *rear=(PtrToVNode*)malloc(m*sizeof(struct VNode));    
    p->Array=(PtrToVNode*)malloc(m*sizeof(struct VNode));    
    p->NumOfVertices=m;    
    p->NumOfEdges=n;    
    for(i=0;i<m;i++){    
        rear[i]=p->Array[i]=(PtrToVNode)malloc(sizeof(struct VNode));    
        p->Array[i]->Next=NULL;    
    }    
    for(i=0;i<n;i++){    
        scanf("%d%d",&x,&y);    
        rear[x]=insert(rear[x],y);    
    }    
    for(i=0;i<m;i++){    
        PtrToVNode tmp=p->Array[i];    
        p->Array[i]=p->Array[i]->Next;    
        tmp->Next=NULL;    
        free(tmp);    
    }     
    return p;   
}  
  
void PrintV( Vertex V )
{
   printf("%d ", V);
}

void StronglyConnectedComponents( Graph G, void (*visit)(Vertex V) );

int main()
{
    Graph G = ReadG();
    StronglyConnectedComponents( G, PrintV );
    return 0;
}

int Stack[MaxVertices], order[MaxVertices],low[MaxVertices];
int Checked[MaxVertices];
int top=-1,timeOrder=0;

int inStack(int v){
	int i;
	for(i=0;i<=top;i++)
		if(Stack[i]==v)
			return 1;
	return 0;
}

void tarjan(Graph G, Vertex R,void (*visit)(Vertex V)){
	PtrToVNode temp;
	Checked[R]=1;
	order[R]=timeOrder++;
	low[R]=order[R];
	Stack[++top]=R;
	temp=G->Array[R];
	while(temp!=NULL){
		if(Checked[temp->Vert]==0){
			tarjan(G,temp->Vert,visit);
			low[R]=low[temp->Vert]<low[R]?low[temp->Vert]:low[R];
		}
		else if(inStack(temp->Vert))
			low[R]=low[R]<order[temp->Vert]?low[R]:order[temp->Vert];
		temp=temp->Next;
	}
	if(low[R]==order[R]){
		int v=Stack[top--];
		while(v!=R){
			visit(v);
			v=Stack[top--];
		}
		visit(R);
		if(top>=0||(timeOrder<G->NumOfVertices))
			printf("\n");
		else
			return;
	}
}

void StronglyConnectedComponents( Graph G, void (*visit)(Vertex V) ){
	int i;
	int nv=G->NumOfVertices;
	for(i=0;i<nv;i++){
		order[i]=-1;
		low[i]=-1;
		Checked[i]=0;
	}
	for(i=0;i<nv;i++){
		if(Checked[i]==0){
			tarjan(G,i,visit);
			if(timeOrder==G->NumOfVertices)
				break;
		}
	}
	return;
}

