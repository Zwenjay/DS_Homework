#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <ctype.h>  
typedef double ElementType;
#define Infinity 1e8
#define Max_Expr 30   /* max size of expression */

ElementType EvalPostfix( char *expr );
double calculate(double number1,double number2,char ch)  ;
int main()
{
    ElementType v;
    char expr[Max_Expr];
    gets(xpr);
    v = EvalPostfix( expr );
    if ( v < Infinity )
        printf("%f\n", v);
    else
        printf("ERROR\n");
    return 0;
}

double calculate(double number1,double number2,char ch)  
{  
    if(ch=='+')  
      return number1+number2;  
    else if(ch=='-')  
      return number2-number1;  
    else if(ch=='*')  
      return number1*number2;  
    else{  
        return number2/number1;  
    }  
  
}  


ElementType EvalPostfix( char *expr )
{
	double result = 0;
	double number[100];
	int top =-1;
	int start = -1;//操作数开始的下标 
	
	//输入直接为单独一个操作数 
	int flag = 0;
	for (int j=0; expr[j];j++)//go through the expression and check the wrong word
	{
		if(j==0)
		{
			if(expr[j]!='-'&&!isdigit(expr[j]))flag = 1;//error
		}
		else if(expr[j]!='.'&&!isdigit(expr[j]))flag = 1;//error
	}
	if(!flag)
		return atof(expr);
	
	//regulation process
	for(int i=0;expr[i];i++)
	{
		if((expr[i]=='+'||expr[i]=='-'||expr[i]=='*'||expr[i]=='/')&&(expr[i+1]==' '||expr[i+1]=='\0'))//there is an operator
		{      // \0 means the end of string  
			if(top<1)
				return(double)Infinity;
			double number1 = number [top--];
			double number2 = number [top--];
			result = calculate (number1,number2, expr[i]);
			if(result>=Infinity)
				return(double) Infinity;
			number[++top]=result;
		}
		else if(expr[i]!=' '&&start == -1)//there is a new operation number
			start= i;
		else if(expr[i]==' ') //there is a space enter
		{
			expr[i]='\0';//define the space enter as \0, so we can transfer a string to a double
			if(isdigit(expr[i-1]))//当前操作数到结束位置 ,means the end of an operand
			{
				double temp=atof(expr+start);
				number[++top]=temp;
				start = -1;//存完当前操作数，重置start，以读取下一操作数 
			}
			
		}
		else if (strchr("0123456789.+-*/",expr[i]==NULL)) 
			return(double)Infinity;
	}
	
	//最后出现的不是运算符，而为操作数
	if(start!=-1)
		return(double) Infinity;
	//最后栈内剩余多个操作数
	if(top!=0)	
		return(double) Infinity;
	//栈头即为结果
	return	number[0]; 
 } 
 

 
 
 
 
 
 
 
 
 
 
 
 
 
