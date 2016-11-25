#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>

void Input(int N);
int Check(int M, int N, int sign, int head, int tail);
int Array[100];

int main(int argc, char *argv[]) {
	int M, N, K;
	cin >> M>>N>>K;
	int i;
	for (i = 0; i<K; i++){
		Input(N);
		int f = Check(M, N, 1, 0, N);
		if (f == 1) printf("YES\n");
		else printf("NO\n");
	}
	system("pause");
	return 0;
}

void Input(int N){
	int i = 0;
	for (i = 0; i < N; i++){
		cin >> Array[i];
	}
}

int Check(int M, int N, int sign, int head, int tail){
	if (head + 1 == tail) return 1;
	if (N == 0) return 1;
	if (M == 1){
		int j, p;
		for (j = head; j < tail-1; j++)
			if (Array[j] > Array[j+1])
				return 0;
		return 1;
	}
	int k;
	for (k = head; k < tail; k++)
		if (Array[k] == sign) break;
	if (k + 1 == tail) tail--;
	int i;
	for (i = head; i < k; i++)
		if (Array[i]>k + sign - head) return 0;
	int left = Check(M - 1, k - head, sign + 1, head, k);
	int right = Check(M, N - (k - head) - 1, k + 2, k + 1, tail);
	return left&&right;
}
