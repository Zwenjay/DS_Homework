#include<iostream>
using namespace std;

#define MaxVertices 10  /* maximum number of vertices */

typedef struct VNode *PtrToVNode;

class VNode{
	public:
		int v;
		VNode * Next;
};

class Graph{
	public:
		int Nv;
		int Ne;
		VNode * Array[MaxVertices];
		void Init(){
			for(int i=0;i<Nv;i++){
				Array[i]=new VNode;
				Array[i]->v=i;
				Array[i]->Next=NULL;
			}
		}
		void Read(){
			int v1,v2;
			VNode * temp;
			cin>>Nv>>Ne;
			for(int i=0;i<Ne;i++){
				cin>>v1>>v2;
				temp=Array[v1];
				while(temp!=NULL){
					
				}
			}
		}			
};

int main(){
	
	return 0;
}
