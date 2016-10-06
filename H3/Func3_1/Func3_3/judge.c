#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define ERROR 1e5
typedef enum { push, pop, inject, eject, end } Operation;

typedef struct Node *PtrToNode;

struct Node {
	ElementType Element;
	PtrToNode Next, Last;
};

typedef struct DequeRecord *Deque;

struct DequeRecord {
	PtrToNode Front, Rear;
};

Deque CreateDeque();
int Push(ElementType X, Deque D);
ElementType Pop(Deque D);
int Inject(ElementType X, Deque D);
ElementType Eject(Deque D);

Operation GetOp();          /* details omitted */
void PrintDeque(Deque D); /* details omitted */

int main()
{
	ElementType X;
	Deque D;
	int done = 0;
	D = CreateDeque();
	while (!done) {

 		switch (GetOp()) {
		case push:
			scanf_s("%d", &X);
			if (!Push(X, D)) printf("Memory is Full!\n");
			break;
		case pop:
			X = Pop(D);
			if (X == ERROR) printf("Deque is Empty!\n");
			break;
		case inject:
			scanf_s("%d", &X);
			if (!Inject(X, D)) printf("Memory is Full!\n");
			break;
		case eject:
			X = Eject(D);
			if (X == ERROR) printf("Deque is Empty!\n");
			break;
		case end:
			PrintDeque(D);
			done = 1;
			break;
		}
	}
	system("pause");
	return 0;
}

Deque CreateDeque(){
	Deque D;
	PtrToNode N;
	D=(Deque)malloc(sizeof(struct Node));
	N = (PtrToNode)malloc(sizeof(struct Node));
	N->Last = N;
	N->Element = NULL;
	N->Next = N;
	D->Front = N;
	D->Rear = N;
	return D;
}

int Push(ElementType X, Deque D){
	PtrToNode N, tempN, header;
	header = D->Front;
	tempN = header->Next;
	if ((N = (PtrToNode)malloc(sizeof(struct Node))) == NULL)
		return 0;
	N->Element = X;
	header->Next = N;
	N->Last = header;
	N->Next = tempN;
	tempN->Last = N;
	if (D->Rear == D->Front)
		D->Rear = N;
	return 1;
}


ElementType Pop(Deque D){
	ElementType result;
	if (D->Front->Next->Element == NULL)
		return ERROR;
	if (D->Front->Next == D->Rear){
		D->Rear = D->Front;
	}
	result = D->Front->Next->Element;
	D->Front->Next->Next->Last = D->Front;
	D->Front->Next = D->Front->Next->Next;
	
	return result;
}

int Inject(ElementType X, Deque D){
	PtrToNode N, tempN;
	tempN = D->Rear;
	if ((N = (PtrToNode)malloc(sizeof(struct Node))) == NULL)
		return 0;

	D->Rear = N;
	N->Element = X;

	N->Last = tempN;
	tempN->Next->Last = N;
	N->Next = tempN->Next;
	tempN->Next = N;

	return 1;
}

ElementType Eject(Deque D){
	ElementType result;
	if (D->Rear->Element == NULL)
		return ERROR;
	result = D->Rear->Element;

	D->Rear->Next->Last = D->Rear->Last;
	D->Rear->Last->Next = D->Rear->Next;
	D->Rear = D->Rear->Last;
	return result;
}

Operation GetOp(){
	int num;
	scanf_s("%d", &num);
	switch (num)
	{
	case 1:
		return push;
	case 2:
		return pop;
	case 3:		
		return inject;
	case 4:
		return eject;
	case 5:
		return end;
		break;
	}
}

void PrintDeque(Deque D){
	PtrToNode header = D->Front;
	PtrToNode p = header->Next;
	while (p->Element!=0){
		printf("\n%d\n", p->Element);
		p = p->Next;
	}
}