#include <stdio.h>
#include <stdlib.h>

typedef struct Node * PtrtoNode;
typedef PtrtoNode Set;
struct Node{
	int Element;
	Set Next;
}; 

void Check(char a, char b, Set* s){
	int i=a-'1';
	int j=b-'1';
	Set temp1[10];
	Set temp2[10];
	int id1=0,id2=0,k;
	int rs1,rs2;
	Set p;
	p=s[i];
	while(p->Next!=NULL)
		{
			temp1[id1++]=p;
			p=p->Next;
		}
		temp1[id1]=p;
	rs1=p->Element;
	p=s[j];
	while(p->Next!=NULL){
		temp2[id2++]=p;
		p=p->Next;
	}
	temp2[id2]=p;
	for(k=0;k<id1;k++){
		temp1[k]->Next=temp1[id1];
	}
	for(k=0;k<id2;k++){
		temp2[k]->Next=temp2[id2];
	}
	rs2=p->Element;
	if(rs1==rs2) printf("yes\n");
	else printf("no\n");
}

void Insert(char a, char b, Set *s){
	int i=a-'1';
	int j=b-'1';
	int d1=0, d2=0;
	Set p,q;
	p=s[i];
	q=s[j];
	while(p->Next!=NULL){
		p=p->Next;
		d1++;
	}
	while(q->Next!=NULL){
		q=q->Next;
		d2++;
		}
	if(d1<d2)
	{
	p->Next=(Set)malloc(sizeof(struct Node));
	p->Next=q;
}else
{
	q->Next=(Set)malloc(sizeof(struct Node));
	q->Next=p;
}
}


int main(){
	int n,i=0;
	Set temps;
	char line[10];
	scanf("%d",&n);
	Set s[n];
	for(i=0;i<n;i++){
		temps=(Set)malloc(sizeof(struct Node));
		temps->Element=i+1;
		temps->Next=NULL;
		s[i]=temps;
	}
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
