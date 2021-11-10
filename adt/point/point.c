#include <stdio.h>
#include "point.h"

const float PI = 3.14159;

POINT MakePOINT (int X, int Y) {
    POINT a;
    AbsisPOINT(a) = X;
    OrdinatPOINT(a) = Y;
    return a;
};

void TulisPOINT (POINT P) {
    printf("(%i,%i)", AbsisPOINT(P), OrdinatPOINT(P));
}

boolean EQPOINT (POINT P1, POINT P2) {
    return (AbsisPOINT(P1) == AbsisPOINT(P2)) && (OrdinatPOINT(P1) == OrdinatPOINT(P2)); 
}

boolean NEQPOINT (POINT P1, POINT P2) {
    return !EQPOINT(P1, P2);
}

boolean IsOriginPOINT (POINT P) {
    return AbsisPOINT(P) == 0 && OrdinatPOINT(P) == 0;
}

boolean IsOnSbXPOINT (POINT P) {
    return OrdinatPOINT(P) == 0;
}

boolean IsOnSbYPOINT (POINT P) {
    return AbsisPOINT(P) == 0;
}

int KuadranPOINT (POINT P) {
    if (AbsisPOINT(P) > 0 && OrdinatPOINT(P) > 0) return 1;
    else 
    if (AbsisPOINT(P) < 0 && OrdinatPOINT(P) > 0) return 2;
    else 
    if (AbsisPOINT(P) < 0 && OrdinatPOINT(P) < 0) return 3;
    else return 4;
}

POINT NextXPOINT (POINT P) {
    return MakePOINT(AbsisPOINT(P)+1, OrdinatPOINT(P));
};

POINT NextYPOINT (POINT P) {
    return MakePOINT(AbsisPOINT(P), OrdinatPOINT(P)+1);
};

POINT PlusDeltaPOINT (POINT P, int deltaX, int deltaY) {
    return MakePOINT(AbsisPOINT(P) + deltaX, OrdinatPOINT(P) + deltaY);
}

POINT MirrorOfPOINT (POINT P, boolean SbX) {
    if (SbX) {
        return MakePOINT(AbsisPOINT(P), -1*OrdinatPOINT(P));
    } else {
        return MakePOINT(-1*AbsisPOINT(P), OrdinatPOINT(P));
    }
}

// float Jarak0POINT (POINT P) {
//     return sqrt(AbsisPOINT(P)*AbsisPOINT(P) + OrdinatPOINT(P)*OrdinatPOINT(P));
// }

void GeserPOINT (POINT *P, int deltaX, int deltaY) {
    AbsisPOINT(*P) += deltaX;
    OrdinatPOINT(*P) += deltaY;
}

void GeserKeSbXPOINT (POINT *P) {
    OrdinatPOINT(*P) = 0;
}

void GeserKeSbYPOINT (POINT *P) {
    AbsisPOINT(*P) = 0;
}

void MirrorPOINT (POINT *P, boolean SbX) {
    if (SbX) {
        OrdinatPOINT(*P) *= -1;
    } else {
        AbsisPOINT(*P) *= -1; 
    }
}