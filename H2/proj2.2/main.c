#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node {
    ElementType Element;
    Position Next;
};

List Read(); 
void Print( List L ); 
List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

List Read(){
	List h,p;
	h=(List)malloc(sizeof(struct Node));
	int i=0;
	h->Next=NULL;
	p=h;
	int listLength, tempNum;
	scanf("%d",&listLength);
	
	for(i=0; i<listLength;i++){
		scanf("%d",&tempNum);
		p->Next=(List)malloc(sizeof(struct Node));
		p=p->Next;
		p->Element=tempNum;
		p->Next=NULL;
	}
	return h;
}

void Print( List L ){
	List p=L->Next;
	while(p!=NULL){
		printf("%d ", p->Element);
		p=p->Next;
	}
	printf("\n");
}


List Reverse( List L ){
	List p, q, r,h;
	p=L->Next;
	q=p->Next;
	r=NULL;
	h=(List)malloc(sizeof(struct Node));

	while(p!=NULL && p->Next!=NULL){
		q=p->Next;
		p->Next=r;
		r=q->Next;
		q->Next=p;
		p=r;
		r=q;
	}
	if (p==NULL)
			h->Next=r;
	else if(p->Next==NULL)
		{
			h->Next=p;
			p->Next=r;
		}
	*L=*h;
	return h;
}
