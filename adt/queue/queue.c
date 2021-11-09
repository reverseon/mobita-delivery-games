#include <stdio.h>
#include "queue.h"

void CreateQueue(Queue *q) {
    IDX_HEAD_QUEUE(*q) = IDX_UNDEF_QUEUE;
    IDX_TAIL_QUEUE(*q) = IDX_UNDEF_QUEUE;
}
boolean isEmptyQUEUE(Queue q) {
    return (IDX_HEAD_QUEUE(q) == IDX_UNDEF_QUEUE && IDX_TAIL_QUEUE(q) == IDX_UNDEF_QUEUE);
}
boolean isFullQUEUE(Queue q) {
    return (IDX_HEAD_QUEUE(q) == 0 && IDX_TAIL_QUEUE(q) == CAPACITY_QUEUE-1);
}
int lengthQUEUE(Queue q) {
    int ret = 0;
    if (IDX_HEAD_QUEUE(q) == IDX_UNDEF_QUEUE) {
        ret = 0;
    } else {
        ret = (IDX_TAIL_QUEUE(q) - IDX_HEAD_QUEUE(q) + 1);
    }
    return ret;
}
void enqueue(Queue *q, ElTypeQUEUE val) {
    // FRAGMENTING
    if (IDX_TAIL_QUEUE(*q) == CAPACITY_QUEUE-1 && IDX_HEAD_QUEUE(*q) != 0) {
        int i = 0;
        for (i = IDX_HEAD_QUEUE(*q); i <= IDX_TAIL_QUEUE(*q); i++) {
            q->buffer[i-IDX_HEAD_QUEUE(*q)] = q->buffer[i];
        }
        IDX_TAIL_QUEUE(*q) -= IDX_HEAD_QUEUE(*q);
        IDX_HEAD_QUEUE(*q) = 0; 
    }
    if (isEmptyQUEUE(*q)) { // KOSONG
        IDX_HEAD_QUEUE(*q) = 0;
        IDX_TAIL_QUEUE(*q) = 0;
        TAIL_QUEUE(*q) = val;
    } else {
        IDX_TAIL_QUEUE(*q)++;
        TAIL_QUEUE(*q) = val; 
    }
}
void dequeue(Queue *q, ElTypeQUEUE *val) {
    *val = q->buffer[IDX_HEAD_QUEUE(*q)];
    if (lengthQUEUE(*q) == 1) {
        IDX_TAIL_QUEUE(*q) = IDX_UNDEF_QUEUE;
        IDX_HEAD_QUEUE(*q) = IDX_UNDEF_QUEUE; // KOSONG
    } else {
        IDX_HEAD_QUEUE(*q)++;
    }
}
void displayQueue(Queue q) {
    if (IDX_HEAD_QUEUE(q) == IDX_UNDEF_QUEUE) {
        printf("[]");
    }
    else {
        printf("[%i", q.buffer[IDX_HEAD_QUEUE(q)]);
        int i = IDX_HEAD_QUEUE(q)+1;
        while (i <= IDX_TAIL_QUEUE(q)) {
            printf(",%i", q.buffer[i]);
            i++;
        }
        printf("]");
    }
}