#ifndef NODE_LL_H
#define NODE_LL_H

#include <stdlib.h>

typedef int ElTypeNODELL;
typedef struct nodeLL* AddressNODELL;
typedef struct nodeLL {
    ElTypeNODELL info;
    AddressNODELL next;
} NodeLL;

#define INFONODELL(p) (p)->info
#define NEXTNODELL(p) (p)->next

AddressNODELL newNode(ElTypeNODELL val);


#endif