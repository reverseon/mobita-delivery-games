#include <stdio.h>
#include "staticlist.h"

void CreateListPosSTATIC(ListPos *l) {
    int i = 0;
    for (i = 0; i < CAPACITYSTATIC; i++) ELMTSTATIC(*l, i) = VAL_UNDEF;   
}
int lengthSTATIC(ListPos l) {
    int r = 0;
    boolean udf = false;
    while (r < CAPACITYSTATIC && !udf) {
        if (ELMTSTATIC(l,r) == VAL_UNDEF) {
            udf = true;
        } else r++;
    }
    return r;
}
boolean isIdxValidSTATIC(ListPos l, int i) {
    return i >= 0 && i < CAPACITYSTATIC; 
}
boolean isIdxEffSTATIC(ListPos l, int i) {
    if (isIdxValidSTATIC(l,i)) {
        return ELMTSTATIC(l,i) != VAL_UNDEF;
    } else {
        return false;
    } 
}
boolean isEmptySTATIC(ListPos l) {
    return lengthSTATIC(l) == 0;
}

boolean isFullSTATIC(ListPos l) {
    return lengthSTATIC(l) == CAPACITYSTATIC;
}
void displayListSTATIC(ListPos l) {
    int i = 0;
    int len = lengthSTATIC(l);
    if (len == 0) {
        printf("[]");
    } else {
        printf("[");
        for (i = 0; i < len-1; i++) {
            printf("%i,", ELMTSTATIC(l,i));
        }
        printf("%i]", ELMTSTATIC(l, len-1));
    }
}

ListPos plusMinusTabSTATIC(ListPos l1, ListPos l2, boolean plus) {
    int i = 0;
    ListPos ret;
    CreateListPosSTATIC(&ret);
    if (plus) {
        for (i = 0; i < lengthSTATIC(l1); i++) {
            ELMTSTATIC(ret, i) = ELMTSTATIC(l1, i) + ELMTSTATIC(l2, i);
        }
    } else {
        for (i = 0; i < lengthSTATIC(l1); i++) {
            ELMTSTATIC(ret, i) = ELMTSTATIC(l1, i) - ELMTSTATIC(l2, i);
        }
    }
    return ret;
}

boolean isListEqualSTATIC(ListPos l1, ListPos l2) {
    int len = lengthSTATIC(l1);
    if (len == lengthSTATIC(l2)) {
        sortSTATIC(&l1, true); sortSTATIC(&l2, true);
        int i = 0;
        boolean dif = false;
        while (i < len && !dif)  {
            if (ELMTSTATIC(l1,i) != ELMTSTATIC(l2,i)) dif = true;
            i++;
        } 
        return !dif;
    } else return false;
}

int indexOfSTATIC(ListPos l, ElTypeSTATIC val) {
    int i = 0;
    boolean f = false;

    while (i < lengthSTATIC(l) && !f) {
        if (ELMTSTATIC(l, i) == val) f = true;
        i++;
    }
    if (f) return i-1;
    else return IDX_UNDEF;
}

void extremesSTATIC(ListPos l, ElTypeSTATIC *max, ElTypeSTATIC *min) {
    *max = ELMTSTATIC(l, 0);
    *min = *max;
    int i = 1;
    for (i = 1; i < lengthSTATIC(l); i++) {
        if (*max < ELMTSTATIC(l,i)) *max = ELMTSTATIC(l,i);
        if (*min > ELMTSTATIC(l,i)) *min = ELMTSTATIC(l,i);
    }
}
boolean isAllEvenSTATIC(ListPos l) {
    int i = 0;
    boolean ev = true;
    while (i < lengthSTATIC(l) && ev) {
        if (ELMTSTATIC(l,i)%2 == 1) ev = false;
        i++;
    }
    return ev;
}
void sortSTATIC(ListPos *l, boolean asc) {
    int len = lengthSTATIC(*l);
    int i = 0;
    if (asc) {
        boolean flip = false;
        do {
            flip = false;
            for (i = 0; i < len-1; i++) {
                if (ELMTSTATIC(*l,i+1) < ELMTSTATIC(*l,i)) {
                    flip = true;
                    ElTypeSTATIC temp = ELMTSTATIC(*l, i+1);
                    ELMTSTATIC(*l, i+1) = ELMTSTATIC(*l,i);
                    ELMTSTATIC(*l,i) = temp;
                }
            }
        } while (flip);
    } else {
        boolean flip = false;
        do {
            flip = false;
            for (i = 0; i < len-1; i++) {
                if (ELMTSTATIC(*l,i+1) > ELMTSTATIC(*l,i)) {
                    flip = true;
                    ElTypeSTATIC temp = ELMTSTATIC(*l, i+1);
                    ELMTSTATIC(*l, i+1) = ELMTSTATIC(*l,i);
                    ELMTSTATIC(*l,i) = temp;
                }
            }
        } while (flip);
    }
}
void insertLastSTATIC(ListPos *l, ElTypeSTATIC val) {
    ELMTSTATIC(*l,lengthSTATIC(*l)) = val; 
}
void deleteLastSTATIC(ListPos *l, ElTypeSTATIC *val) {
    int len = lengthSTATIC(*l);
    *val = ELMTSTATIC(*l, len-1);
    ELMTSTATIC(*l, len-1) = VAL_UNDEF;
}