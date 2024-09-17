#include <stdio.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char ch) 
{
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = ch;
}
char pop() 
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}
int checkBalanced(char exp[]) 
{
    int i;
    char temp;
    for (i = 0; i < strlen(exp); i++) 
    {
        if (exp[i] == '[') 
        {
            push(exp[i]);
        } 
        else if (exp[i] == ']') 
        {
            temp = pop();
            if (temp == -1)
                return 0;
        }
    }
    if (top == -1)
        return 1;
    else
        return 0;
}
int main() 
{
    char expression[MAX];
    printf("Enter an expression: ");
    gets(expression);
    if (checkBalanced(expression))
        printf("Brackets are balanced\n");
    else
        printf("Brackets are not balanced\n");

    return 0;
}
