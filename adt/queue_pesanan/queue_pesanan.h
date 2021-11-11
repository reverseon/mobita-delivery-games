#ifndef SORTED_QUEUE_H
#define SORTED_QUEUE_H

#include "../boolean/boolean.h"
#include "../load/load.h"

typedef struct queue_pesanan queue_pesanan;
struct queue_pesanan{
    jumlahPesanan data;
    queue_pesanan* next;
};

typedef struct {
    queue_pesanan* root;
}sorted_pesanan;

boolean isEmptysorted_pesanan(sorted_pesanan* self);

sorted_pesanan* createsorted_pesanan();

void pushsorted_pesanan(sorted_pesanan* self, jumlahPesanan data);

jumlahPesanan popsorted_pesanan(sorted_pesanan* self);

sorted_pesanan* makeSQ(jumlahPesanan* arr, int len);

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
