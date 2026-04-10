/*Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct MinHeap {
    int data[MAX_SIZE];
    int size;
} MinHeap;

void initMinHeap(MinHeap* heap) {
    heap->size = 0;
}

void insert(MinHeap* heap, int value) {
    if (heap->size == MAX_SIZE) {
        printf("Heap is full\n");
        return;
    }
    heap->data[heap->size] = value;
    heap->size++;
    // Heapify up
    int i = heap->size - 1;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap->data[i] < heap->data[parent]) {
            // Swap
            int temp = heap->data[i];
            heap->data[i] = heap->data[parent];
            heap->data[parent] = temp;
            i = parent;
        } else {
            break;
        }
    }
}


int extractMin(MinHeap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty\n");
        return -1; // Indicating error
    }
    int min = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    // Heapify down
    int i = 0;
    while (i < heap->size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < heap->size && heap->data[left] < heap->data[smallest]) {
            smallest = left;
        }
        if (right < heap->size && heap->data[right] < heap->data[smallest]) {
            smallest = right;
        }
        if (smallest != i) {
            // Swap
            int temp = heap->data[i];
            heap->data[i] = heap->data[smallest];
            heap->data[smallest] = temp;
            i = smallest;
        } else {
            break;
        }
    }
    return min;
}


int peek(MinHeap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty\n");
        return -1; // Indicating error
    }
    return heap->data[0];
}


int main() {
    MinHeap heap;
    initMinHeap(&heap);

    insert(&heap, 5);
    insert(&heap, 3);
    insert(&heap, 8);
    insert(&heap, 1);

    printf("Minimum element: %d\n", peek(&heap)); // Should print 1
    printf("Extracted minimum: %d\n", extractMin(&heap)); // Should print 1
    printf("New minimum after extraction: %d\n", peek(&heap)); // Should print 3

    return 0;
}

