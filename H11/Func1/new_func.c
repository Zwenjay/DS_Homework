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

Graph ReadG(){
	int ne,nv,i;
	int v1,v2;
	PtrToVNode temp;
	Graph g=(Graph)malloc(sizeof(struct GNode));
	scanf("%d%d",&nv,&ne);
	g->NumOfEdges=ne;
	g->NumOfVertices=nv;
	g->Array=(PtrToVNode *)malloc(nv*sizeof(PtrToVNode));
	for(i=0;i<nv;i++){
		g->Array[i]=(PtrToVNode)malloc(sizeof(struct VNode));
		g->Array[i]->Vert=i;
		g->Array[i]->Next=NULL; 
	}
	for(i=0;i<ne;i++){
		scanf("%d%d",&v1,&v2);
		temp=g->Array[v1];
		while(temp->Next!=NULL){
			temp=temp->Next;
		}
		temp->Next=(PtrToVNode)malloc(sizeof(struct VNode));
		temp->Next->Vert=v2;
		temp->Next->Next=NULL;
	}
	return g;
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
  
int index=0;  
int top=0;  
int Stack[MaxVertices];  
int DFN[MaxVertices];  
int LOW[MaxVertices];  
int vi[MaxVertices];  
int whether[MaxVertices];  
  
int min(int x, int y)  
{  
    if( x >= y )  
    {  
        return y;  
    }  
    else if( x < y )  
    {  
        return x;  
    }  
}  
  
void Tarjan(int u, Graph G)  
{  
    int t, v;  
    DFN[u]=LOW[u]=index++;  
    Stack[top++]=u;  
    vi[u]=1;  
    struct VNode *temp;  
    temp=G->Array[u];  
    while(temp!=NULL)  
    {  
        v=temp->Vert;  
        if(DFN[v]==-1)  
        {  
            Tarjan(v, G);  
            LOW[u]=min(LOW[u],LOW[v]);  
        }  
        else if(whether[v]==0)  
        {  
            LOW[u]=min(LOW[u],DFN[v]);  
        }  
        temp=temp->Next;  
    }  
    if(DFN[u]==LOW[u])  
    {   
        do  
        {  
            t=Stack[--top];  
            printf("%d ", t);   
            whether[t]=1;  
        }while(u!=t);  
        printf("\n");  
    }  
}  
  
void StronglyConnectedComponents( Graph G, void (*visit)(Vertex V) )  
{  
    for(int i=0; i<G->NumOfVertices; i++)  
    {  
        vi[i]=0;  
        whether[i]=0;  
        DFN[i]=LOW[i]=-1;  
    }  
    for(int i=0; i<G->NumOfVertices; i++)  
    {  
        if(vi[i]==0)  
        {  
            Tarjan(i, G);  
        }  
    }  
}  
