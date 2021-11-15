#include <stdio.h>
#include "map.h"
#include "../load/loadData.h"

// CARA RUN
// make build
// ./driver_map

int main() {
    load_data("../../savefile/test.txt");
    map_command_MapMat();
    move_command_MapMat();
    map_command_MapMat();
}