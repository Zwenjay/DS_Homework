#include <stdio.h>
#include <stdlib.h>
#define MaxInt 100

void InsertSort(int Insert[] ,int N,int k);
void OnestepHeapSort(int Heap[], int N, int k);
void OnestepCaompare(int init[], int part[], int N);
void SetHeap(int Heap[], int postion,int N, int length);
void output(int array[], int head,int tail);

int main(){
	int N,i;
	FILE * stream;
	stream=fopen("data2.txt","r");
	fscanf(stream,"%d",&N);
	int a[N],b[N]; 
	for(i=0;i<N;i++)
		fscanf(stream,"%d",&a[i]);
	for(i=0;i<N;i++)
		fscanf(stream,"%d",&b[i]);
	Compare(a,b,N);
	return 0;
} 

void Compare(int init[], int part[], int N){
	int Insert[N], Heap[N+1];
	int i,flag=0;
	int k=0;
	for(i=0;i<N;i++){
		Insert[i]=init[i];
		Heap[i+1]=init[i];
	}
	Heap[0]=1e5;
	for(k=0;k<N;k++){
		OnestepInsertSort(Insert, N,k);
		OnestepHeapSort(Heap,N,k);
		for(i=0;i<N;i++){
			if(part[i]!=Insert[i]){
				flag=0;
				break;
			}
			else
				flag=1;				
		}
		if(flag==1){
			printf("Insertion Sort\n");
			OnestepInsertSort(Insert,N,k+1);
			output(Insert,0,N);
			break;
		}
		for(i=0;i<N;i++){
			if(part[i]!=Heap[i+1]){
				flag=0;
				break;
			}
			else
				flag=1;
		}
		if(flag==1){
			printf("Heap Sort\n");
			OnestepHeapSort(Heap,N,k+1);
			output(Heap,1,N+1);
			break;
		}
	}
}

void OnestepInsertSort(int Insert[], int N, int k){
	int i=0,j, num=Insert[k];
	for(i=0;i<k;i++){
		if(num<Insert[i])
			break;
		}
	for(j=k;j>i;j--){
		Insert[j]=Insert[j-1];
	}
	Insert[i]=num;
}

void OnestepHeapSort(int Heap[], int N,int k){
	int i, max;
	output(Heap,1,N+1);
	if(k==0)
		SetHeap(Heap,1,N,N-k);
	else{
		max=Heap[1];
		Heap[1]=Heap[N-k+1];
		Heap[N-k+1]=max;
		SetHeap(Heap,1,N,N-k);
	}	
}

void SetHeap(int Heap[], int position, int N, int length){
	int temp,children;
	if(position*2>length)
		return;
	if(position*2==length){
		if	(Heap[position]>Heap[length])
			return;
		temp=Heap[position];
		Heap[position]=Heap[length];
		Heap[length]=temp;
		return;
	}
	if(N==length){
		SetHeap(Heap,position*2,N,length);
		SetHeap(Heap,position*2+1,N,length);
	}
	int tempP=position;
	while(tempP<=length/2){
		if(tempP*2+1>length)
			children=tempP*2;
		else
			children=Heap[tempP*2]>Heap[tempP*2+1]?tempP*2:tempP*2+1;
		if(Heap[tempP]<Heap[children]){
			temp=Heap[tempP];
			Heap[tempP]=Heap[children];
			Heap[children]=temp; 
		}
		tempP=children;
	}
}

void output(int array[], int head,int tail){
	int i;
	for(i=head;i<tail-1;i++){
		printf("%d ",array[i]);
	}
	printf("%d\n",array[tail-1]);
}
