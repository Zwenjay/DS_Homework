#include <stdio.h>
#include <stdlib.h>

void Exchange(int L[], int a, int b){
	int temp=L[a];
	L[a]=L[b];
	L[b]=temp;
}

void QuickSort(int a[], int N){
	int pivot,i,j,key;
	for(i=0;i<N;i++)
		printf("%d ",a[i]);
	printf("\n");
	if(N<=1)
		return;
	if(N==2){
		if(a[0]<a[1])
			return;
		else{
			Exchange(a,0,1);
			return;
		}
	}
	if((a[0]>a[N/2]&&a[0]<a[N-1])||(a[0]<a[N/2]&&a[0]>a[N-1]))
		pivot=0;
	else if((a[N/2]>a[0]&&a[N/2]<a[N-1])||(a[N/2]<a[0]&&a[N/2]>a[N-1]))
		pivot=N/2;
	else
		pivot=N-1;
	key=a[pivot];
	Exchange(a,N-1,pivot);
	i=0;
	j=N-2;
	while(i<j){
		if(a[i]>key&&a[j]<key){
			Exchange(a,i,j);
		}
		if(a[i]<=key)
			i++;
		if(i==j)
			break;
		if(a[j]>=key){
			j--;
		}
	}
	Exchange(a,j,N-1);
	QuickSort(a,j);
	QuickSort(a+j+1,N-j-1);
}

int main(){
	int a[7]={3,4,1,6,7,5,2};
	int i;
	QuickSort(a,7);
	for(i=0;i<7;i++)
		printf("%d ",a[i]);
	return 0;
}
