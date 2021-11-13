#include <stdio.h>
#include "tas.h"

void CreateTas(Tas *s) {
    IDX_TOP_STACK(*s) = IDX_UNDEF_STACK;
}
boolean isEmpty(Tas s) {
    return IDX_TOP_STACK(s) == IDX_UNDEF_STACK;
}
boolean isFull(Tas s) {
    return IDX_TOP_STACK(s) == CAPACITY_STACK - 1;
}
void pushTas(Tas *s, ElTypeTas val) {
    IDX_TOP_STACK(*s)++;
    TOP_STACK(*s) = val;
}  
void popTas(Tas *s, ElTypeTas *val){
    *val = TOP_STACK(*s);
    IDX_TOP_STACK(*s)--;
}
