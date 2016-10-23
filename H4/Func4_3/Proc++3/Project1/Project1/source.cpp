#include<iostream>
#include<string>
using namespace std;

#define ERROR 1e5

typedef struct TreeNode *Tree;

typedef struct TreeNode{
	int num;
	Tree left;
	Tree right;
};
typedef struct Node *Stack;

struct Node{
	Tree T;
	Stack next;
};

void Push(Stack S, Tree t);
Tree Pop(Stack S);
int IsEmpty(Stack S);
Tree SearchTree(Tree T, Tree t);
void PrintPostTree(Tree tree, Tree root);

int main(){
	string ch;
	int number;
	int i = 0, j;
	Stack S;
	S = (Stack)malloc(sizeof(Node));
	S->next = NULL;
	cin >> number;
	Tree root=(Tree)malloc(sizeof(TreeNode));
	root->left = NULL;
	root->right = NULL;
	Tree lastPop = root;

	for (i = 0; i < 2 * number; i++)
	{
		cin >> ch;
		if (ch == "Push"){
			cin >> j;
			if (i == 0){
				root->num = j;
				Push(S, root);
			}
			else{
				Tree tempT;
				tempT = (Tree)malloc(sizeof(TreeNode));
				tempT->left = NULL;
				tempT->right = NULL;
				tempT->num = j;
				Push(S, tempT);
				if (lastPop->left == NULL) lastPop->left=tempT;
				else if (lastPop->right == NULL) lastPop->right=tempT;
				lastPop = tempT;
			}
		}
		else if (ch == "Pop"){
			Tree ttempTree;
			ttempTree= Pop(S);
			lastPop = SearchTree(root,ttempTree);
		}
	}
	PrintPostTree(root,root);
	system("pause");
	return 0;
}

Tree SearchTree(Tree T,Tree t){
	if (T== t) return T;
	if (T->left!= NULL)
		return SearchTree(T->left,t);
	if (T->right!=NULL)
		return SearchTree(T->right,t);
}

void Push(Stack S, Tree t){
	Stack p = S;
	while (p->next!= NULL)
		p = p->next;
	p->next = (Stack)malloc(sizeof(Node));
	p->next->T = t;
	p->next->next = NULL;
}

Tree Pop(Stack S){
	Stack p = S;
	Tree result=NULL;
	while (p->next->next != NULL)
		p = p->next;
	result = p->next->T;
	p->next = NULL;
	return result;
}


void PrintPostTree(Tree tree, Tree root){
	Tree t = tree;
	if (t->left != NULL)
		PrintPostTree(t->left,root);
	if (t->right != NULL)
		PrintPostTree(t->right,root);
	if (t!=root)
		printf("%d ",t->num);
	else printf("%d", t->num);
}