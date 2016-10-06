#include <stdio.h>
#include <stdlib.h>
#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;

typedef struct StackRecord *Stack;

struct StackRecord  {
	int Capacity;       /* maximum size of the stack array */
	int Top1;           /* top pointer for Stack 1 */
	int Top2;           /* top pointer for Stack 2 */
	ElementType *Array; /* space for the two stacks */
};

Stack CreateStack(int MaxElements);
int IsEmpty(Stack S, int Stacknum);
int IsFull(Stack S);
int Push(ElementType X, Stack S, int Stacknum);
ElementType Top_Pop(Stack S, int Stacknum);

Operation GetOp();  /* details omitted */
void PrintStack(Stack S, int Stacknum); /* details omitted */

int main()
{
	int N, Sn, X;
	Stack S;
	int done = 0;

	scanf_s("%d", &N);
	S = CreateStack(N);
	while (!done) {
		switch (GetOp()) {
		case push:
			scanf_s("%d %d", &Sn, &X);
			if (!Push(X, S, Sn)) printf("Stack %d is Full!\n", Sn);
			break;
		case pop:
			scanf_s("%d", &Sn);
			X = Top_Pop(S, Sn);
			if (X == ERROR) printf("Stack %d is Empty!\n", Sn);
			break;
		case end:
			PrintStack(S, 1);
			PrintStack(S, 2);
			done = 1;
			break;
		}
	}
	return 0;
}

Stack CreateStack(int MaxElements){
	int i = 0;
	int * PtrToInt;
	PtrToInt = (int *)malloc(sizeof(int));
	Stack result;
	result = (Stack)malloc(sizeof(struct StackRecord));
	for (i = 0; i < MaxElements; i++){
		PtrToInt = (int *)malloc(sizeof(int));
		*PtrToInt = NULL;
		PtrToInt++;
	}
	result->Capacity = MaxElements;
	result->Array = PtrToInt;
	result->Top1 = 0;
	result->Top2 = MaxElements-1;
	return result;
}

int IsEmpty(Stack S, int Stacknum)
{
	if ((S->Top1 == 0 && Stacknum == 1) || (S->Top2==S->Capacity-1)&&Stacknum==2)
		return 1;
	return 0;
}

int IsFull(Stack S){
	if (S->Top1-1 == S->Top2)
		return 1;
	return 0;
}

int Push(ElementType X, Stack S, int Stacknum){
	if (IsFull(S))
		return 0;
	if (Stacknum == 1){
		S->Array[S->Top1]=X;
		S->Top1++;
	}
	else{
		S->Array[S->Top2]=X;
		S->Top2--;
	}
	return 1;
}

ElementType Top_Pop(Stack S, int Stacknum){
	if (IsEmpty(S,Stacknum))
		return ERROR;
	int result;
	if (Stacknum == 1){
		S->Top1--;
		result = S->Array[S->Top1];
		S->Array[S->Top1] = NULL;
		return result;
	}
	else{
		S->Top2++;
		result = S->Array[S->Top2];
		S->Array[S->Top2] = NULL;
		return result;
	}
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
		return end;
		break;
	}
}


void PrintStack(Stack S, int Stacknum)
{
	int i;
	printf("1:\n");
	for (i = 0; i < S->Top1; i++)
		printf("%d ", S->Array[i]);
	printf("2:\n");
	for (i = S->Capacity - 1; i>S->Top2; i--)
		printf("%d ", S->Array[i]);
}