#include <stdio.h>
#include <stdlib.h>

#include<iostream>
using namespace std;

void Check(char a, char b, int *s){
	int i=a-'0';
	int j=b-'0';
	int rs1=i, rs2=j;
	while(s[rs1]!=-1)
		{
			rs1=s[rs1];
		}
	while(s[rs2]!=-1){
		rs2=s[rs2];
	}
	if(rs1==rs2) printf("yes\n");
	else printf("no\n");
}

void Insert(char a, char b,int *s){
	int i=a-'0';
	int j=b-'0';
	int id1=i,id2=j;
	int d1=0,d2=0;
	while(s[id1]!=-1){
		id1=s[id1];
		d1++;}
	while(s[id2]!=-1){
		id2=s[id2];
		d2++;}
	if(d1<d2)
		s[id1]=id2;
	else
		s[id2]=id1;
}


int main(){
	int n,i=0;
	char line[10];
	scanf("%d",&n);
	int s[n+1];
	for(i=1;i<n+1;i++)
		s[i]=-1;
	while(1){
		gets(line);
		if(line[0]=='C')
			Check(line[2],line[4],s);
		else if(line[0]=='I'){
			Insert(line[2],line[4],s);
			n--;
		}
		else if(line[0]=='S'&&n!=1)
			{
			printf("There are %d components.",n);
			break;
		}
		else if(line[0]=='S'&&n==1)
			{printf("The network is connected.");
			break;}
	}
	return 0;
}
