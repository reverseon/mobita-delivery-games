#include <stdio.h>
#include "map.h"
#define endl printf("\n")

char availdest[28];
boolean availdest_init = false;
int countAvailableBuilding;
MapMat DisplayedMap;
boolean maploaded = false;

POINT sLocHandler_MapMat(ListBangunan l, ElType_ListBangunan namaGedung) {
    if (namaGedung == '8') {
        return MakePOINT(x_hq, y_hq);
    } else {
        return showLocation_ListBangunan(l, namaGedung);
    }
}

void displayMap_MapMat(MapMat map) {
    for (int i = 0; i < ROWSMATRIX(map); i++) {
        for (int j = 0; j < COLSMATRIX(map); j++) {
            POINT temp = MakePOINT(i, j);
            if (EQPOINT(temp, _currentLocPOINT)) {
                print_yellow(GETELMT_MapMat(map, i, j));
            } else {
                boolean can_move = false;
                for (int availtrav = 1; availtrav <= countAvailableBuilding; availtrav++) {
                    if (availdest[availtrav] == GETELMT_MapMat(map, i, j)) {
                        can_move = true;
                        break;
                    }
                }
                if (can_move) {
                    print_green(GETELMT_MapMat(map, i, j));
                } else {
                    printf("%c", GETELMT_MapMat(map, i, j));
                }
            }
        }
        printf("\n");
    }
}

void loadMap_MapMat(MapMat* map) {
    ROWSMATRIX(*map) = row+2;
    COLSMATRIX(*map) = col+2;
    POINT temp; 
    POINT hq_coor = MakePOINT(x_hq, y_hq);
    int travBuild = 0;
    for (int i = 0; i < row+2; i++) {
        for (int j = 0; j < col+2; j++) {
            temp = MakePOINT(i, j);
            if (i == 0 || i == row+1 || j == 0 || j == col+1) {
                SETELMT_MapMat(DisplayedMap, i, j, '*');
            } else if (EQPOINT(temp, hq_coor)) {
                SETELMT_MapMat(DisplayedMap, i, j, '8');
            } else if (travBuild <= NEFF_ListBangunan(tole)) {
                boolean found = false;
                char iffound = ' ';
                for (int bt = 0; bt < NEFF_ListBangunan(tole); bt++) {
                    if (EQPOINT(temp, COORDINAT_ListBangunan(tole, bt))) {
                        iffound = ELMT_ListBangunan(tole, bt);
                        found = true;
                        travBuild++;
                        break;
                    }
                }
                if (!found) {
                    SETELMT_MapMat(DisplayedMap, i, j, ' ');
                } else {
                    SETELMT_MapMat(DisplayedMap, i, j, iffound);
                }
            } else {
               SETELMT_MapMat(DisplayedMap, i, j, ' ');
            }
        }
    }
    maploaded = true;
}

void availdestload_MapMat() {
    availdest_init = true;
    countAvailableBuilding = 1;
    for (int i = 0; i < 27; i++) {
        availdest[i] = ' ';
    }
    for (int j = 0; j < adjacencyMatrix.colEff; j++) {
        if (adjacencyMatrix.contents[buildingCharToInt_MapMat(_currentLocBuilding)][j] == 1) {
            availdest[countAvailableBuilding] = buildingIntToChar_MapMat(j);
            countAvailableBuilding++;
        }
    }
    countAvailableBuilding--;
}

int buildingCharToInt_MapMat(char b) {
    if (b == '8') {
        return 0;
    } else {
        return ((int)b) - 64;
    }
}

char buildingIntToChar_MapMat(int a) {
    if (a == 0) {
        return '8';
    } else {
        return ((char)a + 64);
    }
}

void move_to_MapMat(char building) {
    _currentLocBuilding = building;
    _currentLocPOINT = sLocHandler_MapMat(tole, building);
    _time = _time + _waktuTambahan +  1;
    availdest_init = false;
}

void displayAvailableDestination_MapMat() {
    for (int i = 1; i <= countAvailableBuilding; i++) {
        printf("%i. %c ", i, availdest[i]);
        TulisPOINT(sLocHandler_MapMat(tole, availdest[i]));
        printf("\n");
    }
}

void move_command_MapMat() {
    if (availdest_init == false) {
        availdestload_MapMat();
    }
    Word* whereto = (Word*)malloc(sizeof(Word));
    printf("Posisi yang dapat dicapai:\n");
    displayAvailableDestination_MapMat();
    printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)\n");
    readCommand(whereto);
    int dest = KataToInt(*whereto);
    if (dest == 0) {
        printf("Proses dibatalkan\n");
    } else if (availdest[dest] == ' ') {
        printf("Posisi tidak tersedia\n");
    } else {
        printf("Pindah ke: "); TulisPOINT(sLocHandler_MapMat(tole, availdest[dest])); endl;
        move_to_MapMat(availdest[dest]);
    }
}

void map_command_MapMat() {
    if (availdest_init == false) {
        availdestload_MapMat();
    }
    if (maploaded == false) {
        loadMap_MapMat(&DisplayedMap);
    }
    displayMap_MapMat(DisplayedMap);
}