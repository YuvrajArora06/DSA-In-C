/*Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a circular linked list node
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

// Function to insert a node at the end of the circular linked list
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode; // Point to itself to make it circular
        return newNode; // If the list is empty, the new node becomes the head
    }
    struct Node* current = head;
    while (current->next != head) {
        current = current->next; // Traverse to the end of the list
    }
    current->next = newNode; // Link the last node to the new node
    newNode->next = head; // Link the new node back to the head
    return head; // Return the head of the list
}

// Function to traverse the circular linked list and print the elements
void traverseList(struct Node* head) {
    if (head == NULL) {
        return; // If the list is empty, return
    }
    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next; // Move to the next node
    } while (current != head); // Continue until we loop back to the head
}

// Function to free the circular linked list memory
void freeList(struct Node* head) {
    if (head == NULL) {
        return; // If the list is empty, return
    }
    struct Node* current = head;
    do {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    } while (current != head); // Continue until we loop back to the head
}

int main() {
    int n;
    struct Node* head = NULL;

    // Read the number of nodes
    scanf("%d", &n);

    // Read the data for each node and insert into the circular linked list
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        head = insertEnd(head, data);
    }

    // Traverse the circular linked list and print the elements
    traverseList(head);
    printf("\n");

    // Free the memory allocated for the circular linked list
    freeList(head);

    return 0;
}
