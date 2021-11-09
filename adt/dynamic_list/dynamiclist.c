#include <stdio.h>
#include <stdlib.h>
#include "dynamiclist.h"

void CreateListDin(ListDin *l, int capacity) {
    CAPACITYDYNAMIC(*l) = capacity;
    BUFFERDYNAMIC(*l) = (ElTypeDYNAMIC*)malloc(capacity*sizeof(ElTypeDYNAMIC));
    int i = 0;
    for (i = 0; i < capacity; i++) {
        ELMTDYNAMIC(*l, i) = VAL_UNDEFDYNAMIC; 
    }
}
void dealocateDYNAMIC(ListDin *l) {
    free(l);
}
int lengthDYNAMIC(ListDin l) {
    int len = 0;
    while(len < CAPACITYDYNAMIC(l) && ELMTDYNAMIC(l, len) != VAL_UNDEFDYNAMIC) {
        len++;
    };
    return len;
}
IdxTypeDYNAMIC getLastIdx(ListDin l) {
    return lengthDYNAMIC(l) - 1;
}
boolean isIdxValidDYNAMIC(ListDin l, IdxTypeDYNAMIC i) {
    return i >= 0 && i < CAPACITYDYNAMIC(l);
}
boolean isIdxEffDYNAMIC(ListDin l, IdxTypeDYNAMIC i) {
    return i >= 0 && i < lengthDYNAMIC(l);
}
boolean isEmptyDYNAMIC(ListDin l) {
    return lengthDYNAMIC(l) == 0;
}
boolean isFullDYNAMIC(ListDin l) {
    return lengthDYNAMIC(l) == CAPACITYDYNAMIC(l);
}
void displayListDYNAMIC(ListDin l) {
    int len = lengthDYNAMIC(l);
    int i = 0;
    if (isEmptyDYNAMIC(l)) {
        printf("[]");
    } else {
        printf("[");
        for (i = 0; i < len-1; i++) {
            printf("%i,", ELMTDYNAMIC(l,i));
        }
        printf("%i]", ELMTDYNAMIC(l, len-1));
    }
}
ListDin plusMinusListDYNAMIC(ListDin l1, ListDin l2, boolean plus) {
    ListDin out;
    CreateListDin(&out, CAPACITYDYNAMIC(l1));
    int len = lengthDYNAMIC(l1);
    int i = 0;
    if (plus) {
        for (i = 0; i < len; i++) {
            ELMTDYNAMIC(out, i) = ELMTDYNAMIC(l1, i) + ELMTDYNAMIC(l2, i);
        }
    } else {
        for (i = 0; i < len; i++) {
            ELMTDYNAMIC(out, i) = ELMTDYNAMIC(l1, i) - ELMTDYNAMIC(l2, i);
        }
    }
    return out;
}
boolean isListEqualDYNAMIC(ListDin l1, ListDin l2) {
    int len1 = lengthDYNAMIC(l1);
    int len2 = lengthDYNAMIC(l2);
    if (len1 == len2) {
        boolean dif = false;
        sortDYNAMIC(&l1, true); sortDYNAMIC(&l2, true);
        int i = 0;
        while (i < len1 && !dif) {
            if (ELMTDYNAMIC(l1, i) != ELMTDYNAMIC(l2, i)) {
                dif = true;
            } else {
                i++;
            }
        }
        return !dif;
    } else {
        return false;
    }
}
IdxTypeDYNAMIC indexOfDYNAMIC(ListDin l, ElTypeDYNAMIC val) {
    IdxTypeDYNAMIC out;
    boolean found = false;
    int i = 0;
    int len = lengthDYNAMIC(l);
    while (i < len && !found) {
        if (ELMTDYNAMIC(l,i) == val) {
            found = true;
            out = i;
        } else {
            i++;
        }
    }
    if (!found) out = VAL_UNDEFDYNAMIC;
    return out;
}
void extremesDYNAMIC(ListDin l, ElTypeDYNAMIC *max, ElTypeDYNAMIC *min) {
    int len = lengthDYNAMIC(l);
    *max = ELMTDYNAMIC(l, 0);
    *min = *max;
    int i = 1;
    for (i = 1; i < len; i++) {
        if (*max < ELMTDYNAMIC(l,i)) *max = ELMTDYNAMIC(l,i);
        if (*min > ELMTDYNAMIC(l,i)) *min = ELMTDYNAMIC(l,i);
    }
}
void copyListDYNAMIC(ListDin lIn, ListDin *lOut) {
    CreateListDin(lOut, CAPACITYDYNAMIC(lIn));
    int len = lengthDYNAMIC(lIn);
    int i = 0;
    for (i = 0; i < len; i++) {
        ELMTDYNAMIC(*lOut, i) = ELMTDYNAMIC(lIn, i);
    }
}
ElTypeDYNAMIC sumListDYNAMIC(ListDin l) {
    int len = lengthDYNAMIC(l);
    ElTypeDYNAMIC out = 0;
    int i = 0;
    for (i = 0; i < len; i++) {
        out += ELMTDYNAMIC(l, i);
    }
    return out;
}
int countValDYNAMIC(ListDin l, ElTypeDYNAMIC val) {
    int len = lengthDYNAMIC(l);
    int count = 0;
    int i = 0;
    for (i=0; i<len; i++) {
        if (ELMTDYNAMIC(l, i) == val) {
            count++;
        }
    }
    return count;
}
boolean isAllEvenDYNAMIC(ListDin l) {
    int len = lengthDYNAMIC(l);
    int i = 0;
    boolean ev = true;
    while (i < len && ev) {
        if (ELMTDYNAMIC(l,i)%2 == 1) ev = false;
        i++;
    }
    return ev;
}
void sortDYNAMIC(ListDin *l, boolean asc) {
    int len = lengthDYNAMIC(*l);
    int i = 0;
    if (asc) {
        boolean flip = false;
        do {
            flip = false;
            for (i = 0; i < len-1; i++) {
                if (ELMTDYNAMIC(*l,i+1) < ELMTDYNAMIC(*l,i)) {
                    flip = true;
                    ElTypeDYNAMIC temp = ELMTDYNAMIC(*l, i+1);
                    ELMTDYNAMIC(*l, i+1) = ELMTDYNAMIC(*l,i);
                    ELMTDYNAMIC(*l,i) = temp;
                }
            }
        } while (flip);
    } else {
        boolean flip = false;
        do {
            flip = false;
            for (i = 0; i < len-1; i++) {
                if (ELMTDYNAMIC(*l,i+1) > ELMTDYNAMIC(*l,i)) {
                    flip = true;
                    ElTypeDYNAMIC temp = ELMTDYNAMIC(*l, i+1);
                    ELMTDYNAMIC(*l, i+1) = ELMTDYNAMIC(*l,i);
                    ELMTDYNAMIC(*l,i) = temp;
                }
            }
        } while (flip);
    }
}
void insertLastDYNAMIC(ListDin *l, ElTypeDYNAMIC val) {
    int len = lengthDYNAMIC(*l);
    ELMTDYNAMIC(*l, len) = val;
}
void deleteLastDYNAMIC(ListDin *l, ElTypeDYNAMIC *val) {
    *val = ELMTDYNAMIC(*l, getLastIdx(*l));
    ELMTDYNAMIC(*l, getLastIdx(*l)) = VAL_UNDEFDYNAMIC;
}
void growListDYNAMIC(ListDin *l, int num) {
    CAPACITYDYNAMIC(*l)+=num;
    BUFFERDYNAMIC(*l) = realloc(BUFFERDYNAMIC(*l), CAPACITYDYNAMIC(*l)*sizeof(ElTypeDYNAMIC));
}
void shrinkListDYNAMIC(ListDin *l, int num) {
    CAPACITYDYNAMIC(*l)-=num;
    BUFFERDYNAMIC(*l) = realloc(BUFFERDYNAMIC(*l), CAPACITYDYNAMIC(*l)*sizeof(ElTypeDYNAMIC));
}
void compactListDYNAMIC(ListDin *l) {
    CAPACITYDYNAMIC(*l) = lengthDYNAMIC(*l);
    BUFFERDYNAMIC(*l) = realloc(BUFFERDYNAMIC(*l), CAPACITYDYNAMIC(*l)*sizeof(ElTypeDYNAMIC));
}