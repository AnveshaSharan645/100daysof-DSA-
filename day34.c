/*
Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands,
push result back. Final stack top is result.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

void push(int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main() {
    int a, b, result;
    char token;

    while (scanf("%c", &token) != EOF) {

        if (isdigit(token)) {
            push(token - '0');
        }

        else if (token == '+' || token == '-' || token == '*' || token == '/') {

            b = pop();
            a = pop();

            switch (token) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(result);
        }
    }

    printf("%d", pop());

    return 0;
}