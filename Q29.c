/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode; // If the list is empty, the new node becomes the head
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next; // Traverse to the end of the list
    }
    current->next = newNode; // Link the last node to the new node
    return head; // Return the head of the list
}

// Function to rotate the linked list right by k places
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k <= 0) {
        return head; // If the list is empty, has only one node, or k is non-positive, return the head
    }
    
    // Compute the length of the linked list
    struct Node* current = head;
    int length = 1; // Start with 1 to count the head
    while (current->next != NULL) {
        current = current->next;
        length++;
    }
    
    // Connect the last node to the head to make it circular
    current->next = head;
    
    // Calculate the effective rotations needed
    k = k % length; // If k is greater than length, we only need to rotate k mod length times
    
    // Find the new tail and new head after rotation
    int stepsToNewHead = length - k; // Steps to reach the new head from the current tail
    struct Node* newTail = current; // Start from the current tail
    while (stepsToNewHead > 0) {
        newTail = newTail->next; // Move to the next node
        stepsToNewHead--;
    }
    
    struct Node* newHead = newTail->next; // The new head is the next node after the new tail
    newTail->next = NULL; // Break the circular link to finalize the rotated list
    
    return newHead; // Return the new head of the rotated list
}

// Function to traverse the linked list and print the elements
void traverseList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next; // Move to the next node
    }
}

// Function to free the linked list memory
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int n, k;
    struct Node* head = NULL;

    // Read the number of nodes
    scanf("%d", &n);

    // Read the linked list elements and insert them into the list
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        head = insertEnd(head, data);
    }

    // Read the number of rotations
    scanf("%d", &k);

    // Rotate the linked list right by k places
    head = rotateRight(head, k);

    // Traverse the rotated list and print the elements
    traverseList(head);
    
    // Free the linked list memory
    freeList(head);

    return 0;
}
