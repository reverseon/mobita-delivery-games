#include <stdio.h>
#include "mapfn.h"
#define endl printf("\n")

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
    _currentLocPOINT = showLocation(tole, building);
    _time += 1;
}

void displayAvailableDestination(char* availdest) {
    int count = 1;
    for (int j = 0; j < adjacencyMatrix.cEff; j++) {
        if (adjacencyMatrix.a[buildingCharToInt(_currentLocBuilding)][j] == 1) {
            availdest[count] = buildingIntToChar(j);
            printf("%i. %c ", count, buildingIntToChar(j));
            TulisPOINT(showLocation(tole, buildingIntToChar(j)));
            printf("\n");
            count++;
        }
    }
}

void move_command() {
    Word* whereto = (Word*)malloc(sizeof(Word));
    char availdest[28];
    for (int i = 0; i < 27; i++) {
        availdest[i] = ' ';
    }
    printf("Posisi yang dapat dicapai:\n");
    displayAvailableDestination(availdest);
    printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)\n");
    readCommand(whereto);
    int dest = KataToInt(*whereto);
    if (dest == 0) {
        printf("Proses dibatalkan\n");
    } else if (availdest[dest] == ' ') {
        printf("Posisi tidak tersedia\n");
    } else {
        printf("Pindah ke: "); TulisPOINT(showLocation(tole, availdest[dest])); endl;
        move_to(availdest[dest]);
    }
}

void map_command() {
    POINT temp; 
    POINT hq_coor = MakePOINT(x_hq, y_hq);
    int travBuild = 0;
    for (int i = 0; i < row+2; i++) {
        for (int j = 0; j < col+2; j++) {
            temp = MakePOINT(i, j);
            if (i == 0 || i == row+1 || j == 0 || j == col+1) {
                printf("*");
            } else if (EQ(temp, hq_coor)) {
                printf("8");
            } else if (travBuild < NEFF(tole)) {
                boolean found = false;
                for (int bt = 0; bt < NEFF(tole); bt++) {
                    if (EQ(temp, COORDINAT(tole, bt))) {
                        printf("%c", ELMT(tole, bt));
                        found = true;
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