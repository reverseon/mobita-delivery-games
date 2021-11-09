/* File: node.c */
/* Implementasi Node */

#include "nodeLL.h"
#include <stdlib.h>

AddressNODELL newNode(ElTypeNODELL val) {
    AddressNODELL p = (AddressNODELL) malloc(sizeof(NodeLL));
    if (p!=NULL) {
        INFONODELL(p) = val;
        NEXTNODELL(p) = NULL;
    }
    return p;
}