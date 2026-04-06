/*Problem Statement:
Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both 
the front and the rear. It provides more flexibility than a standard queue or stack.

*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Deque {
    Node* front;
    Node* rear;
    int size;
} Deque;

void initDeque(Deque* dq) {
    dq->front = dq->rear = NULL;
    dq->size = 0;
}

void insertFront(Deque* dq, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = dq->front;
    newNode->prev = NULL;

    if (dq->size == 0) {
        dq->rear = newNode; // If deque is empty, rear also points to new node
    } else {
        dq->front->prev = newNode; // Link old front to new node
    }
    dq->front = newNode; // Update front to new node
    dq->size++;
}


void insertRear(Deque* dq, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = dq->rear;

    if (dq->size == 0) {
        dq->front = newNode; // If deque is empty, front also points to new node
    } else {
        dq->rear->next = newNode; // Link old rear to new node
    }
    dq->rear = newNode; // Update rear to new node
    dq->size++;
}

void deleteFront(Deque* dq) {
    if (dq->size == 0) {
        printf("Deque is empty\n");
        return;
    }

    Node* temp = dq->front;
    if (dq->size == 1) {
        dq->front = dq->rear = NULL; // Deque becomes empty
    } else {
        dq->front = dq->front->next; // Move front to next node
        dq->front->prev = NULL; // Update new front's prev to NULL
    }
    free(temp); // Free the dequeued node
    dq->size--;
}

void deleteRear(Deque* dq) {
    if (dq->size == 0) {
        printf("Deque is empty\n");
        return;
    }

    Node* temp = dq->rear;
    if (dq->size == 1) {
        dq->front = dq->rear = NULL; // Deque becomes empty
    } else {
        dq->rear = dq->rear->prev; // Move rear to previous node
        dq->rear->next = NULL; // Update new rear's next to NULL
    }
    free(temp); // Free the dequeued node
    dq->size--;
}

int main() {
    Deque dq;
    initDeque(&dq);

    // Example operations
    insertRear(&dq, 10);
    insertRear(&dq, 20);
    insertFront(&dq, 5);
    deleteFront(&dq);
    deleteRear(&dq);

    return 0;
}


