#include <stdio.h>
#include <stdlib.h>
#include "adjacencymatrix.h"

AdjacencyMatrix loadAdjM(int nBuild) {
    AdjacencyMatrix* adjMap = (AdjacencyMatrix*)malloc(sizeof(AdjacencyMatrix));
    ROWSMATRIX(*adjMap) = nBuild+1;
    COLSMATRIX(*adjMap) = nBuild+1;
    int i ; // CONTROL
    int j ;
    for (i = 0 ; i < ROWSMATRIX(*adjMap); i++ ){
        for (j = 0 ; j < COLSMATRIX(*adjMap); j++) {
            ELMTMATRIX(*adjMap, i, j) = KataToInt(currentWord);
            advWord();
        }
    }
    return *adjMap;
}