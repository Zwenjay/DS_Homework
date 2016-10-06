#include <stdio.h>
#include <stdlib.h>
typedef struct Node *PtrToNode;
struct Node  {
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};
typedef PtrToNode Polynomial;

Polynomial Read();
void Print( Polynomial p );
Polynomial Add( Polynomial a, Polynomial b );

int main()
{
    Polynomial a, b, s;
    a = Read();
    b = Read();
    s = Add(a, b);
    Print(s);
    return 0;
}

Polynomial Read(){
	Polynomial h,p;
	h=(Polynomial)malloc(sizeof(struct Node));
	int i=0;
	h->Next=NULL;
	p=h;
	int listLength, tempNum1, tempNum2;
	scanf("%d",&listLength);
	
	for(i=0; i<listLength;i++){
		scanf("%d%d",&tempNum1,&tempNum2);
		p->Next=(Polynomial)malloc(sizeof(struct Node));
		p=p->Next;
		p->Coefficient=tempNum1;
		p->Exponent=tempNum2;
		p->Next=NULL;
	}
	return h;
}


void Print(Polynomial p){
	Polynomial p1=p->Next;
	while(p1!=NULL){
		printf("%d  %d ",p1->Coefficient,p1->Exponent);
		p1=p1->Next;
	}
	printf("\n");
}

Polynomial Add(Polynomial a, Polynomial b ){
    Polynomial c, pc,pa,pb;
    c=(Polynomial)malloc(sizeof(struct Node));
    c->Next=NULL;
    pc=c;
    pa=a->Next;
    pb=b->Next;
    while(pa!=NULL && pb!=NULL){
    	if (pa->Exponent>pb->Exponent){
    		pc->Next=(Polynomial)malloc(sizeof(struct Node));
    		pc=pc->Next;
    		pc->Exponent=pa->Exponent;
    		pc->Coefficient=pa->Coefficient;
    		pc->Next=NULL;
    		pa=pa->Next;
    	}
    	else if (pa->Exponent==pb->Exponent){
    		if (pa->Coefficient+pb->Coefficient==0)
    		{
    			pa=pa->Next;
    			pb=pb->Next;
    			continue;
    		}
    		pc->Next=(Polynomial)malloc(sizeof(struct Node));
    		pc=pc->Next;
    		pc->Exponent=pa->Exponent;
    		pc->Coefficient=pa->Coefficient+pb->Coefficient;
    		pc->Next=NULL;
    		pa=pa->Next;
    		pb=pb->Next;
    	}
    	else{
    		pc->Next=(Polynomial)malloc(sizeof(struct Node));
    		pc=pc->Next;
    		pc->Exponent=pb->Exponent;
    		pc->Coefficient=pb->Coefficient;
    		pc->Next=NULL;
    		pb=pb->Next;
    	}
    }
        while(pa!=NULL){
    		pc->Next=(Polynomial)malloc(sizeof(struct Node));
    		pc=pc->Next;
    		pc->Exponent=pa->Exponent;
    		pc->Coefficient=pa->Coefficient;
    		pc->Next=NULL;
    		pa=pa->Next;
    	}
    	while(pb!=NULL){
    		pc->Next=(Polynomial)malloc(sizeof(struct Node));
    		pc=pc->Next;
    		pc->Exponent=pb->Exponent;
    		pc->Coefficient=pb->Coefficient;
    		pc->Next=NULL;
    		pb=pb->Next;
    }
    return c;
}
