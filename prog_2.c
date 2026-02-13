#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX]; // stack for the operators
int top = -1;

// stack operations
void push(char c) { stack[++top] = c; }
char pop() { return (top == -1) ? '\0' : stack[top--]; }
char peek() { return (top == -1) ? '\0' : stack[top]; }
int isEmpty() { return top == -1; }

// Operator precedence
int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

int isOperator(char c) {
    return c=='+' || c=='-' || c=='*' || c=='/';
}

// Converting infix to postfix
void infixToPostfix(char *infix, char *postfix) {
    int i, j=0;
    top = -1;

    for(i=0; i<strlen(infix); i++) {
        char c = infix[i];
        if(c == ' ') continue;

        if(isdigit(c) || isalpha(c)) { // when number or variable
            while(i < strlen(infix) && (isdigit(infix[i]) || isalpha(infix[i])))
                postfix[j++] = infix[i++];
            postfix[j++] = ' '; // for separate numbers
            i--; // adjusting the index
        }
        else if(c == '(') {
            push(c);
        }
        else if(c == ')') {
            while(!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
                postfix[j++] = ' ';
            }
            if(!isEmpty()) pop();
        }
        else if(isOperator(c)) {
            while(!isEmpty() && precedence(peek()) >= precedence(c)) {
                postfix[j++] = pop();
                postfix[j++] = ' ';
            }
            push(c);
        }
    }

    while(!isEmpty()) {
        postfix[j++] = pop();
        postfix[j++] = ' ';
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = 0;

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
