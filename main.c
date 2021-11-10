#include <stdio.h>
#include "adt/load/loadData.h"
// #include "stack/stack.h"
#define endl printf("\n")

boolean EXIT = false;

void commandProcess() {
    Word* command = (Word*)malloc(sizeof(Word));
    printf("ENTER COMMAND: ");readCommand(command);
    if (IsCommandSama(*command,StringToKata("MOVE"))) {
        move_command_MapMat();
        // jumlahPesanan out = sq->root->data;
        // while(out.time <= _time){
        //     addQueuetoTodo(&TL, sq);
        //     out = sq->root->data;
        // } 
    } else if (IsCommandSama(*command,StringToKata("MAP"))) {
        map_command_MapMat();
    } else if (IsCommandSama(*command,StringToKata("EXIT"))) {
        printf("EXITING...\n");
        EXIT = true;
    } else if (IsCommandSama(*command,StringToKata("PICK_UP"))) {
        // pickup_command();
    }  else if (IsCommandSama(*command,StringToKata("TO_DO"))) {
        // displayTodoList(TL);
    }
    else {
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
    load_data("configuration_c/rutin.txt");
    while (!EXIT) {
        displayStats();
        printf("\n");
    }
}