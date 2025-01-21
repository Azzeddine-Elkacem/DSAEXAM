#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Function to reverse a doubly linked list
void reverseDoublyLinkedList(Node** head) {
    // Check if the list is empty
    if (isListEmpty(*head)) {
        return; // Nothing to reverse
    }

    Node* current = *head;
    Node* temp = NULL;

    // Traverse the list and swap the next and prev pointers for each node
    while (current != NULL) {
        temp = getNext(current);       // Store the next node
        setNext(current, getPrev(current)); // Swap next with prev
        setPrev(current, temp);       // Swap prev with next
        current = getPrev(current);   // Move to the next node (which was prev)
    }

    // Update the head to the new first node
    if (temp != NULL) {
        *head = temp->prev;
    }
}
