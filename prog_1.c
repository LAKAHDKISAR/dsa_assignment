#include <stdio.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char ch)
{
    top++;
    stack[top] = ch;
}

char pop() 
{
    char item;
    if (top == -1) {
        printf("Stack Underflow"); //when empty
        exit(1);
    }
    item = stack[top];
    top--;
    return item;
}

int isEmpty() // using function for isEmpty
{
    if (top == -1) {
        return 1;
    }
    else {
        return 0;
    }
        
}

int checking_if_balance_or_not(char expr[]) 
{
    int i;
    char temp;

    top = -1;   // making the stack empty before checking the balance of the expression

    for (i = 0; i < strlen(expr); i++) {

        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
            push(expr[i]);     // push opening bracket
        }

        if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}') {

            if (isEmpty())
                return 0;

            temp = pop();     // popping last opening bracket

            if (expr[i] == ')' && temp != '(')return 0;
            if (expr[i] == ']' && temp != '[')return 0;
            if (expr[i] == '}' && temp != '{')return 0;
        }
    }

    if (isEmpty())
        return 1;
    else
        return 0;
}

int main() {
    char expr[100];

    printf("Enter a mathematical expression: ");
    fgets(expr, 100, stdin);

    if (checking_if_balance_or_not(expr))
        printf("Expression is Balanced\n");
    else
        printf("Expression is Not Balanced\n");

    return 0;
}
