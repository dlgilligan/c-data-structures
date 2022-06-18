#include "stack-funcs.h"

int main () {
    struct Stack * stack = createStack(10);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("%d was Popped from the stack\n",pop(stack));
}

