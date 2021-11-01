#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include "../configuration_c/konfigurasi_c.h"

typedef struct todoPesanan todoPesanan;
struct todoPesanan
{
    char pickup;
    char dropoff;
    char itemtype;
    int timelimit;
};

typedef todoPesanan TipeEl;
typedef struct nodeListPesanan* AddressTodo;
typedef struct nodeListPesanan {
    TipeEl info;    
    AddressTodo next;
} NodeListPesanan;

#define INFO(p) (p)-> info
#define NEXT(p) (p)->next


AddressTodo newNode(jumlahPesanan val);


#endif