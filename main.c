#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "stack.h"

// Function prototypes
int readConvert(char[]);
void printPostfix(char[], int);
double evaluatePostfix(char[], int);
int precedence(char token);
char getToken(void);

int main() {
    char post[50];
    int n = readConvert(post);  // Convert infix to postfix
    printPostfix(post, n);      // Print the postfix expression
    double result = evaluatePostfix(post, n);  // Evaluate the postfix expression
    printf("Result: %f\n", result);  // Print the result of the evaluation
    return 0;
}

char getToken(void) {
    char token = getchar();  // Read a single character from the input
    return token;
}
// Function to read and convert infix expression to postfix
int readConvert(char post[]) {
    char getToken(void), token, c;
    int precedence(char);
    StackData temp;
    int h = 0;
    Stack S = initStack();
    printf("Type an infix expression and press Enter\n");
    token = getToken();
    while (token != '\n') {
        if (isdigit(token)) {
            post[h++] = token;  // If it's a digit, add it to postfix
        } else if (token == '(') {
            temp.ch = token;
            push(&S, temp);  // Push '(' to the stack
        } else if (token == ')') {
            while ((c = pop(&S).ch) != '(') {
                post[h++] = c;  // Pop until '(' is found
            }
        } else {  // Handle operators and functions
            while (!empty(S) && precedence(peek(S).ch) >= precedence(token)) {
                post[h++] = pop(&S).ch;
            }
            temp.ch = token;
            push(&S, temp);  // Push current operator
        }
        token = getToken();
    }
    while (!empty(S)) {
        post[h++] = pop(&S).ch;  // Pop remaining operators
    }
    return h;  // Return the length of the postfix expression
}

// Function to get the precedence of operators
int precedence(char token) {
    switch (token) {
        case '+':
        case '-': return 1;
        case '*':
        case '/':
        case '%': return 2;
        case '^': return 3;
        case 's':  // sin
        case 'c':  // cos
        case 't':  // tan
        case 'l':  // log
        case 'r':  // sqrt
        case 'e':  // exp
            return 4;  // Highest precedence for functions
        default: return 0;
    }
}

// Function to print the postfix expression
void printPostfix(char post[], int n) {
    printf("\nThe postfix form is:\n");
    for (int h = 0; h < n; h++) {
        printf("%c ", post[h]);
    }
    printf("\n");
}

// Function to evaluate the postfix expression
double evaluatePostfix(char post[], int n) {
    Stack S = initStack();
    StackData temp;
    double operand1, operand2, result;

    for (int i = 0; i < n; i++) {
        char token = post[i];
        if (isdigit(token)) {
            // Push the numeric value onto the stack
            push(&S, (StackData){.ch = token - '0'});  // Convert char to int
        } else if (token == '+') {
            operand2 = pop(&S).ch;
            operand1 = pop(&S).ch;
            result = operand1 + operand2;
            push(&S, (StackData){.ch = result});
        } else if (token == '-') {
            operand2 = pop(&S).ch;
            operand1 = pop(&S).ch;
            result = operand1 - operand2;
            push(&S, (StackData){.ch = result});
        } else if (token == '*') {
            operand2 = pop(&S).ch;
            operand1 = pop(&S).ch;
            result = operand1 * operand2;
            push(&S, (StackData){.ch = result});
        } else if (token == '/') {
            operand2 = pop(&S).ch;
            operand1 = pop(&S).ch;
            result = operand1 / operand2;
            push(&S, (StackData){.ch = result});
        } else if (token == '%') {
            operand2 = pop(&S).ch;
            operand1 = pop(&S).ch;
            result = fmod(operand1, operand2);  // Modulus
            push(&S, (StackData){.ch = result});
        } else if (token == '^') {
            operand2 = pop(&S).ch;
            operand1 = pop(&S).ch;
            result = pow(operand1, operand2);  // Exponentiation
            push(&S, (StackData){.ch = result});
        }
    }

    // The final result should be the only element left on the stack
    return pop(&S).ch;
}
