#include <stdio.h>
#include "list_linked.h"

void CreateListLL(ListLL *l) {
    FIRSTLL(*l) = NULL;
}
boolean isEmptyLL(ListLL l) {
    return lengthLL(l) == 0;
}
ElTypeNODELL getElmtLL(ListLL l, int idx) {
    AddressNODELL op = FIRSTLL(l);
    int i = 0;
    for (i = 1; i <= idx; i++) {
        op = NEXTNODELL(op);
    }
    return INFONODELL(op);
}
void setElmtLL(ListLL *l, int idx, ElTypeNODELL val) {
    AddressNODELL op = FIRSTLL(*l);
    int i = 0;
    for (i = 1; i <= idx; i++) {
        op = NEXTNODELL(op);
    }
    INFONODELL(op) = val;
} 
int indexOfPickupLL(ListLL l, char val) {
    if (isEmptyLL(l)) {
        return IDX_UNDEF_LL;
    } else {
        AddressNODELL op = FIRSTLL(l);
        boolean found = false;
        int i = 0;
        while (!found && op != NULL) {
            if (PICKUPNODELL(op) == val) {
                found = true;
            } else {
                op = NEXTNODELL(op);
                i++;
            }
        }
        if (op == NULL) {
            return IDX_UNDEF_LL;
        } else {
            return i;
        }
    }
}
int indexOfDropoffLL(ListLL l, char val) {
    if (isEmptyLL(l)) {
        return IDX_UNDEF_LL;
    } else {
        AddressNODELL op = FIRSTLL(l);
        boolean found = false;
        int i = 0;
        while (!found && op != NULL) {
            if (DROPOFFNODELL(op) == val) {
                found = true;
            } else {
                op = NEXTNODELL(op);
                i++;
            }
        }
        if (op == NULL) {
            return IDX_UNDEF_LL;
        } else {
            return i;
        }
    }
}
void insertFirstLL(ListLL *l, ElTypeNODELL val) {
    AddressNODELL na = newNode(val);
    if (isEmptyLL(*l)) {
        FIRSTLL(*l) = na;
    } else {
        NEXTNODELL(na) = FIRSTLL(*l);
        FIRSTLL(*l) = na;
    }
}
void insertLastLL(ListLL *l, ElTypeNODELL val) {
    if (lengthLL(*l) == 0) {
        insertFirstLL(l, val);
    } else {
        AddressNODELL na = newNode(val);
        AddressNODELL op = FIRSTLL(*l);
        int i = 0;
        while(NEXTNODELL(op) != NULL) {
            op = NEXTNODELL(op);
        }
        NEXTNODELL(op) = na;
    }
}
void insertAtLL(ListLL *l, ElTypeNODELL val, int idx) {
    if (idx == 0) {
        insertFirstLL(l, val);
    } else {
        AddressNODELL na = newNode(val);
        AddressNODELL op = FIRSTLL(*l);
        int i = 0;
        for (i = 0; i < idx-1; i++) {
            op = NEXTNODELL(op);
        }
        AddressNODELL temp = NEXTNODELL(op);
        NEXTNODELL(op) = na;
        NEXTNODELL(na) = temp;
    }
}
void deleteFirstLL(ListLL *l, ElTypeNODELL *val) {
    if (!isEmptyLL(*l)) {
        *val = INFONODELL(*l);
        FIRSTLL(*l) = NEXTNODELL(*l);
    }
}
void deleteLastLL(ListLL *l, ElTypeNODELL *val) {
    if(!isEmptyLL(*l)){
        if (lengthLL(*l) == 1) {
            deleteFirstLL(l, val);
        } else {
            AddressNODELL op1 = FIRSTLL(*l);
            AddressNODELL op2 = NEXTNODELL(op1);
            while (NEXTNODELL(op2) != NULL) {
                op1 = op2;
                op2 = NEXTNODELL(op2);
            }
            *val = INFONODELL(op2);
            NEXTNODELL(op1) = NULL;
        }
    }
}
void deleteAtLL(ListLL *l, int idx, ElTypeNODELL *val) {
    if(!isEmptyLL(*l)){
        if (idx == 0) {
            deleteFirstLL(l, val);
        } else {
            AddressNODELL op = FIRSTLL(*l);
            int i = 0;
            for (i = 0; i < idx-1; i++) {
                op = NEXTNODELL(op);
            }
            *val = INFONODELL(NEXTNODELL(op));
            NEXTNODELL(op) = NEXTNODELL(NEXTNODELL(op));
        }
    }
}
void displayListLL(ListLL l) {
    if (lengthLL(l) == 0) {
        printf("[]");
    } else {
        printf("[");
        AddressNODELL op = FIRSTLL(l);
        while (NEXTNODELL(op) != NULL) {
            printf("%c, %c, %c, %d;", PICKUPNODELL(op), DROPOFFNODELL(op), ITEMTYPENODELL(op), TIMELIMITNODELL(op));
            op = NEXTNODELL(op);
        }
        printf("%c, %c, %c, %d", PICKUPNODELL(op), DROPOFFNODELL(op), ITEMTYPENODELL(op), TIMELIMITNODELL(op));
        printf("]");
    }
}
int lengthLL(ListLL l) {
    AddressNODELL op = FIRSTLL(l);
    int i = 0;
    while (op != NULL) {
        op = NEXTNODELL(op);
        i++;
    }
    return i;
}
int indexOfExpiredPerish(ListLL l, char val) {
    if (isEmptyLL(l)) {
        return IDX_UNDEF_LL;
    } else {
        AddressNODELL op = FIRSTLL(l);
        boolean found = false;
        int i = 0;
        while (!found && op != NULL) {
            if (ITEMTYPENODELL(op) == val && (TIMELIMITNODELL(op) == 0)) {
                found = true;
            } else {
                op = NEXTNODELL(op);
                i++;
            }
        }
        if (op == NULL) {
            return IDX_UNDEF_LL;
        } else {
            return i;
        }
    }
}

