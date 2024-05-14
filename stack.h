typedef struct {
    int *elems;
    int loglength;
    int alloclength;
} stack;

void StackNew(stack *s);
void StackDispose(stack *s);
void StackPush(stack *s, int value);
int StackPop(stack *s);
int stack_is_empty(stack *s);
