#ifndef STACK_H
#define STACK_H

// Define the maximum size of the stack
#define MAX_SIZE 100

// Stack structure definition
typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

// Function prototypes
void initStack(Stack* stack);
int is_empty(const Stack* stack);
int is_full(const Stack* stack);
void push(Stack* stack, char item);
char pop(Stack* stack);
char peek(const Stack* stack);
void clear(Stack* stack);

#endif // STACK_H
