
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include <stdlib.h>
#define MAX 50

typedef struct stack
{
    int stk[MAX];
    int top;
}STACK;
 
void infix_to_prefix(char infix[],char prefix[]);
int isoperand(char );
int isp(char ); 
int icp(char ); 
void init(STACK *);
int empty(STACK *);
int full(STACK *);
int pop(STACK *);
void push(STACK *,int);
int top(STACK *);   


int main()
{
     int i,j; //i-index of infix,j-index of prefix
     STACK s;
     char x,token;
      init(&s);
     
      char infix[30],prefix[30],rev[30];
     printf("Enter the expression : ");
     fgets(infix,30,stdin);
      strrev(infix);
       i=0;
      while( infix[i] != '\0' )
          {
             if(infix[i] == '(')
               infix[i] = ')';
             else if(infix[i] == ')')
               infix[i] = '(';
             else
              infix[i] == infix[i];
              i++;
           }
 
      infix_to_prefix(infix,prefix);
     strrev(prefix);  
   printf("\nprefix expression: %s",prefix);
       return 0;
  }

void infix_to_prefix(char infix[],char prefix[])
{
     STACK s;
      char x,token;
      int i,j;
      init(&s);
      i=0,j=0;
   while(infix[i]!= '\0')
     {
        token=infix[i];
         if(isoperand(token))
                 prefix[j++]=token;
         else if(token=='(')
                 push(&s,'(');
         else if(token==')')
                while((x=pop(&s))!='(')
                      prefix[j++]=x;
         else  
                {
                    while(isp(top(&s)&&!empty(&s)) > icp(token))
                      {
                          x=pop(&s);
                         prefix[j++]=x;
                      }
                    push(&s,token);
                }
        i++;
    }
      while(!empty(&s))
    {
        x=pop(&s);
        prefix[j++]=x;
     }
 
    prefix[j]='\0';
}
   
int isoperand(char z)
 {
    if (z>='A' && z<='Z')
        return 1;
    else if(z>= 'a' && z<='z')
        return 1;
    else
        return 0;
}
int isp(char e)
 {
    if (e=='+' || e=='-')
        return 2;
    else if(e=='*' || e=='/')
        return 4;
    else if(e=='^')
     return 5;
    else if(e=='(')
        return 0;
    else
        return -1; 
}
int icp(char e)
{
    if (e=='+' || e=='-')
        return 1;
    else if(e=='*' || e=='/')
        return 3;
    else if(e=='^')
     return 6;
    else if(e=='(')
        return 9;
    else
        return 1; 
}


void init(STACK *s)
{
    s->top=-1;
}

int empty(STACK *s)
{
    if(s->top==-1)
        return(1);
 
    return(0);
}
 
int full(STACK *s)
{
    if(s->top==MAX-1)
        return(1);
 
    return(0);
}

void push(STACK *s,int x)
{
    s->top=s->top+1;
    s->stk[s->top]=x;
}
 
int pop(STACK *s)
{
    int x;
    x=s->stk[s->top];
    s->top=s->top-1;
    return(x);
}
 
int top(STACK *p)
{
    return (p->stk[p->top]);
}


