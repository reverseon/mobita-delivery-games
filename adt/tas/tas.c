#include <stdio.h>
#include "tas.h"

void CreateTas(Tas *s) {
    IDX_TOP_STACK(*s) = IDX_UNDEF_STACK;
}
<<<<<<< HEAD
boolean isEmptyTas(Tas s) {
    return IDX_TOP_STACK(s) == IDX_UNDEF_STACK;
}
boolean isFullTas(Tas s) {
=======
boolean isEmpty(Tas s) {
    return IDX_TOP_STACK(s) == IDX_UNDEF_STACK;
}
boolean isFull(Tas s) {
>>>>>>> 7d58e1bd1b819bed2f7a560b43ac4067d8530fc8
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
<<<<<<< HEAD
/*
void updatePerishable(Tas *s)
{
    Tas temp;
    ElTypeTas sampah,sampahPermanent;
    int idxIn;
    while(!isEmptyTas(*s)){
        popTas(s,&sampah);
        if (sampah.itemtype = 'P' && sampah.timelimit > 0) {
            sampah.timelimit--;
            pushTas(&temp,sampah);
        } else if (sampah.timelimit == 0) {
            popTas(s,&sampahPermanent);
            idxIn=indexOfExpiredPerish(_ListOfProggress,'P');        
            
        } 
    }

    while(!isEmptyTas(temp)) {
        popTas(&temp, &sampah);
        pushTas(s, sampah);
    }
}
*/
=======
>>>>>>> 7d58e1bd1b819bed2f7a560b43ac4067d8530fc8
