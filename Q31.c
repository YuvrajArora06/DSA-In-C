/*Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

Input:
- First line: integer n (number of operations)
- Next n lines: operation type and value (if applicable)
  - 1 value: push value
  - 2: pop
  - 3: display*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100    

// Define the structure for the stack
struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack* s) {
    s->top = -1; // Initialize top to -1 indicating an empty stack
}

// Function to push an element onto the stack
void push(struct Stack* s, int value) {
    if (s->top < MAX_SIZE - 1) { // Check for stack overflow
        s->items[++s->top] = value; // Increment top and add value to stack
    } else {
        printf("Stack overflow\n");
    }
}

// Function to pop an element from the stack
int pop(struct Stack* s) {
    if (s->top >= 0) { // Check for stack underflow
        return s->items[s->top--]; // Return the popped element and decrement top
    } else {
        printf("Stack underflow\n");
        return -1; // Return a default value indicating an error
    }
}

// Function to display the elements in the stack
void display(struct Stack* s) {
    if (s->top >= 0) { // Check if the stack is not empty
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->items[i]); // Print elements from top to bottom
        }
        printf("\n");
    } else {
        printf("Stack is empty\n");
    }
}

int main() {
    struct Stack s;
    initStack(&s); // Initialize the stack

    int n, operation, value;
    scanf("%d", &n); // Read the number of operations

    for (int i = 0; i < n; i++) {
        scanf("%d", &operation); // Read the operation type
        switch (operation) {
            case 1: // Push operation
                scanf("%d", &value); // Read the value to push
                push(&s, value); // Push the value onto the stack
                break;
            case 2: // Pop operation
                pop(&s); // Pop an element from the stack
                break;
            case 3: // Display operation
                display(&s); // Display the elements in the stack
                break;
            default:
                printf("Invalid operation\n");
        }
    }

    return 0;
}


