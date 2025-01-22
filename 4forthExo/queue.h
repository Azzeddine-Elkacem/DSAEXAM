#ifndef QUEUE_H
#define QUEUE_H

#define MAX_SIZE 5 // Size of the queue

// Define the Queue struct
typedef struct {
    int queue[MAX_SIZE];  // Array to store queue elements
    int rear;             // Marker for the next insertion point
} Queue;

// Function declarations
void initializeQueue(Queue *q);
int is_empty(Queue *q);
int is_full(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
int peek(Queue *q);

#endif
