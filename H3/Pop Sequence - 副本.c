#include <stdio.h>
#include <stdlib.h>


//Given a stack which can keep M numbers at most
//push N numbers in order and pop randomly
//should tell if a given sequence of numers is a posssible pop sequence of the stack

int main()
{
	int M,N,K;
	scanf("%d%d%d",&M,&N,&K);
	int Stack[M+1];
	Stack[0]=0;
	int i;
	int num,j,flag,now,top;
	for(i=0;i<K;i++){
		flag=1;
		now=1;
		top=0;
		for(j=0;j<N;j++){
			scanf("%d",&num);
			while(flag&&top==0||(Stack[top]!=num&&top<=M)){
				Stack[++top]=now++;
				if(top>M){
					flag=0;
					break;
				}
			}
			if(Stack[top]==num)
				top--;
		}
		if(!flag)
			printf("NO\n");
		else printf("YES\n");
	}
	system("PAUSE"); 
	return 0;
} 

