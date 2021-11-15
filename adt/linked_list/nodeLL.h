#ifndef NODE_LL_H
#define NODE_LL_H

#include <stdlib.h>
typedef struct{
    char pickup;
    char dropoff;
    char itemtype;
    int timelimit;
    int timelimit_original;
}PesananLL;


typedef PesananLL ElTypeNODELL;
typedef struct nodeLL* AddressNODELL;
typedef struct nodeLL {
    ElTypeNODELL info;
    AddressNODELL next;
} NodeLL;

#define INFONODELL(p) (p)->info
#define PICKUPNODELL(p) (p)->info.pickup
#define DROPOFFNODELL(p) (p)->info.dropoff
#define ITEMTYPENODELL(p) (p)->info.itemtype
#define TIMELIMITNODELL(p) (p)->info.timelimit
#define TIMELIMITORIGINAL(p) (p)->info.timelimit_original
#define NEXTNODELL(p) (p)->next

AddressNODELL newNode(ElTypeNODELL val);


#endif