// boolean fSearchLL(ListLL L, AddressNODELL P) {
//     AddressNODELL op = FIRSTLL(L);
//     while (op != NULL) {
//         if (op == P) {
//             return true;
//         }
//         op = NEXTNODELL(op);
//     }
//     return false;
// }

// AddressNODELL searchPrecLL(ListLL L, ElTypeNODELL X) {
//     if (lengthLL(L) == 0) {
//         return NULL;
//     } else {
//         AddressNODELL op = FIRSTLL(L);
//         AddressNODELL prev = NULL;
//         boolean f = false;
//         while (op != NULL && !f) {
//             if (INFONODELL(op) == X) {
//                 f = true;
//             } else {
//                 prev = op;
//                 op = NEXTNODELL(op);
//             }
//         }
//         if (f) return prev;
//         else return NULL;
//     }
// }

// ElTypeNODELL maxLL(ListLL l) {
//     AddressNODELL op = FIRSTLL(l);
//     int m = INFONODELL(op);
//     while (op != NULL) {
//         if (INFONODELL(op) > m) {
//             m = INFONODELL(op);
//         }
//         op = NEXTNODELL(op);
//     }
//     return m;
// }

// AddressNODELL adrMaxLL(ListLL l) {
//     AddressNODELL op = FIRSTLL(l);
//     AddressNODELL madr = op;
//     while (op != NULL) {
//         if (INFONODELL(op) > INFONODELL(madr)) {
//             madr = op;
//         }
//         op = NEXTNODELL(op);
//     }
//     return madr;
// }

// ElTypeNODELL minLL(ListLL l) {
//     AddressNODELL op = FIRSTLL(l);
//     int m = INFONODELL(op);
//     while (op != NULL) {
//         if (INFONODELL(op) < m) {
//             m = INFONODELL(op);
//         }
//         op = NEXTNODELL(op);
//     }
//     return m;
// }

