#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TreeNode *Tree;

struct TreeNode {
	ElementType Element;
	Tree  Left;
	Tree  Right;
};

Tree BuildTree(); /* details omitted */

int Isomorphic(Tree T1, Tree T2);

int main()
{
	Tree T1, T2;
	T1 = BuildTree();
	T2 = BuildTree();
	printf("%d\n", Isomorphic(T1, T2));
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

int Isomorphic(Tree T1, Tree T2){
	if (T1 == NULL&&T2 == NULL) return 1;
	if (T1 == NULL&&T2 != NULL || (T2 == NULL&&T1 != NULL)) return 0;
	if (T1->Element != T2->Element) return 0;
	return (Isomorphic(T1->Left, T2->Left) && Isomorphic(T1->Right, T2->Right)) || (Isomorphic(T1->Right, T2->Left) && Isomorphic(T1->Left, T2->Right));
}