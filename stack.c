#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Function to initialize a stack
Stack initStack(void) {
    Stack S;
    S.top = NULL;  // Start with an empty stack (no nodes)
    return S;
}

// Function to check if the stack is empty
int empty(Stack S) {
    return S.top == NULL;  // Return 1 if stack is empty, else 0
}

// Function to push data onto the stack
void push(Stack* S, StackData d) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Allocate memory for new node
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);  // Exit if memory allocation fails
    }
    newNode->data = d;
    newNode->next = S->top;  // New node's next points to the current top
    S->top = newNode;  // The new node is now the top
}

// Function to pop data from the stack
StackData pop(Stack* S) {
    if (empty(*S)) {
        printf("Stack underflow!\n");
        exit(1);  // Exit if trying to pop from an empty stack
    }
    Node* temp = S->top;  // Store the top node
    StackData poppedData = temp->data;  // Store the data from the top node
    S->top = S->top->next;  // Move the top pointer to the next node
    free(temp);  // Free memory of the popped node
    return poppedData;
}

// Function to peek at the top of the stack without popping
StackData peek(Stack S) {
    if (empty(S)) {
        printf("Stack is empty!\n");
        exit(1);  // Exit if trying to peek an empty stack
    }
    return S.top->data;  // Return the data at the top of the stack
}

// Function to free all memory used by the stack
void freeStack(Stack* S) {
    while (!empty(*S)) {
        pop(S);  // Pop all elements to free memory
    }
}