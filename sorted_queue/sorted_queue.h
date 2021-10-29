#ifndef SORTED_QUEUE_H
#define SORTED_QUEUE_H

#include "boolean.h"
#include "../configuration_c/konfigurasi_c.h"

typedef struct SortedQueueNode SortedQueueNode;
struct SortedQueueNode{
    jumlahPesanan data;
    SortedQueueNode* next;
};

typedef struct {
    SortedQueueNode* root;
}SortedQueue;

boolean isEmptySortedQueue(SortedQueue* self);

SortedQueue* createSortedQueue();

void pushSortedQueue(SortedQueue* self, jumlahPesanan data);

jumlahPesanan popSortedQueue(SortedQueue* self);

SortedQueue* makeSQ(jumlahPesanan* arr, int len);

#endif

// 10
// 1 G N N
// 3 G N H
// 2 B M N
// 1 M B H
// 5 C D N
// 3 F E N
// 10 P Q P 20
// 5 G N P 10
// 8 O P V
// 8 Q L V