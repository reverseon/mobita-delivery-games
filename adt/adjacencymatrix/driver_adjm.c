#include <stdio.h>
#include "adjacencymatrix.h"
#include "../load/loadData.h"

// CARA RUN
// make build
// ./driver_adjm

void dispRel(AdjacencyMatrix a) {
    for (int i = 0; i < max+1; i++) {
        if (i == 0) {
            printf("Relasi ke HQ: ");
        } else {
            printf("Relasi Bangunan ke-%i: ", i);
        }
        for (int j = 0; j < 18; j++) {
            if (ELMTMATRIX(a, i, j) == 1) {
                printf("%i ", j);
            }
        }
        printf("\n");
    }
}

int main() {
    load_data("../../savefile/test.txt");
    dispRel(adjacencyMatrix);
}