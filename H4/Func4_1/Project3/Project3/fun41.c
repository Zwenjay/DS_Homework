#include <stdio.h>
#include <stdlib.h>

#define MaxTree 10 /* maximum number of nodes in a tree */
typedef int ElementType;
typedef struct TreeNode *Tree;

typedef struct Node *Queue;

struct TreeNode {
	ElementType Element;
	Tree  Left;
	Tree  Right;
};

struct Node{
	Tree Element;
	Queue Next;
};

Tree BuildTree(); /* details omitted */


Queue BuildQ();
void Push(Queue q, Tree e);
Tree Pop(Queue q);
int IsEmpty(Queue q);


void Level_order(Tree T, void(*visit)(Tree ThisNode)){
	Queue q = BuildQ();
	Push(q, T);
	Tree temp;
	while (IsEmpty(q) == 0){
		temp = Pop(q);
		visit(temp);
		if (temp->Left != NULL) Push(q, temp->Left);
		if (temp->Right != NULL) Push(q, temp->Right);
	}
}

Queue BuildQ(){
	Queue q;
	q = (Queue)malloc(sizeof(struct Node));
	q->Next = NULL;
	return q;
}

void Push(Queue q, Tree tre){
	Queue p = q;
	while (p->Next != NULL)
		p = p->Next;
	p->Next = (Queue)malloc(sizeof(struct Node));
	p->Next->Element = tre;
	p->Next->Next = NULL;
}

Tree Pop(Queue q){
	Tree result = NULL;
	if (IsEmpty(q) == 0){
		result = q->Next->Element;
		Queue p = q->Next->Next;
		q->Next = p;
		return result;
	}
	else return result;
}

int IsEmpty(Queue q){
	if (q->Next == NULL) return 1;
	else return 0;
}

void PrintNode(Tree NodePtr)
{
	printf(" %d", NodePtr->Element);
}

void Level_order(Tree T, void(*visit)(Tree ThisNode));
void PrintNode(Tree ThisNode);

int main()
{
	Tree T = BuildTree();
	printf("Level-order:");
	Level_order(T, PrintNode);
	system("pause");
	return 0;
}

Tree BuildTree(){
	Tree root;
	int l, r, cont;
	scanf_s("%d%d%d", &l, &r, &cont);
	root = (Tree)malloc(sizeof(struct TreeNode));
	root->Element = cont;
	if (l == 1) root->Left = BuildTree();
	else root->Left = NULL;
	if (r == 1) root->Right = BuildTree();
	else root->Right = NULL;
	return root;
}

