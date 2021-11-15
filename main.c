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
        jumlahPesanan* out = &sq->root->data;
        while(out != NULL && out->time <= _time){
            addQueuetoTodo(&TL, sq);
            out = &sq->root->data;
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
    } else if (IsCommandSama(*command,StringToKata("BUY"))) {
        printf("\nUang anda sekarang: %d Yen\n", _money);
        printf("Gadget yang tersedia:\n");
        printf("1. Kain Pembungkus Waktu (800 Yen)\n");
        printf("2. Senter Pembesar (1200 Yen)\n");
        printf("3. Pintu Kemana Saja (1500 Yen)\n");
        printf("4. Mesin Waktu (3000 Yen)\n");
        printf("Gadget mana yang ingin dibeli? (ketik 0 jika ingin kembali)\n\n");
        printf("ENTER COMMAND: ");
        int buy_item;
        scanf("%d", &buy_item);
        char inventory_item[255];
        switch (buy_item)
        {
            case 0:
                printf("Menutup Shop\n");
                break;
            case 1:
                if (_money - 800 >= 0)
                {
                    // Mengecek apakah masih ada slot pada inventory
                    GetElmt_inventory(_inventory, 0, inventory_item);
                    if (inventory_item[0]=='-')
                    {
                        _money -= 800;
                        printf("Kain Pembungkus Waktu berhasil dibeli!\n");
                        SetElmnt_inventory(&_inventory, 0, "Kain Pembungkus Waktu");
                        break;
                    }
                    GetElmt_inventory(_inventory, 1, inventory_item);
                    if (inventory_item[0]=='-')
                    {
                        _money -= 800;
                        printf("Kain Pembungkus Waktu berhasil dibeli!\n");
                        SetElmnt_inventory(&_inventory, 1, "Kain Pembungkus Waktu");
                        break;
                    }
                    GetElmt_inventory(_inventory, 2, inventory_item);
                    if (inventory_item[0]=='-')
                    {
                        _money -= 800;
                        printf("Kain Pembungkus Waktu berhasil dibeli!\n");
                        SetElmnt_inventory(&_inventory, 2, "Kain Pembungkus Waktu");
                        break;
                    }
                    GetElmt_inventory(_inventory, 3, inventory_item);
                    if (inventory_item[0]=='-')
                    {
                        _money -= 800;
                        printf("Kain Pembungkus Waktu berhasil dibeli!\n");
                        SetElmnt_inventory(&_inventory, 3, "Kain Pembungkus Waktu");
                        break;
                    }
                    GetElmt_inventory(_inventory, 4, inventory_item);
                    if (inventory_item[0]=='-')
                    {
                        _money -= 800;
                        printf("Kain Pembungkus Waktu berhasil dibeli!\n");
                        SetElmnt_inventory(&_inventory, 4, "Kain Pembungkus Waktu");
                        break;
                    }
                    printf("Inventory Telah Penuh!\n");
                    break;
                }
                else
                {
                    printf("Uang tidak cukup untuk membeli gadget!");
                    break;
                }
                break;
            case 2:
                if (_money - 1200 >= 0)
                {
                    // Mengecek apakah masih ada slot pada inventory
                    GetElmt_inventory(_inventory, 0, inventory_item);
                    if (inventory_item[0]=='-')
                    {
                        _money -= 1200;
                        printf("Senter Pembesar berhasil dibeli!\n");
                        SetElmnt_inventory(&_inventory, 0, "Senter Pembesar");
                        break;
                    }
                    GetElmt_inventory(_inventory, 1, inventory_item);
                    if (inventory_item[0]=='-')
                    {
                        _money -= 1200;
                        printf("Senter Pembesar berhasil dibeli!\n");
                        SetElmnt_inventory(&_inventory, 1, "Senter Pembesar");
                        break;
                    }
                    GetElmt_inventory(_inventory, 2, inventory_item);
                    if (inventory_item[0]=='-')
                    {
                        _money -= 1200;
                        printf("Senter Pembesar berhasil dibeli!\n");
                        SetElmnt_inventory(&_inventory, 2, "Senter Pembesar");
                        break;
                    }
                    GetElmt_inventory(_inventory, 3, inventory_item);
                    if (inventory_item[0]=='-')
                    {
                        _money -= 1200;
                        printf("Senter Pembesar berhasil dibeli!\n");
                        SetElmnt_inventory(&_inventory, 3, "Senter Pembesar");
                        break;
                    }
                    GetElmt_inventory(_inventory, 4, inventory_item);
                    if (inventory_item[0]=='-')
                    {
                        _money -= 1200;
                        printf("Senter Pembesar berhasil dibeli!\n");
                        SetElmnt_inventory(&_inventory, 4, "Senter Pembesar");
                        break;
                    }
                    printf("Inventory Telah Penuh!\n");
                    break;
                }
                else
                {
                    printf("Uang tidak cukup untuk membeli gadget!");
                    break;
                }
                break;
            case 3:
                if (_money - 1500 >= 0)
                {
                    // Mengecek apakah masih ada slot pada inventory
                    GetElmt_inventory(_inventory, 0, inventory_item);
                    if (inventory_item[0]=='-')
                    {
                        _money -= 1500;
                        printf("Pintu Kemana Saja berhasil dibeli!\n");
                        SetElmnt_inventory(&_inventory, 0, "Pintu Kemana Saja");
                        break;
                    }
                    GetElmt_inventory(_inventory, 1, inventory_item);
                    if (inventory_item[0]=='-')
                    {
                        _money -= 1500;
                        printf("Pintu Kemana Saja berhasil dibeli!\n");
                        SetElmnt_inventory(&_inventory, 1, "Pintu Kemana Saja");
                        break;
                    }
                    GetElmt_inventory(_inventory, 2, inventory_item);
                    if (inventory_item[0]=='-')
                    {
                        _money -= 1500;
                        printf("Pintu Kemana Saja berhasil dibeli!\n");
                        SetElmnt_inventory(&_inventory, 2, "Pintu Kemana Saja");
                        break;
                    }
                    GetElmt_inventory(_inventory, 3, inventory_item);
                    if (inventory_item[0]=='-')
                    {
                        _money -= 1500;
                        printf("Pintu Kemana Saja berhasil dibeli!\n");
                        SetElmnt_inventory(&_inventory, 3, "Pintu Kemana Saja");
                        break;
                    }
                    GetElmt_inventory(_inventory, 4, inventory_item);
                    if (inventory_item[0]=='-')
                    {
                        _money -= 1500;
                        printf("Pintu Kemana Saja berhasil dibeli!\n");
                        SetElmnt_inventory(&_inventory, 4, "Pintu Kemana Saja");
                        break;
                    }
                    printf("Inventory Telah Penuh!\n");
                    break;
                }
                else
                {
                    printf("Uang tidak cukup untuk membeli gadget!");
                    break;
                }
                break;
            case 4:
                if (_money - 3000 >= 0)
                {
                    // Mengecek apakah masih ada slot pada inventory
                    GetElmt_inventory(_inventory, 0, inventory_item);
                    if (inventory_item[0]=='-')
                    {
                        _money -= 3000;
                        printf("Mesin Waktu berhasil dibeli!\n");
                        SetElmnt_inventory(&_inventory, 0, "Mesin Waktu");
                        break;
                    }
                    GetElmt_inventory(_inventory, 1, inventory_item);
                    if (inventory_item[0]=='-')
                    {
                        _money -= 3000;
                        printf("Mesin Waktu berhasil dibeli!\n");
                        SetElmnt_inventory(&_inventory, 1, "Mesin Waktu");
                        break;
                    }
                    GetElmt_inventory(_inventory, 2, inventory_item);
                    if (inventory_item[0]=='-')
                    {
                        _money -= 3000;
                        printf("Mesin Waktu berhasil dibeli!\n");
                        SetElmnt_inventory(&_inventory, 2, "Mesin Waktu");
                        break;
                    }
                    GetElmt_inventory(_inventory, 3, inventory_item);
                    if (inventory_item[0]=='-')
                    {
                        _money -= 3000;
                        printf("Mesin Waktu berhasil dibeli!\n");
                        SetElmnt_inventory(&_inventory, 3, "Mesin Waktu");
                        break;
                    }
                    GetElmt_inventory(_inventory, 4, inventory_item);
                    if (inventory_item[0]=='-')
                    {
                        _money -= 3000;
                        printf("Mesin Waktu berhasil dibeli!\n");
                        SetElmnt_inventory(&_inventory, 4, "Mesin Waktu");
                        break;
                    }
                    printf("Inventory Telah Penuh!\n");
                    break;
                }
                else
                {
                    printf("Uang tidak cukup untuk membeli gadget!");
                    break;
                }
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