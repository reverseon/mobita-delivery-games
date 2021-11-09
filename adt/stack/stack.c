#include <stdio.h>
#include "stack.h"

void CreateStack(Stack *s) {
    IDX_TOP_STACK(*s) = IDX_UNDEF_STACK;
}
boolean isEmpty(Stack s) {
    return IDX_TOP(s) == IDX_UNDEF_STACK;
}
boolean isFull(Stack s) {
    return IDX_TOP(s) == CAPACITY_STACK - 1;
}
void push(Stack *s, ElTypeSTACK val) {
    IDX_TOP_STACK(*s)++;
    TOP_STACK(*s) = val;
}  
void pop(Stack *s, ElTypeSTACK *val){
    *val = TOP(*s);
    IDX_TOP_STACK(*s)--;
}
