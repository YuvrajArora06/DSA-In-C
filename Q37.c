/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int size;
} PriorityQueue;

void initQueue(PriorityQueue* pq) {
    pq->size = 0;
}

void insert(PriorityQueue* pq, int value) {
    if (pq->size == MAX_SIZE) {
        printf("Priority Queue is full\n");
        return;
    }
    pq->data[pq->size++] = value; // Insert at the end
}

void delete(PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty\n");
        return;
    }
    // Find the index of the element with the highest priority (smallest value)
    int minIndex = 0;
    for (int i = 1; i < pq->size; i++) {
        if (pq->data[i] < pq->data[minIndex]) {
            minIndex = i;
        }
    }
    // Shift elements to fill the gap
    for (int i = minIndex; i < pq->size - 1; i++) {
        pq->data[i] = pq->data[i + 1];
    }
    pq->size--; // Decrease size after deletion
}

void peek(PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty\n");
        return;
    }
    // Find the element with the highest priority (smallest value)
    int minValue = pq->data[0];
    for (int i = 1; i < pq->size; i++) {
        if (pq->data[i] < minValue) {
            minValue = pq->data[i];
        }
    }
    printf("%d\n", minValue); // Print the element with the highest priority
}

int main() {
    PriorityQueue pq;
    initQueue(&pq);

    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char operation[10];
        scanf("%s", operation);
        if (strcmp(operation, "insert") == 0) {
            int value;
            scanf("%d", &value);
            insert(&pq, value);
        } else if (strcmp(operation, "delete") == 0) {
            delete(&pq);
        } else if (strcmp(operation, "peek") == 0) {
            peek(&pq);
        }
    }
    return 0;
}
