#include <stdio.h>
#include <stdlib.h>

typedef struct Node *Stack;
struct Node{
	int num;
	Stack next;
};
typedef struct TreeNode *Tree;

struct TreeNode{
	int num;
	Tree Left;
	Tree Right;
};

int main(){
	char ch[4];
	int number;
	int i = 0, j;
	scanf_s("%d", &number);
	for (i = 0; i < 2 * number; i++)
	{
		scanf_s("%s", &ch);
		if (ch[1] == 'u'){
			printf("%s", ch);
		}
	}
	system("pause");
	return 0;
}