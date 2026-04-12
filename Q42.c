/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct Stack {
    int data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

void push(Stack* s, int value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->data[++s->top] = value;
}

int pop(Stack* s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        return -1; // Indicating error
    }
    return s->data[s->top--];
}

int main() {
    Stack s;
    initStack(&s);
    int N, value;
    printf("Enter number of elements: ");
    scanf("%d", &N);
    if (N > MAX_SIZE) {
        printf("Exceeds maximum size\n");
        return 1;
    }
    printf("Enter elements:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &value);
        push(&s, value);
    }
    printf("Reversed queue:\n");
    while (s.top != -1) {
        printf("%d ", pop(&s));
    }
    printf("\n");
    return 0;
}



