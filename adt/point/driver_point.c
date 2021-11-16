#include <stdio.h>
#include "boolean.h"
#include "point.h"

int main() {
    POINT a = MakePOINT(0,0); POINT b = MakePOINT(5,2);
    TulisPOINT(a); printf("\n");
    if (EQ(a, b)) printf("equal\n");
    else if (NEQ(a,b)) printf("not equal\n");
}