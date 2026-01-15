//a
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
void push(int item);
int pop();
int i, top = -1;
int op1, op2, res, s[20];
char postfix[90], symb;
void push(int item)
{
 top = top+1;
 s[top] = item;
}
int pop()
{
 int item;
 item = s[top];
 top = top-1;
 return item;
}
void main()
{
 printf("\nEnter a valid postfix expression:\n");
 scanf("%s", postfix);
 for(i=0; postfix[i]!='\0'; i++)
 {
 symb = postfix[i];
 if(isdigit(symb))
 {
 push(symb - '0');
 }
 else
 {
 op2 = pop();
 op1 = pop();
 switch(symb)
 {
 case '+': push(op1+op2);
 break;
     case '-': push(op1-op2);
 break;
 case '*': push(op1*op2);
 break;
 case '/': push(op1/op2);
 break;
 case '%': push(op1%op2);
 break;
 case '$':
 case '^': push(pow(op1, op2));
 break;
 default : push(0);
 }
 }
 }
 res = pop();
 printf("\n Result = %d", res);
 }

//b
#include<stdio.h>
#include<stdlib.h>
void towerOfHanoi(int n,char fromtower,char totower,char auxtower){
if(n==1){
    printf("\nMove disc 1 from tower %c to tower %c ",fromtower,totower);
    return;
}
towerOfHanoi(n-1,fromtower,auxtower,totower);
printf("\nmove disc %d from tower %c to tower %c",n,fromtower,totower);
towerOfHanoi(n-1,auxtower,totower,fromtower);
}
int main(){
    int n;
    printf("\nenter the no. of disks\n");
    scanf("%d",&n);
    printf("\nthe steps to be performed\n");
    towerOfHanoi(n,'a','b','c');
}


