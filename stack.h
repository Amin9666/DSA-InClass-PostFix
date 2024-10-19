#ifndef STACK_H
#define STACK_H

// Define the structure to hold the data in the stack
typedef struct {
    double ch;  // Use 'double' to handle both numbers and intermediate results
} StackData;

// Define the stack node structure
typedef struct Node {
    StackData data;
    struct Node* next;
} Node;

// Define the stack structure
typedef struct {
    Node* top;  // Pointer to the top of the stack
} Stack;

// Function prototypes
Stack initStack(void);            // Initialize a stack
int empty(Stack S);               // Check if the stack is empty
void push(Stack* S, StackData d);  // Push data onto the stack
StackData pop(Stack* S);           // Pop data from the stack
StackData peek(Stack S);           // Peek at the top of the stack
void freeStack(Stack* S);          // Free the stack memory

#endif  // STACK_H