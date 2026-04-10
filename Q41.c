/*Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
    q->size = 0;
}

void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->size == 0) {
        q->front = q->rear = newNode; // If queue is empty, front and rear point to new node
    } else {
        q->rear->next = newNode; // Link old rear to new node
        q->rear = newNode; // Update rear to new node
    }
    q->size++;
}

void dequeue(Queue* q) {
    if (q->size == 0) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = q->front;
    q->front = q->front->next; // Move front to next node
    free(temp); // Free old front node
    q->size--;
    if (q->size == 0) {
        q->rear = NULL; // If queue becomes empty, rear should also be NULL
    }
}


int main() {
    Queue q;
    initQueue(&q);
    int N, value;
    char operation[10];

    printf("Enter number of operations: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        printf("Enter operation (enqueue x / dequeue): ");
        scanf("%s", operation);
        if (strcmp(operation, "enqueue") == 0) {
            scanf("%d", &value);
            enqueue(&q, value);
        } else if (strcmp(operation, "dequeue") == 0) {
            dequeue(&q);
        } else {
            printf("Invalid operation\n");
        }
    }

    return 0;
}

