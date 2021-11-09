#include <stdio.h>
#include "boolean.h"
#include "point.h"

int main() {
    POINT a = MakePOINT(0,0); POINT b = MakePOINT(5,2);
    BacaPOINT(&a);
    TulisPOINT(a); printf("\n");
    if (EQ(a, b)) printf("equal\n");
    else if (NEQ(a,b)) printf("not equal\n");
    if (IsOrigin(a)) printf("a in origin\n");
    else if (IsOnSbX(a)) printf("a in sb x\n");
    else if (IsOnSbY(a)) printf("a in sb y\n");
    else printf("a ada di kuadran %i\n", Kuadran(a));
    POINT c = NextX(a);
    POINT d = NextY(a);
    POINT e = PlusDelta(a, 1, 3);
    POINT f = MirrorOf(a, true);
    printf("Jarak: %f\nPanjang: %f\n", Jarak0(a), Panjang(a, b));
    GeserKeSbX(&a);
    GeserKeSbY(&a);
    Geser(&a, 3, 4);
    Mirror(&a, false);
    Putar(&a, 53);
    TulisPOINT(a); printf("\n");
}