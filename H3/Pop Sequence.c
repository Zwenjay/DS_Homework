#include <stdio.h>
#include <stdlib.h>


//Given a stack which can keep M numbers at most
//push N numbers in order and pop randomly
//should tell if a given sequence of numers is a posssible pop sequence of the stack

int main()
{
	int M,N,repeat_time;
	scanf("%d%d%d", &M, &N,&repeat_time);
	int i;
	int stack[M+1];
	for(i=1;i<=repeat_time;i++)
	{
		int top=0;
		int flag=1;
		int now=1;
		int number;
		int j;
		for(j=1;j<=N;j++)
		{
			scanf("%d",&number);
			while(flag&&(top==0||stack[top]!=number))
			{
				stack[++top]=now;
				if(top>M)
				{
					flag=0;
					break;
				}
				now++;
			}
			if(flag&&top>=1&&stack[top]==number)
				top--;
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	system("PAUSE");
	return 0;
}

