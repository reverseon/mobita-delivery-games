#include <stdio.h>
#include "bangunan.h"
#include "../load/loadData.h"

// CARA RUN
// make build
// ./driver_bangunan

int main() {
    load_data("../../savefile/test.txt");
    displayList_ListBangunan(tole);
    printf("\n");
    TulisPOINT(showLocation_ListBangunan(tole, 'D'));
    printf("\n%i\n", length_ListBangunan(tole));
}