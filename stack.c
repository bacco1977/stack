#include "stack.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

void StackNew(stack *s) {
    s->loglength = 0;
    s->alloclength = 4;
    s->elems = malloc(4 * sizeof(int));
    assert(s->elems != NULL);
}
void StackDispose(stack *s) {
    free(s->elems);
}
void StackPush(stack *s, int value) {
    if (s->loglength == s->alloclength) {
        s->alloclength *= 2;
        s->elems = realloc(s->elems, s->alloclength * sizeof(int));
        assert(s->elems != NULL);
    }
    s->elems[s->loglength] = value;
    s->loglength++;
}
int StackPop(stack *s) {
    assert(s->loglength > 0);
    s->loglength--;
    return s->elems[s->loglength];
}
int stack_is_empty(stack *s) {
    return s->loglength == 0;
}

int main() {
    // Instantiate a stack
    stack stack;
   StackNew(&stack);

    // Push some data onto the stack
    StackPush(&stack, 10);
    StackPush(&stack, 20);
    StackPush(&stack, 30);

    // Print the elements in the stack
    printf("Stack elements: ");
    while (!stack_is_empty(&stack)) {
     printf("%d ",StackPop(&stack));
    }
    printf("\n");



    return 0;
}


