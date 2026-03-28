#include <stdio.h>
#include <string.h>
#define MAX 100

// Stack implementation
char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        return '\0'; // Empty stack
    }
    return stack[top--];
}

int isMatchingPair(char left, char right) {
    if (left == '(' && right == ')') return 1;
    if (left == '{' && right == '}') return 1;
    if (left == '[' && right == ']') return 1;
    return 0;
}

int checkBalanced(char *expr) {
    for (int i = 0; i < strlen(expr); i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(expr[i]);
        } else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            char popped = pop();
            if (!isMatchingPair(popped, expr[i])) {
                return 0; // Not balanced
            }
        }
    }
    return (top == -1); // Balanced if stack is empty
}

int main() {
    char expr[MAX];
    printf("Enter an expression: ");
    scanf("%s", expr);

    if (checkBalanced(expr)) {
        printf("Balanced Expression\n");
    } else {
        printf("Not Balanced Expression\n");
    }

    return 0;
}