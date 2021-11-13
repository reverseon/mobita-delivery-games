#include <stdio.h>
#include "mapfn.h"
#include "pcolor.h"
#define endl printf("\n")

char availdest[28];
boolean availdest_init = false;
int countAvailableBuilding;

POINT sLocHandler(ListBangunan l, ElType_ListBangunan namaGedung) {
    if (namaGedung == '8') {
        return MakePOINT(x_hq, y_hq);
    } else {
        return showLocation_ListBangunan(l, namaGedung);
    }
}

void availdestload() {
    availdest_init = true;
    countAvailableBuilding = 1;
    for (int i = 0; i < 27; i++) {
        availdest[i] = ' ';
    }
    for (int j = 0; j < adjacencyMatrix.colEff; j++) {
        if (adjacencyMatrix.contents[buildingCharToInt(_currentLocBuilding)][j] == 1) {
            availdest[countAvailableBuilding] = buildingIntToChar(j);
            countAvailableBuilding++;
        }
    }
    countAvailableBuilding--;
}

int buildingCharToInt(char b) {
    if (b == '8') {
        return 0;
    } else {
        return ((int)b) - 64;
    }
}

char buildingIntToChar(int a) {
    if (a == 0) {
        return '8';
    } else {
        return ((char)a + 64);
    }
}

void move_to(char building) {
    _currentLocBuilding = building;
    _currentLocPOINT = sLocHandler(tole, building);
    _time += 1;
    availdest_init = false;
}

void displayAvailableDestination() {
    for (int i = 1; i <= countAvailableBuilding; i++) {
        printf("%i. %c ", i, availdest[i]);
        TulisPOINT(sLocHandler(tole, availdest[i]));
        printf("\n");
    }
}

void move_command() {
    if (availdest_init == false) {
        availdestload();
    }
    Word* whereto = (Word*)malloc(sizeof(Word));
    printf("Posisi yang dapat dicapai:\n");
    displayAvailableDestination();
    printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)\n");
    readCommand(whereto);
    int dest = KataToInt(*whereto);
    if (dest == 0) {
        printf("Proses dibatalkan\n");
    } else if (availdest[dest] == ' ') {
        printf("Posisi tidak tersedia\n");
    } else {
        printf("Pindah ke: "); TulisPOINT(sLocHandler(tole, availdest[dest])); endl;
        move_to(availdest[dest]);
    }
}

void map_command() {
    if (availdest_init == false) {
        availdestload();
    }
    POINT temp; 
    POINT hq_coor = MakePOINT(x_hq, y_hq);
    int travBuild = 0;
    for (int i = 0; i < row+2; i++) {
        for (int j = 0; j < col+2; j++) {
            temp = MakePOINT(i, j);
            if (i == 0 || i == row+1 || j == 0 || j == col+1) {
                printf("*");
            } else if (EQPOINT(temp, hq_coor)) {
                if (_currentLocBuilding == '8') {
                    print_yellow('8');
                } else {
                    boolean can_move = false;
                    for (int availtrav = 1; availtrav <= countAvailableBuilding; availtrav++) {
                        if (availdest[availtrav] == '8') {
                            can_move = true;
                            break;
                        }
                    }
                    if (can_move) {
                        print_green('8');
                    } else {
                        printf("8");
                    }
                }
            } else if (travBuild <= NEFF_ListBangunan(tole)) {
                boolean found = false;
                for (int bt = 0; bt < NEFF_ListBangunan(tole); bt++) {
                    if (EQPOINT(temp, COORDINAT_ListBangunan(tole, bt))) {
                        if (ELMT_ListBangunan(tole, bt) == _currentLocBuilding) {
                            print_yellow(ELMT_ListBangunan(tole, bt));
                        } else {
                            boolean can_move = false;
                            for (int availtrav = 1; availtrav <= countAvailableBuilding; availtrav++) {
                                if (availdest[availtrav] == ELMT_ListBangunan(tole, bt)) {
                                    can_move = true;
                                    break;
                                }
                            }
                            if (can_move) {
                                print_green(ELMT_ListBangunan(tole, bt));
                            } else {
                                printf("%c", ELMT_ListBangunan(tole, bt));
                            }
                        }
                        found = true;
                        travBuild++;
                        break;
                    }
                }
                if (!found) {
                    printf(" ");
                }
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}