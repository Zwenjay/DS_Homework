#include <stdio.h>

#define ElementType int
#define MAXN 100

void merge_pass( ElementType list[], ElementType sorted[], int N, int length );

void output( ElementType list[], int N )
{
    int i;
    for (i=0; i<N; i++) printf("%d ", list[i]);
    printf("\n");
}

void  merge_sort( ElementType list[],  int N )
{
    ElementType extra[MAXN];  /* the extra space required */
    int  length = 1;  /* current length of sublist being merged */
    while( length < N ) { 
        merge_pass( list, extra, N, length ); /* merge list into extra */
        output( extra, N );
        length *= 2;
        merge_pass( extra, list, N, length ); /* merge extra back to list */
        output( list, N );
        length *= 2;
    }
} 


int main()
{
    int N, i;
    ElementType A[MAXN];

    scanf("%d", &N);
    for (i=0; i<N; i++) scanf("%d", &A[i]);
    merge_sort(A, N);
    output(A, N);

    return 0;
}

void merge_pass( ElementType list[], ElementType sorted[], int N, int length ){
	int turns=N/(length*2)+1,i,j,now=0,head,k;
	for(k=0;k<turns;k++){
		i=length*2*k;
		j=i+length;
		while(now<N && i<length*2*k+length && j<length*2*(k+1)&&j<N){
			if(list[i]<list[j])
				sorted[now++]=list[i++];
			else
				sorted[now++]=list[j++];
		}
		if(i==length*2*k+length)
			while(now<N&&j<length*2*(k+1))
				sorted[now++]=list[j++];
		else
			while(now<N&&i<length*2*k+length)
				sorted[now++]=list[i++];
	}
	while(now<N)
		sorted[now]=list[now++];
}
