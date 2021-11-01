/* File: node.c */
/* Implementasi Node */

#include "node.h"
#include <stdlib.h>


AddressTodo newNode(jumlahPesanan val) {
    AddressTodo p = (AddressTodo) malloc(sizeof(NodeListPesanan));

    if (p!=NULL) {
        INFO(p).pickup = val.pickup;
        INFO(p).dropoff = val.dropoff;
        INFO(p).itemtype = val.itemtype;
        INFO(p).timelimit = val.timelimit;
        NEXT(p) = NULL;
    }
    return p;
}