// AddressNODELL adrMinLL(ListLL l) {
//     AddressNODELL op = FIRSTLL(l);
//     AddressNODELL madr = op;
//     while (op != NULL) {
//         if (INFONODELL(op) < INFONODELL(madr)) {
//             madr = op;
//         }
//         op = NEXTNODELL(op);
//     }
//     return madr;
// }

// float averageLL(ListLL l) {
//     float sum = 0;
//     int i = 0;
//     AddressNODELL op = FIRSTLL(l);
//     while (op != NULL) {
//         sum += INFONODELL(op);
//         op = NEXTNODELL(op);
//         i++;
//     }
//     return sum / i;
// }

// ListLL concatLL(ListLL l1, ListLL l2) {
//     ListLL cl1, cl2;
//     CreateListLL(&cl1);
//     CreateListLL(&cl2);
//     int lenl1 = lengthLL(l1);
//     int lenl2 = lengthLL(l2);
//     int i = 0;
//     for (i = 0; i < lenl1; i++) {
//         insertLastLL(&cl1, getElmtLL(l1, i));
//     }
//     for (i = 0; i < lenl2; i++) {
//         insertLastLL(&cl2, getElmtLL(l2, i));
//     }
//     if (lengthLL(cl2) == 0) {
//         return cl1;
//     } else if (lengthLL(cl1) == 0) {
//         return cl2;
//     } else {
//         ListLL l3 = FIRSTLL(cl1);
//         AddressNODELL op = FIRSTLL(l3);
//         while (NEXTNODELL(op) != NULL) {
//             op = NEXTNODELL(op);
//         }
//         NEXTNODELL(op) = FIRSTLL(cl2);
//         return l3;
//     }
// }

// void delAllLL(ListLL *l) {
//     if (lengthLL(*l) != 0) {
//         AddressNODELL op = FIRSTLL(*l);
//         AddressNODELL nxt = NEXTNODELL(op);
//         while (nxt != NULL) {
//             free(op);
//             op = nxt;
//             nxt = NEXTNODELL(nxt);
//         }
//         free(op);
//     }
//     CreateListLL(l);
// }

// void inverseListLL(ListLL *l) {
//     ListLL ret;
//     CreateListLL(&ret);
//     AddressNODELL op = FIRSTLL(*l);
//     while (op != NULL) {
//         insertFirstLL(&ret, INFONODELL(op));
//         op = NEXTNODELL(op);
//     }
//     delAllLL(l);
//     *l = FIRSTLL(ret);
// }

// ListLL fInverseListLL(ListLL l) {
//     ListLL ret;
//     CreateListLL(&ret);
//     AddressNODELL op = FIRSTLL(l);
//     while (op != NULL) {
//         insertFirstLL(&ret, INFONODELL(op));
//         op = NEXTNODELL(op);
//     }
//     return ret;
// }

// void copyListLL(ListLL *l1, ListLL *l2) {
//     *l2 = *l1;
// }

// ListLL fCopyListLL(ListLL l) {
//     ListLL ret;
//     CreateListLL(&ret);
//     AddressNODELL op = FIRSTLL(l);
//     while (op != NULL) {
//         insertLastLL(&ret, INFONODELL(op));
//         op = NEXTNODELL(op);
//     }
//     return ret;
// }

// void cpAllocListLL(ListLL lIn, ListLL *lOut) {
//     CreateListLL(lOut);
//     *lOut = fCopyListLL(lIn);
// }

// void splitListLL(ListLL *l1, ListLL *l2, ListLL l) {
//     int lenl = lengthLL(l);
//     AddressNODELL op = FIRSTLL(l);
//     CreateListLL(l1);
//     CreateListLL(l2);
//     if (lenl != 0){
//         int lenl1 = lenl / 2;
//         int lenl2 = lenl - lenl1;
//         int i = 0;
//         int j = 0;
//         for (i = 0; i < lenl1; i++) {
//             insertLastLL(l1, INFONODELL(op));
//             op = NEXTNODELL(op);
//         }
//         for (j = 0; j < lenl2; j++) {
//             insertLastLL(l2, INFONODELL(op));
//             op = NEXTNODELL(op);
//         }
//     }
// }