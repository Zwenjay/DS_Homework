#include <stdio.h>
#include <stdlib.h>

typedef double ElementType;
#define Infinity 1e8
#define Max_Expr 30   /* max size of expression */

ElementType EvalPostfix(char *expr);

int main()
{
	ElementType v;
	char expr[Max_Expr];
	gets_s(expr, Max_Expr);
	v = EvalPostfix(expr);
	if (v < Infinity)
		printf("%f\n", v);
	else
		printf("ERROR\n");
	system("pause");
	return 0;
}
ElementType EvalPostfix(char *expr){
	int i = 0;
	int num = 0;
	int sign = 0;
	char *c = expr;
	double Trans[Max_Expr];
	c = expr;
	int k = 0;
	i = 0;
	while (c[i]!='\0'){
		if (c[i] == ' '){
			i++;
			continue;
		}
		if ((c[i] >= '0' && c[i] <= '9')||*c=='.'||(c[i]=='-'&&(c[i+1])>='0'&&(c[i+1])<='9')){
			double temp = 0;
			int flag = 1;
			if (c[i] == '-'){
				flag = -1;
				i++;
			}

			while ( c[i]!= ' ' && c[i]!='.'&&c[i]!='\0'){
				temp = 10 * temp + c[i] - '0';
				i++;
			}
			if (c[i] == '.' && (c[i + 1] > '9' || c[i + 1] < '0')) return Infinity;
			if (c[i] == '.'){
				i++;
				int m = 0;
				int n;
				double point ;
				while (c[i] != ' '&&c[i] != '\0'){
					m++;
					point = c[i]-'0';
					for (n = 0; n < m; n++)
						point = point / 10.0;
					temp = temp+point;
					i++;
				}
			}
			Trans[k] = flag*temp;
			k++;
			num++;
			continue;
		}
		else{
			switch (c[i]){
			case '+':
				k--;
				if (k - 1 < 0) return Infinity;
				Trans[k - 1] = Trans[k - 1] + Trans[k];
				i ++;
				sign++;
				break;
			case '-':
				k--;
				if (k - 1 < 0) return Infinity;
				Trans[k - 1] = Trans[k - 1] - Trans[k];
				i++;
				sign++;
				break;
			case '*':
				k--;
				if (k - 1 < 0) return Infinity;
				Trans[k - 1] = Trans[k - 1] * Trans[k];
				i ++;
				sign++;
				break;
			case '/':
				if (k - 1 < 0) return Infinity;
				if (Trans[k] == 0) return Infinity;
				k--;
				Trans[k - 1] = Trans[k - 1] / Trans[k];
				i ++;
				sign++;
				break;
			default:
				break;
			}
		}
	}
	if (num - 1 != sign) return Infinity;
	return Trans[0];
}
