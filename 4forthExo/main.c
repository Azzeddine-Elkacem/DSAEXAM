#include <stdio.h>
#include "queue.h"

// Stack implementation using a single queue
typedef struct StackSingleQueue {
    Queue q;
} StackSingleQueue;

StackSingleQueue* createStackSingleQueue() {
    StackSingleQueue* stack = (StackSingleQueue*)malloc(sizeof(StackSingleQueue));
    initializeQueue(&stack->q);
    return stack;
}

void pushSingle(StackSingleQueue* stack, int x) {
    enqueue(&stack->q, x);
    int size = stack->q.rear;
    for (int i = 0; i < size - 1; i++) {
        enqueue(&stack->q, dequeue(&stack->q));
    }
}

int popSingle(StackSingleQueue* stack) {
    return dequeue(&stack->q);
}

int peekSingle(StackSingleQueue* stack) {
    return peek(&stack->q);
}

int emptySingle(StackSingleQueue* stack) {
    return is_empty(&stack->q);
}

// Stack implementation using two queues
typedef struct StackTwoQueues {
    Queue q1;
    Queue q2;
} StackTwoQueues;

StackTwoQueues* createStackTwoQueues() {
    StackTwoQueues* stack = (StackTwoQueues*)malloc(sizeof(StackTwoQueues));
    initializeQueue(&stack->q1);
    initializeQueue(&stack->q2);
    return stack;
}

void pushTwo(StackTwoQueues* stack, int x) {
    enqueue(&stack->q2, x);
    while (!is_empty(&stack->q1)) {
        enqueue(&stack->q2, dequeue(&stack->q1));
    }
    Queue temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;
}

int popTwo(StackTwoQueues* stack) {
    return dequeue(&stack->q1);
}

int peekTwo(StackTwoQueues* stack) {
    return peek(&stack->q1);
}

int emptyTwo(StackTwoQueues* stack) {
    return is_empty(&stack->q1);
}

// Main function to demonstrate functionality
int main() {
    printf("Single Queue Approach:\n");
    StackSingleQueue* stack1 = createStackSingleQueue();
    pushSingle(stack1, 10);
    pushSingle(stack1, 20);
    printf("Top: %d\n", peekSingle(stack1));
    printf("Popped: %d\n", popSingle(stack1));
    printf("Empty: %d\n", emptySingle(stack1));

    printf("\nTwo Queues Approach:\n");
    StackTwoQueues* stack2 = createStackTwoQueues();
    pushTwo(stack2, 10);
    pushTwo(stack2, 20);
    printf("Top: %d\n", peekTwo(stack2));
    printf("Popped: %d\n", popTwo(stack2));
    printf("Empty: %d\n", emptyTwo(stack2));

    return 0;
}
