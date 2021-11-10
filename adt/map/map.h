#ifndef MAP_MATRIX_H
#define MAP_MATRIX_H
#include <stdio.h>
#include "../load/loadData.h"
#include "../pcolor/pcolor.h"
#define GETELMT_MapMat(M, i, j) (char)(M).contents[(i)][(j)]
#define SETELMT_MapMat(M, i, j, v) (M).contents[(i)][(j)] = (unsigned)(v)

typedef Matrix MapMat;

POINT sLocHandler_MapMat(ListBangunan l, ElType_ListBangunan namaGedung);

void loadMap_MapMat(MapMat* map);

void availdestload_MapMat();

int buildingCharToInt_MapMat(char b);

char buildingIntToChar_MapMat(int a);

void move_to_MapMat(char building);

void displayAvailableDestination_MapMat();

void move_command_MapMat();

void map_command_MapMat();
#endif