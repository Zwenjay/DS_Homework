#include <stdio.h>
#include <stdlib.h>


typedef struct TNode *BinTree;
struct TNode{
	int Key;
	BinTree Left;
	BinTree Right;
};

BinTree BuildTree(); /* details omitted */
int CheckBST(BinTree T, int K);
void MakeTree(BinTree T);

int main()
{
	BinTree T;
	int K, out;

	T = BuildTree();
	scanf_s("%d", &K);
	out = CheckBST(T, K);
	if (out < 0)
		printf("No.  Height = %d\n", -out);
	else
		printf("Yes.  Key = %d\n", out);
	system("pause");
	return 0;
}

BinTree BuildTree(){
	BinTree root=(BinTree)malloc(sizeof(struct TNode));
	root->Left = NULL;
	root->Right = NULL;
	MakeTree(root);
	return root;
}

void MakeTree(BinTree T){
	int l,m, r;
	scanf_s("%d",&l);
	scanf_s("%d", &m);
	scanf_s("%d",&r);
	T->Key = m;
	if (l == 0){
		T->Left = NULL;
	}
	if (r == 0){
		T->Right = NULL;
	}
	if (l == 0 && r == 0) return;
	if (l != 0){
		T->Left = (BinTree)malloc(sizeof(struct TNode));
		MakeTree(T->Left);
	}
	if (r != 0){
		T->Right = (BinTree)malloc(sizeof(struct TNode));
		MakeTree(T->Right);
	}
}

#ifndef __cplusplus
#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))
#endif 

int num[100];
int m = 0;

void Store(BinTree T){
	if (T == NULL) return;
	Store(T->Left);
	num[m++] = T->Key;
	Store(T->Right);
}

int IsBST(BinTree T){
	int j;
	for (j = 0; j < m-1; j++)
		if (num[j]>num[j + 1])
			return 0;
	return 1;
}

int Height(BinTree T){
	if (T == NULL) return 0;
	return (max(Height(T->Left), Height(T->Right)) + 1);
}


int CheckBST(BinTree T, int K){
	Store(T);
	int i = IsBST(T);
	if (!i){
		return Height(T)*(-1);
	}
	else{
		return num[m-K];
	}
}