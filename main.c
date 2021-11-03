#include <stdio.h>
#include "configuration_c/loadData.h"
#include "map/mapfn.h"
#define endl printf("\n")

boolean EXIT = false;

void commandProcess() {
    Word command;
    printf("ENTER COMMAND: ");readCommand(&command);
    if (IsCommandSama(command,StringToKata("MOVE"))) {
        move_command();
    } else if (IsCommandSama(command,StringToKata("MAP"))) {
        map_command();
    } else if (IsCommandSama(command,StringToKata("EXIT"))) {
        printf("EXITING...\n");
        EXIT = true;
    } else {
        printf("Command Invalid\n");
    }
}
void displayStats() {
    printf("Mobita berada di posisi %c ", _currentLocBuilding); TulisPOINT(_currentLocPOINT); endl;
    printf("Waktu: %i\n", _time);
    printf("Uang yang dimiliki: %i Yen\n", _money);
    commandProcess();
}

int main() {
    load_data("C:\\reverseon\\code\\github\\Alstrukdat_Kel08_K03\\configuration_c\\rutin.txt");
    while (!EXIT) {
        displayStats();
        printf("\n");
    }
}