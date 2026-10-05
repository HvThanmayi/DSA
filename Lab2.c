#include<stdio.h>
#include<ctype.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char c)
{
    stack[++top]=c;
}
char pop()
{
    return stack[top--];
}
int precedence(char c)
{
    if(c=='*' || c=='/')
        return 2;
    else if(c=='+' || c=='-')
        return 1;
    else
        return 0;
}
int main()
{
    char infix[MAX], postfix[MAX];
    int i=0,j=0;
    printf("Enter an infix expression: ");
    scanf("%s",infix);
    while(infix[i]!='\0')
    {
        if(isalnum(infix[i]))
            postfix[j++]=infix[i];
        else if(infix[i]=='(')
            push(infix[i]);
        else if(infix[i]==')')
        {
            while(top!=-1 && stack[top]!='(')
                postfix[j++]=pop();
            if(top!=-1 && stack[top]=='(')
                pop();
        }
        else
        {
            while(top!=-1 && precedence(stack[top])>=precedence(infix[i]))
                postfix[j++]=pop();
            push(infix[i]);
        }
        i++;
    }
    while(top!=-1)
        postfix[j++]=pop();
    postfix[j]='\0';
    printf("Postfix expression: %s\n",postfix);
    return 0;
}