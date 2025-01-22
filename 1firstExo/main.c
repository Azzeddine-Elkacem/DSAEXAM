#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Function to insert a new node with a specific value at position k in a linked list
void insertAtPosition(Node** head, int value, int k) {
    // Check if the position is invalid (negative)
    if (k < 0) {
        printf("Error: Position k cannot be negative.\n");
        return;
    }

    // Create a new node with the given value
    Node* newNode = createNode(value);

    // If the position is 0, insert at the head of the list
    if (k == 0) {
        setNext(newNode, *head); // Set the new node's next to the current head
        *head = newNode;         // Update the head to point to the new node
        return;
    }

    // Traverse the list to find the position just before k
    Node* current = *head;
    int position = 0;
    while (current != NULL && position < k - 1) {
        current = getNext(current); // Move to the next node
        position++;
    }

    // If we reached the end of the list before reaching position k-1, it's out of bounds
    if (current == NULL) {
        printf("Error: Position k is out of bounds.\n");
        deleteNode(newNode); // Free the memory allocated for the new node
        return;
    }

    // Insert the new node at the desired position
    setNext(newNode, getNext(current)); // Set the new node's next to current's next
    setNext(current, newNode);          // Link the current node to the new node
}

// Function to print the elements of a linked list
void printList(Node* head) {
    Node* current = head; // Start from the head of the list
    while (current != NULL) {
        printf("%d -> ", getValue(current)); // Print the value of the current node
        current = getNext(current);         // Move to the next node
    }
    printf("NULL\n"); // End the list with NULL to signify the end
}
