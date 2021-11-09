#ifndef MAPS_FUNCTION_H
#define MAPS_FUNCTION_H
#include <stdio.h>
#include "../load/loadData.h"
#include "../pcolor/pcolor.h"

POINT sLocHandler(ListBangunan l, ElType_ListBangunan namaGedung);

int buildingCharToInt(char b);

char buildingIntToChar(int a);

void move_to(char building);

void displayAvailableDestination();

void move_command();

void map_command();
#endif