#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/*

Notes:

- Top is used to keep track of how many items are in the stack. If a stack is empty, then top will be -1.
    - Popping does nnot actually remove or change the item in the array or Stack, however, by decrementing top
    when peek is called, we will see the value below it, and when push is called, it will be changed.
        - Depending on the application of Stacks used, this implementation may need to be changed. 

*/

struct Stack {
    int top; // Index of most recently pushed item
    unsigned capacity; // Maximum number of items in stack
    int *array; // Array holding items
};


// Function to create a stack of a given capacity. Initializes the size of the stack as zero
struct Stack* createStack(unsigned capacity) {

    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack -> capacity = capacity; 
    stack -> top = -1; // Means array is empty since 0 is the first item
    stack -> array = (int *)malloc(capacity * sizeof(int));

    return stack;
}

// Checks if stack is full
int isFull(struct Stack* stack) {
    return stack -> top == stack -> capacity - 1; // capacity - 1 is the last index of the array, so if it is equal to top then array is full
}

// Checks if stack is empty
int isEmpty(struct Stack* stack) {
    return stack -> top == -1;
}

// Pushes item into stack
void push(struct Stack* stack, int item) {
    if(isFull(stack)) { return; }

    stack -> array[++stack->top] = item;
    printf("%d is Pushed into the stack\n", item);
}

// Removes item from stack
int pop(struct Stack* stack) {
    if(isEmpty(stack)) { return INT_MIN; }

    return stack->array[stack->top--];
}

// Lets you look at top value without removing it ( By decrementing top )
int peek(struct Stack* stack) {
    if(isEmpty(stack)) {return INT_MIN; }

    return stack->array[stack->top];
}

void destroyStack(struct Stack* stack) {
    free(stack -> array);
    free(stack);
}
