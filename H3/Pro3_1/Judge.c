#include <stdio.h>
#include <stdlib.h>

int* Input(int N);
int Check(int M, int N, int* Array, int sign, int head, int tail);

int main(int argc, char *argv[]) {
	int M, N, K;
	scanf_s("%d%d%d", &M, &N, &K);
	int i = 0;
	for (i = 0; i<K; i++){
		int* Array = Input(N);
		int f = Check(M, N, Array, 1, 0, N);
		if (f == 1) printf("YES\n");
		else printf("NO\n");
	}
	system("pause");
	return 0;
}

int* Input(int N){
	int i = 0;
	int * Array, *p;
	Array= (int *)malloc(sizeof(int));
	p = Array;
	for (i = 0; i < N; i++){
		p = (int *)malloc(sizeof(int));
		scanf_s("%d", &Array[i]);
		p++;
}
	return Array;
}

int Check(int M, int N, int* Array, int sign, int head, int tail){
	if (head+1 == tail) return 1;
	if (N==0) return 1;
	if (M == 1){
		int j, p;
		for (j = head; j < tail; j++){
			for (p = j; p < tail; p++){
				if (Array[p] < Array[j]) return 0;
			}
		}
		return 1;
	}
	int k;
	for (k = head; k < tail; k++)
		if (Array[k] == sign) break;
	if (k+1 == tail) tail--;
	int i;
	for (i = head; i < k; i++)
		if(Array[i]>k+sign-head) return 0 ;
	int left=Check(M - 1, k-head, Array, sign + 1, head, k);
	int right = Check(M, N - (k-head) - 1, Array, k + 2, k + 1, tail);
	return left&&right;
}
