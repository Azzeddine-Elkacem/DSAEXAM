#include <stdio.h>
#include "queue.h"

// Initialize the queue
void initializeQueue(Queue *q) {
    q->rear = 0;  // Set the rear marker to 0 (empty queue)
}

// Check if the queue is empty
int is_empty(Queue *q) {
    return q->rear == 0;  // If rear is 0, the queue is empty
}

// Check if the queue is full
int is_full(Queue *q) {
    return q->rear == MAX_SIZE;  // If rear has reached MAX_SIZE, the queue is full
}

// Enqueue an element
void enqueue(Queue *q, int value) {
    if (is_full(q)) {
        printf("Queue is full, cannot enqueue %d\n", value);
        return;
    }
    q->queue[q->rear] = value;
    q->rear++;  // Move rear marker to the next position
}

// Dequeue an element
int dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty, cannot dequeue\n");
        return -1;
    }

    int value = q->queue[0];  // Get the first element (front of the queue)

    // Shift all elements one position to the left
    for (int i = 0; i < q->rear - 1; i++) {
        q->queue[i] = q->queue[i + 1];
    }

    q->rear--;  // Decrement rear since we've removed one element
    return value;
}

// Peek at the front element
int peek(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty, cannot peek\n");
        return -1;
    }
    return q->queue[0];  // The first element is always at index 0
}
