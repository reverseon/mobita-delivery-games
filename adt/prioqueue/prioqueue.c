#include <stdio.h>
#include "prioqueue.h"

void CreatePrioQueue(PrioQueue *pq) {
    IDX_HEAD_PQ(*pq) = IDX_UNDEF_PQ;
    IDX_TAIL_PQ(*pq) = IDX_UNDEF_PQ;
}
boolean isEmptyPQ(PrioQueue pq) {
    return (IDX_HEAD_PQ(pq) == IDX_UNDEF_PQ && IDX_TAIL_PQ(pq) == IDX_UNDEF_PQ);
}
boolean isFullPQ(PrioQueue pq) {
    return (IDX_HEAD_PQ(pq) == 0 && IDX_TAIL_PQ(pq) == CAPACITY_PQ-1);
}
int lengthPQ(PrioQueue pq) {
    int ret = 0;
    if (isEmptyPQ(pq)) {
        ret = 0;
    } else {
        ret = (IDX_TAIL_PQ(pq) - IDX_HEAD_PQ(pq) + 1);
    }
    return ret;
}
void enqueuePQ(PrioQueue *pq, ElTypePQ val) {
    if (IDX_TAIL_PQ(*pq) == CAPACITY_PQ-1 && IDX_HEAD_PQ(*pq) != 0) {
        int i = 0;
        for (i = IDX_HEAD_PQ(*pq); i <= IDX_TAIL_PQ(*pq); i++) {
            pq->buffer[i-IDX_HEAD_PQ(*pq)] = pq->buffer[i];
        }
        IDX_TAIL_PQ(*pq) -= IDX_HEAD_PQ(*pq);
        IDX_HEAD_PQ(*pq) = 0; 
    }
    if (isEmptyPQ(*pq)) { // KOSONG
        IDX_HEAD_PQ(*pq) = 0;
        IDX_TAIL_PQ(*pq) = 0;
        TAIL_PQ(*pq) = val;
    } else {
        IDX_TAIL_PQ(*pq)++;
        TAIL_PQ(*pq) = val; 
    }
}
void dequeuePQ(PrioQueue * pq, ElTypePQ *val) {
    *val = pq->buffer[IDX_HEAD_PQ(*pq)];
    if (lengthPQ(*pq) == 1) {
        IDX_TAIL_PQ(*pq) = IDX_UNDEF_PQ;
        IDX_HEAD_PQ(*pq) = IDX_UNDEF_PQ; // KOSONG
    } else {
        IDX_HEAD_PQ(*pq)++;
    }
}