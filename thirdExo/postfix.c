#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "stack.h"

#define MAX_EXPR 100

// Function prototypes
int precedence(char op);
int isOperator(char ch);
void infixToPostfix(const char* infix, char* postfix);
int evaluatePostfix(const char* postfix);

int main() {
    char infix[MAX_EXPR], postfix[MAX_EXPR];

    // Ask the user for an infix expression
    printf("Enter an infix expression: ");
    fgets(infix, MAX_EXPR, stdin);
    infix[strcspn(infix, "\n")] = 0;  // Remove the trailing newline character

    // Convert the infix expression to postfix
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    // Evaluate the postfix expression and print the result
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}

// Function to determine the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to check if the character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Function to convert infix expression to postfix
void infixToPostfix(const char* infix, char* postfix) {
    Stack stack;
    initStack(&stack);

    int j = 0; // Index for postfix
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isdigit(ch)) {
            // Append the digit to the postfix expression
            postfix[j++] = ch;
        } else if (ch == '(') {
            // Push '(' onto the stack
            push(&stack, ch);
        } else if (ch == ')') {
            // Pop operators from the stack until '(' is found
            while (!is_empty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack);  // Remove '(' from the stack
        } else if (isOperator(ch)) {
            // Pop operators from the stack with higher or equal precedence
            while (!is_empty(&stack) && precedence(peek(&stack)) >= precedence(ch)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, ch);  // Push the current operator to the stack
        }
    }

    // Pop any remaining operators from the stack
    while (!is_empty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';  // Null-terminate the postfix expression
}

// Function to evaluate the postfix expression
int evaluatePostfix(const char* postfix) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            // Push the operand (converted from char to integer) onto the stack
            push(&stack, ch - '0');
        } else if (isOperator(ch)) {
            // Pop two operands from the stack
            int b = pop(&stack);
            int a = pop(&stack);

            int result = 0;
            // Perform the operation based on the operator
            switch (ch) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            // Push the result of the operation back onto the stack
            push(&stack, result);
        }
    }

    // The final result is the only item left in the stack
    return pop(&stack);
}
