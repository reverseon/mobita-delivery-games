#ifndef MAPS_FUNCTION_H
#define MAPS_FUNCTION_H
#include <stdio.h>
#include "../configuration_c/loadData.h"
#include "pcolor.h"

POINT sLocHandler(ArrDin l, ElType namaGedung);

int buildingCharToInt(char b);

char buildingIntToChar(int a);

void move_to(char building);

void displayAvailableDestination();

void move_command();

void map_command();
#endif