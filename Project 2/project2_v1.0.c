#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

#define INFINITY 1000000
#define MaxStationNum 500  // maximum number of stations
#define PBMC 0

typedef int Station;
typedef int RoadLength;
typedef struct GNode *PtrToGNode;

struct GNode{
    int Capacity;	//Maxium capacity for each station, Capacity should be even and no more than 100
	int Ns;			//number of stations in the graph 
    int Nr;			//number of roads in the graph
    RoadLength R[MaxStationNum][MaxStationNum];		//road's length
    int CurrentNums[MaxStationNum];		//current number of bikes for each station
    int LeastNeed[MaxStationNum];		//the least bikes needed for a certain station's shortest path, could be negative
    Station Sp;			//the problem station
};

typedef PtrToGNode MGraph;

MGraph ReadG();
void Solution(MGraph G, RoadLength dist[], Station path[]);

int main()
{
	Station path[MaxStationNum];	 
	int counter=0,i;
	Station sign;
    RoadLength dist[MaxStationNum]; 
	Station ReversePath[MaxStationNum];
    Station S;
    
    MGraph G = ReadG();
    Solution(G,dist, path);
    
    /*
    	If needed bike is positive, it will be printed out, 
		else, print 0
	*/
    if(G->LeastNeed[G->Sp]>0)
    	printf("%d ",G->LeastNeed[G->Sp]);
    else
    	printf("0 ");
    
    
	sign=G->Sp;		// Set a sign, in order to find its path from the end.
	
	//Fine the reverse path
	while(sign!=PBMC){
		ReversePath[counter++]=sign;
		sign=path[sign];
	}
	ReversePath[counter]=PBMC;
	
	//print the path
	for(i=counter;i>0;i--){
		printf("%d->",ReversePath[i]);
	}
	printf("%d ",ReversePath[0]);
	
	/*
    	If needed bike is negative, it will be printed out, 
		else, print 0
	*/
	if(G->LeastNeed[G->Sp]<0)
		printf("%d",-1*G->LeastNeed[G->Sp]);
	else
		printf("0");
    return 0;
}


/*
	Read the Graph from user input
	input type:
		void
	return type:
		MGraph
*/
MGraph ReadG(){
	int C, N,M;
	int i;
	Station Sp;
	int p,q;
	RoadLength r;
	scanf("%d%d%d%d",&C,&N,&Sp,&M);
	MGraph m;
	m=(MGraph)malloc(sizeof(struct GNode));
	m->Capacity=C;	//set capacity for every station
	m->Nr=M;		//set total number of roads
	m->Ns=N;		//set total number of station
	m->Sp=Sp;		//set problem station

	/*
		Set current bikes and least needed bike for each station,
		the latter is initialized to be Infinity, except for PBMC, which should be 0
	*/
	for(i=1;i<=N;i++){
		scanf("%d",&(m->CurrentNums[i]));
		m->LeastNeed[i]=INFINITY;
	}
	m->LeastNeed[PBMC]=0;
	
	for(i=0;i<M;i++){		//set road's length
		scanf("%d%d%d",&p,&q,&r);
		m->R[p][q]=r;
		m->R[q][p]=r;
	}
	return m; 
}


/*
	Find the solution of the problem
	input type:
		G: Mgraph;
		dist: RoadLength[];
		path: Station[];
	return type:
		void  
*/
void Solution(MGraph G, RoadLength dist[], Station path[]){
	int i;
	bool checked[G->Ns];
	int smallest_dist;
	int p;
	
	/*
		All stations are unchecked at first
		All stations are initialized to be infinity
		paths means last station, and are set to be -1,except for PBMC, which should be 0
	*/
	for(i=0;i<=G->Ns;i++){
		dist[i]=INFINITY;
		path[i]=-1;
		checked[i]=false;
	}
	dist[PBMC]=0;


	while(true){

		smallest_dist=INFINITY; 
		p=INFINITY;

		/*
			Find the nearest unchecked station and label it as checked,
			if not found, break the loop.
		*/
		for(i=0;i<=G->Ns;i++){
			if(!checked[i] && dist[i]<smallest_dist){
				smallest_dist=dist[i];
				p=i;
			}
		}
		if(p==INFINITY)
			break;
		checked[p]=true;

		/*
			Utilize greed algorithm to set path and distance for each station
		*/
		for(i=0;i<=G->Ns;i++){
			if(!checked[i]&&G->R[p][i]>0){
				//Only change those station which are adjacent to current one and unchecked
				if(G->R[p][i]+dist[p]<dist[i]){
					//Only change distance if it will be shorter.
					dist[i]=G->R[p][i]+dist[p];
					path[i]=p;
					G->LeastNeed[i]=5-G->CurrentNums[i]+G->LeastNeed[p];
				}

				else if(G->R[p][i]+dist[p]==dist[i]){
					//Only if distance is the same, then consider the needed bikes
					if(5-G->CurrentNums[i]+G->LeastNeed[p]<G->LeastNeed[i]&&G->LeastNeed[i]>0){
						// If the current needed bikes are positive, then less is better, even if it lead to a negative velue. 
						dist[i]=G->R[p][i]+dist[p];
						path[i]=p;
						G->LeastNeed[i]=G->Capacity/2-G->CurrentNums[i]+G->LeastNeed[p];
					}
					else if(G->LeastNeed[i]<0&&G->Capacity/2-G->CurrentNums[i]+G->LeastNeed[p]>G->LeastNeed[i]&&G->Capacity/2-G->CurrentNums[i]+G->LeastNeed[p]<=0){//If less bikes to send back
						//It the current needed bike is negative and the new value is no more than 0, than, larger value is better.
						dist[i]=G->R[p][i]+dist[p];
						path[i]=p;
						G->LeastNeed[i]=G->Capacity/2-G->CurrentNums[i]+G->LeastNeed[p];
					}
				}
			}
		}
	}
}
