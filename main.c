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
        jumlahPesanan out = sq->root->data;
        while(out.time <= _time && out.time != -1){
            addQueuetoTodo(&TL, sq);
            out = sq->root->data;
        }
        
        // Update perishable item
        updatePerishable(&backpack);

    } else if (IsCommandSama(*command,StringToKata("MAP"))) {
        map_command_MapMat();
    } else if (IsCommandSama(*command,StringToKata("EXIT"))) {
        printf("EXITING...\n");
        EXIT = true;
    } else if (IsCommandSama(*command,StringToKata("PICK_UP"))) {
        pickup_command();
    }  else if (IsCommandSama(*command,StringToKata("TO_DO"))) {
        displayTodoList(TL);
    } else if (IsCommandSama(*command,StringToKata("IN_PROGRESS"))) {
        displayProgressList(_ListOfProggress);
    } else if (IsCommandSama(*command,StringToKata("INVENTORY"))) {
        display_inventory(_inventory);
        printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)");
        printf("\n\nENTER COMMAND: ");
        int use_item;
        scanf("%d", &use_item);
        char returnStr[255];
        switch (use_item)
        {
            case 0:
                printf("Menutup Inventory\n");
                break;
            case 1:
                GetElmt_inventory(_inventory, 0, returnStr);
                if (returnStr[0]=='-')
                {
                    printf("Tidak ada Gadget yang dapat digunakan!\n");
                }
                else
                {
                    SetElmnt_inventory(&_inventory, 0, "-");
                    printf("%s berhasil digunakan\n", returnStr);
                }
                break;
            case 2:
                GetElmt_inventory(_inventory, 1, returnStr);
                if (returnStr[0]=='-')
                {
                    printf("Tidak ada Gadget yang dapat digunakan!\n");
                }
                else
                {
                    SetElmnt_inventory(&_inventory, 1, "-");
                    printf("%s berhasil digunakan\n", returnStr);
                }
                break;
            case 3:
                GetElmt_inventory(_inventory, 2, returnStr);
                if (returnStr[0]=='-')
                {
                    printf("Tidak ada Gadget yang dapat digunakan!\n");
                }
                else
                {
                    SetElmnt_inventory(&_inventory, 2, "-");
                    printf("%s berhasil digunakan\n", returnStr);
                }
                break;
            case 4:
                GetElmt_inventory(_inventory, 3, returnStr);
                if (returnStr[0]=='-')
                {
                    printf("Tidak ada Gadget yang dapat digunakan!\n");
                }
                else
                {
                    SetElmnt_inventory(&_inventory, 3, "-");
                    printf("%s berhasil digunakan\n", returnStr);
                }
                break;
            case 5:
                GetElmt_inventory(_inventory, 4, returnStr);
                if (returnStr[0]=='-')
                {
                    printf("Tidak ada Gadget yang dapat digunakan!\n");
                }
                else
                {
                    SetElmnt_inventory(&_inventory, 4, "-");
                    printf("%s berhasil digunakan\n", returnStr);
                }
                break;
            default:
                printf("Command Anda Salah!\n");
                break;
        }
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
    load_data("savefile/test.txt");
    while (!EXIT) {
        displayStats();
        printf("\n");
    }
}