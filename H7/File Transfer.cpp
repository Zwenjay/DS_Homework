#include <stdio.h>
#include <stdlib.h>

#include<iostream>
using namespace std;

void Check(int i, int j, int *s){
	int rs1=i, rs2=j;
	while(s[rs1]>=1)
		{
			rs1=s[rs1];
		}
	while(s[rs2]>=1){
		rs2=s[rs2];
	}
	if(rs1==rs2) cout<<"yes\n";
	else cout<<"no\n";
}

void Insert(int i, int j,int *s){
	int d1=0,d2=0;
	int id1=i,id2=j;
	while(s[id1]>=1){
		id1=s[id1];
		}
	while(s[id2]>=1){
		id2=s[id2];
		}
	if(s[id1]>s[id2])
		{
			s[id2]+=s[id1];
			s[id1]=id2;
		}
	else{
		s[id1]+=s[id2]; 
		s[id2]=id1;
	}
}


int main(){
	int n,i=0;
	char line[10];
	char ch;
	int a,b;
	scanf("%d",&n);
	int s[n+1];
	for(i=1;i<n+1;i++)
		s[i]=-1;
	while(1){
		cin>>ch;
		if(ch!='S'){
			cin>>a>>b;
		if(ch=='I'){
			Insert(a,b,s);
			n--;
		}
		else if(ch=='C'){
			Check(a,b,s);
		}
	}
		else if(ch=='S') break;
	}
	if(n>1) cout<<"There are "<<n<<" components.";
	else if(n==1) cout<<"The network is connected.\n";
	return 0;
}
