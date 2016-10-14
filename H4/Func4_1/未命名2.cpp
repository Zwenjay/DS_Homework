#include <iostream>
using namespace std;
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
	char ch[6];
	int number;
	int i = 0, j;
	scanf("%d", &number);
	for (i = 0; i < 2 * number; i++)
	{
		cin>>ch;
		if (ch[1] == 'u'){
			scanf("%d", &j);
			printf("%d", j);
		}
	}
	system("pause");
	return 0;
}
