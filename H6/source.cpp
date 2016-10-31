#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
#define MinData -1

typedef struct HeapStruct *PriorityQueue;
struct HeapStruct {
    ElementType  *Elements;
    int Capacity;
    int Size;
};

PriorityQueue Initialize( int MaxElements ); /* details omitted */

void PercolateUp( int p, PriorityQueue H );
void PercolateDown( int p, PriorityQueue H );

void Insert( ElementType X, PriorityQueue H ) 
{
    int p = ++H->Size;
    H->Elements[p] = X;
    PercolateUp( p, H );
}

ElementType DeleteMin( PriorityQueue H ) 
{ 
    ElementType MinElement; 
    MinElement = H->Elements[1];
    H->Elements[1] = H->Elements[H->Size--];
    PercolateDown( 1, H );
    return MinElement; 
}

int main()
{
    int n, i, op, X;
    PriorityQueue H;
    scanf("%d", &n);
    H = Initialize(n);
    for ( i=0; i<n; i++ ) {
        scanf("%d", &op);
        switch( op ) {
        case 1:
            scanf("%d", &X);
            Insert(X, H);
            break;
        case 0:
            printf("%d ", DeleteMin(H));
            break;
        }
    }
    printf("\nInside H:");
    for ( i=1; i<=H->Size; i++ )
        printf(" %d", H->Elements[i]);
    return 0;
}

PriorityQueue Initialize( int MaxElements ){
	PriorityQueue H;
	H=(PriorityQueue)malloc(sizeof(struct HeapStruct));
	H->Elements=(ElementType *)malloc((MaxElements+1)*sizeof(ElementType));
	H->Capacity=MaxElements;
	H->Size=0;
	H->Elements[0]=MinData;
	return H;
}

void PercolateUp( int p, PriorityQueue H ){
	int i;
	int x=H->Elements[p];
	int temp;
	for(i=p;H->Elements[i/2]>H->Elements[i];i/=2){
		temp=H->Elements[i];
		H->Elements[i]=H->Elements[i/2];
		H->Elements[i/2]=temp;
	}
	H->Elements[i]=x;
}

void PercolateDown( int p, PriorityQueue H ){
	int i,Child;
	int LastElement=H->Elements[1];
	for(i=1;i*2<=H->Size;i=Child){
		LastElement=H->Elements[i];
		Child=2*i;
		if(Child!=H->Size&&H->Elements[Child+1]<H->Elements[Child])
			Child++;
		if(LastElement>H->Elements[Child]){
			H->Elements[i]=H->Elements[Child];
			H->Elements[Child]=LastElement;
		}
		else break; 
	}
}
