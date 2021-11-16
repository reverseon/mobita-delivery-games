#include <stdio.h>
#include "adt/load/loadData.h"
// #include "stack/stack.h"
#define endl printf("\n")

boolean EXIT = false;
boolean FINISH = false;

int strlen_main(const char* a)
{
    int result = 0;
    while(a[result++] != '\0') {
    }
    return result - 1;
}


boolean strcmp_main(const char* a, const char* b) {
    int aLen = strlen_main(a);
    int bLen = strlen_main(b);
    if(aLen != bLen) {
        return false;
    }
    int index = 0;
    while(a[index] != '\0') {
        if(a[index] != b[index]) {
            return false;
        }
        index++;
    }
    return true;
}

void help_command_main() {
    printf("MOVE -> menampilkan pilihan lokasi dan pindah ke lokasi tersebut bila diinginkan.\n");
    printf("PICK_UP -> mengambil item jika ada pesanan yang harus diambil pada lokasi.\n");
    printf("DROP_OFF -> mengantarkan item ke lokasi jika item di tumpukan teratas tas sesuai dengan pesanan.\n");
    printf("MAP -> menampilkan Peta\n");
    printf("TO_DO -> menampilkan pesanan yang dapat di lokasi tertentu sekarang.\n");
    printf("IN_PROGRESS -> menampilkan pesanan yang sedang dikerjakan.\n");
    printf("BUY -> menampilkan gadget dan membelinya. hanya dapat digunakan ketika di HQ\n");
    printf("INVENTORY -> menampilkan inventory dan menggunakan gadget yang tersedia\n");
    printf("HELP -> menampilkan penjelasan command yang tersedia\n");
    printf("EXIT -> keluar dari program\n");
}

void commandProcess() {
    printf("ENTER COMMAND: ");
    startWordInput();
    if (IsCommandSama(currentWord, StringToKata("HELP"))) {
        help_command_main();
    } else 
    if (IsCommandSama(currentWord,StringToKata("MOVE"))) {
        move_command_MapMat();
        if (_currentLocBuilding == '8' && isEmptysorted_pesanan(sq) && isEmptyLL(TL) && isEmptyTas(backpack) && isEmptyLL(_ListOfProggress)) {
            FINISH = true;
        } else {
            jumlahPesanan* out = &sq->root->data;
            while(out != NULL && out->time <= _time){
                addQueuetoTodo(&TL, sq);
                out = &sq->root->data;
            }   
            // Update perishable item
            updatePerishable(&backpack);
        }
        if (_speedBoost == true) {
            _moveCounter++;
            if (_moveCounter % 2 == 0) {
                _time--;
            }
            if (_moveCounter == 10) {
                _speedBoost = false;
                _moveCounter = 0;
            }
        }

    } else if (IsCommandSama(currentWord,StringToKata("MAP"))) {
        map_command_MapMat();
    } else if (IsCommandSama(currentWord,StringToKata("EXIT"))) {
        EXIT = true;
    } else if (IsCommandSama(currentWord,StringToKata("PICK_UP"))) {
        pickup_command();
    }  else if (IsCommandSama(currentWord,StringToKata("TO_DO"))) {
        displayTodoList(TL);
    } else if (IsCommandSama(currentWord,StringToKata("IN_PROGRESS"))) {
        displayProgressList(_ListOfProggress);
    } else if (IsCommandSama(currentWord,StringToKata("INVENTORY"))) {
        display_inventory(_inventory);
        printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)");
        printf("\n\nENTER COMMAND: "); startWordInput();
        char pakai_gadget[255];
        int inp_inventory = KataToInt(currentWord);
        switch (inp_inventory)
        {
            case 0:
                printf("Menutup Inventory\n");
                break;
            case 1:
                GetElmt_inventory(_inventory, 0, pakai_gadget);
                if (pakai_gadget[0]=='-')
                {
                    printf("Tidak ada Gadget yang dapat digunakan!\n");
                }
                else
                {
                    SetElmnt_inventory(&_inventory, 0, "-");
                    printf("%s berhasil digunakan\n", pakai_gadget);
                    // Cek apakah nama gadget
                    if(strcmp_main(pakai_gadget, "Pintu Kemana Saja") == true) {
                        printf("Lokasi Tujuan: ");
                        startWordInput();
                        Word teleport = currentWord;
                        if (KataToChar(teleport) == '8')
                        {
                            _currentLocBuilding = '8';
                            _currentLocPOINT = MakePOINT(x_hq,y_hq);
                            if (_currentLocBuilding == '8' && isEmptysorted_pesanan(sq) && isEmptyLL(TL) && isEmptyTas(backpack) && isEmptyLL(_ListOfProggress)) {
                                FINISH = true;
                                return;
                            }      
                        }
                        else
                        {
                            if (NEQPOINT(MakePOINT(-1, -1), showLocation_ListBangunan(tole, KataToChar(teleport)))) {
                                _currentLocBuilding = KataToChar(teleport);
                                _currentLocPOINT = showLocation_ListBangunan(tole, KataToChar(teleport));
                                printf("Anda telah tiba di lokasi\n");
                            } else {
                                printf("Lokasi tidak ditemukan\n");
                                SetElmnt_inventory(&_inventory, 0, "Pintu Kemana Saja");
                            }
                        }
                    }
                    if(strcmp_main(pakai_gadget, "Mesin Waktu") == true) {
                        _time = _time-50<0 ? 0 : _time-50;
                    }
                    if(strcmp_main(pakai_gadget, "Kain Pembungkus Waktu") == true) {
                        Tas temp;
                        CreateTas(&temp);
                        ElTypeTas sampah;
                        int idx = 0;
                        boolean found = false;
                        while(!isEmptyTas(backpack) && !found) {
                            ElTypeNODELL itemDiInP = getElmtLL(_ListOfProggress, idx);
                            popTas(&backpack,&sampah);
                            if (sampah.itemtype == 'P') {
                                sampah.timelimit = sampah.timelimit_original;
                                itemDiInP.timelimit = sampah.timelimit;
                                setElmtLL(&_ListOfProggress, idx, itemDiInP);
                                pushTas(&backpack,sampah);
                                found = true;
                            } else {
                                pushTas(&temp,sampah);
                                idx++;
                            } 
                        }

                        while(!isEmptyTas(temp)) {
                            popTas(&temp, &sampah);
                            pushTas(&backpack, sampah);
                        }
                    }

                    if(strcmp_main(pakai_gadget, "Senter Pembesar") == true) {
                       _kapasitasTas = (_kapasitasTas*2)-100 < 0 ? (_kapasitasTas*2) : 100; 
                    }
                }
                break;
            case 2:
                GetElmt_inventory(_inventory, 1, pakai_gadget);
                if (pakai_gadget[0]=='-')
                {
                    printf("Tidak ada Gadget yang dapat digunakan!\n");
                }
                else
                {
                    SetElmnt_inventory(&_inventory, 1, "-");
                    printf("%s berhasil digunakan\n", pakai_gadget);
                    // Cek apakah nama gadget
                    if(strcmp_main(pakai_gadget, "Pintu Kemana Saja") == true) {
                        printf("Lokasi Tujuan: ");
                        startWordInput();
                        Word teleport = currentWord;
                        if (KataToChar(teleport) == '8')
                        {
                            _currentLocBuilding = '8';
                            _currentLocPOINT = MakePOINT(x_hq,y_hq);
                            if (_currentLocBuilding == '8' && isEmptysorted_pesanan(sq) && isEmptyLL(TL) && isEmptyTas(backpack) && isEmptyLL(_ListOfProggress)) {
                                FINISH = true;
                                return;
                            } 
                        }
                        else
                        {
                            if (NEQPOINT(MakePOINT(-1, -1), showLocation_ListBangunan(tole, KataToChar(teleport)))) {
                                _currentLocBuilding = KataToChar(teleport);
                                _currentLocPOINT = showLocation_ListBangunan(tole, KataToChar(teleport));
                                printf("Anda telah tiba di lokasi\n");
                            } else {
                                printf("Lokasi tidak ditemukan\n");
                                SetElmnt_inventory(&_inventory, 1, "Pintu Kemana Saja");
                            }
                        }
                    }
                    if(strcmp_main(pakai_gadget, "Mesin Waktu") == true) {
                        _time = _time-50<0 ? 0 : _time-50;
                    }
                    if(strcmp_main(pakai_gadget, "Kain Pembungkus Waktu") == true) {
                        Tas temp;
                        CreateTas(&temp);
                        ElTypeTas sampah;
                        int idx = 0;
                        boolean found = false;
                        while(!isEmptyTas(backpack) && !found) {
                            ElTypeNODELL itemDiInP = getElmtLL(_ListOfProggress, idx);
                            popTas(&backpack,&sampah);
                            if (sampah.itemtype == 'P') {
                                sampah.timelimit = sampah.timelimit_original;
                                itemDiInP.timelimit = sampah.timelimit;
                                setElmtLL(&_ListOfProggress, idx, itemDiInP);
                                pushTas(&backpack,sampah);
                                found = true;
                            } else {
                                pushTas(&temp,sampah);
                                idx++;
                            } 
                        }

                        while(!isEmptyTas(temp)) {
                            popTas(&temp, &sampah);
                            pushTas(&backpack, sampah);
                        }
                    }

                    if(strcmp_main(pakai_gadget, "Senter Pembesar") == true) {
                        _kapasitasTas = (_kapasitasTas*2)-100 < 0 ? (_kapasitasTas*2) : 100; 
                    }
                }
                break;
            case 3:
                GetElmt_inventory(_inventory, 2, pakai_gadget);
                if (pakai_gadget[0]=='-')
                {
                    printf("Tidak ada Gadget yang dapat digunakan!\n");
                }
                else
                {
                    SetElmnt_inventory(&_inventory, 2, "-");
                    printf("%s berhasil digunakan\n", pakai_gadget);
                    // Cek apakah nama gadget
                    if(strcmp_main(pakai_gadget, "Pintu Kemana Saja") == true) {
                        printf("Lokasi Tujuan: ");
                        startWordInput();
                        Word teleport = currentWord;
                        if (KataToChar(teleport) == '8')
                        {
                            _currentLocBuilding = '8';
                            _currentLocPOINT = MakePOINT(x_hq,y_hq);
                            if (_currentLocBuilding == '8' && isEmptysorted_pesanan(sq) && isEmptyLL(TL) && isEmptyTas(backpack) && isEmptyLL(_ListOfProggress)) {
                                FINISH = true;
                                return;
                            } 
                        }
                        else
                        {
                            if (NEQPOINT(MakePOINT(-1, -1), showLocation_ListBangunan(tole, KataToChar(teleport)))) {
                                _currentLocBuilding = KataToChar(teleport);
                                _currentLocPOINT = showLocation_ListBangunan(tole, KataToChar(teleport));
                                printf("Anda telah tiba di lokasi\n");
                            } else {
                                printf("Lokasi tidak ditemukan\n");
                                SetElmnt_inventory(&_inventory, 2, "Pintu Kemana Saja");
                            }
                        }
                    }
                    if(strcmp_main(pakai_gadget, "Mesin Waktu") == true) {
                        _time = _time-50<0 ? 0 : _time-50;
                    }
                    if(strcmp_main(pakai_gadget, "Kain Pembungkus Waktu") == true) {
                        Tas temp;
                        CreateTas(&temp);
                        ElTypeTas sampah;
                        int idx = 0;
                        boolean found = false;
                        while(!isEmptyTas(backpack) && !found) {
                            ElTypeNODELL itemDiInP = getElmtLL(_ListOfProggress, idx);
                            popTas(&backpack,&sampah);
                            if (sampah.itemtype == 'P') {
                                sampah.timelimit = sampah.timelimit_original;
                                itemDiInP.timelimit = sampah.timelimit;
                                setElmtLL(&_ListOfProggress, idx, itemDiInP);
                                pushTas(&backpack,sampah);
                                found = true;
                            } else {
                                pushTas(&temp,sampah);
                                idx++;
                            } 
                        }

                        while(!isEmptyTas(temp)) {
                            popTas(&temp, &sampah);
                            pushTas(&backpack, sampah);
                        }
                    }

                    if(strcmp_main(pakai_gadget, "Senter Pembesar") == true) {
                        _kapasitasTas = (_kapasitasTas*2)-100 < 0 ? (_kapasitasTas*2) : 100; 
                    }
                }
                break;
            case 4:
                GetElmt_inventory(_inventory, 3, pakai_gadget);
                if (pakai_gadget[0]=='-')
                {
                    printf("Tidak ada Gadget yang dapat digunakan!\n");
                }
                else
                {
                    SetElmnt_inventory(&_inventory, 3, "-");
                    printf("%s berhasil digunakan\n", pakai_gadget);
                    // Cek apakah nama gadget
                    if(strcmp_main(pakai_gadget, "Pintu Kemana Saja") == true) {
                        printf("Lokasi Tujuan: ");
                        startWordInput();
                        Word teleport = currentWord;
                        if (KataToChar(teleport) == '8')
                        {
                            _currentLocBuilding = '8';
                            _currentLocPOINT = MakePOINT(x_hq,y_hq);
                            if (_currentLocBuilding == '8' && isEmptysorted_pesanan(sq) && isEmptyLL(TL) && isEmptyTas(backpack) && isEmptyLL(_ListOfProggress)) {
                                FINISH = true;
                                return;
                            } 
                        }
                        else
                        {
                            if (NEQPOINT(MakePOINT(-1, -1), showLocation_ListBangunan(tole, KataToChar(teleport)))) {
                                _currentLocBuilding = KataToChar(teleport);
                                _currentLocPOINT = showLocation_ListBangunan(tole, KataToChar(teleport));
                                printf("Anda telah tiba di lokasi\n");
                            } else {
                                printf("Lokasi tidak ditemukan\n");
                                SetElmnt_inventory(&_inventory, 3, "Pintu Kemana Saja");
                            }
                        }
                    }
                    if(strcmp_main(pakai_gadget, "Mesin Waktu") == true) {
                        _time = _time-50<0 ? 0 : _time-50;
                    }
                    if(strcmp_main(pakai_gadget, "Kain Pembungkus Waktu") == true) {
                        Tas temp;
                        CreateTas(&temp);
                        ElTypeTas sampah;
                        int idx = 0;
                        boolean found = false;
                        while(!isEmptyTas(backpack) && !found) {
                            ElTypeNODELL itemDiInP = getElmtLL(_ListOfProggress, idx);
                            popTas(&backpack,&sampah);
                            if (sampah.itemtype == 'P') {
                                sampah.timelimit = sampah.timelimit_original;
                                itemDiInP.timelimit = sampah.timelimit;
                                setElmtLL(&_ListOfProggress, idx, itemDiInP);
                                pushTas(&backpack,sampah);
                                found = true;
                            } else {
                                pushTas(&temp,sampah);
                                idx++;
                            } 
                        }

                        while(!isEmptyTas(temp)) {
                            popTas(&temp, &sampah);
                            pushTas(&backpack, sampah);
                        }
                    }

                    if(strcmp_main(pakai_gadget, "Senter Pembesar") == true) {
                        _kapasitasTas = (_kapasitasTas*2)-100 < 0 ? (_kapasitasTas*2) : 100; 
                    }
                }
                break;
            case 5:
                GetElmt_inventory(_inventory, 4, pakai_gadget);
                if (pakai_gadget[0]=='-')
                {
                    printf("Tidak ada Gadget yang dapat digunakan!\n");
                }
                else
                {
                    SetElmnt_inventory(&_inventory, 4, "-");
                    printf("%s berhasil digunakan\n", pakai_gadget);
                    // Cek apakah nama gadget
                    if(strcmp_main(pakai_gadget, "Pintu Kemana Saja") == true) {
                        printf("Lokasi Tujuan: ");
                        startWordInput();
                        Word teleport = currentWord;
                        if (KataToChar(teleport) == '8')
                        {
                            _currentLocBuilding = '8';
                            _currentLocPOINT = MakePOINT(x_hq,y_hq);
                            if (_currentLocBuilding == '8' && isEmptysorted_pesanan(sq) && isEmptyLL(TL) && isEmptyTas(backpack) && isEmptyLL(_ListOfProggress)) {
                                FINISH = true;
                                return;
                            } 
                        }
                        else
                        {
                            if (NEQPOINT(MakePOINT(-1, -1), showLocation_ListBangunan(tole, KataToChar(teleport)))) {
                                _currentLocBuilding = KataToChar(teleport);
                                _currentLocPOINT = showLocation_ListBangunan(tole, KataToChar(teleport));
                                printf("Anda telah tiba di lokasi\n");
                            } else {
                                printf("Lokasi tidak ditemukan\n");
                                SetElmnt_inventory(&_inventory, 4, "Pintu Kemana Saja");
                            }
                        }
                    }
                    if(strcmp_main(pakai_gadget, "Mesin Waktu") == true) {
                        _time = _time-50<0 ? 0 : _time-50;
                    }
                    if(strcmp_main(pakai_gadget, "Kain Pembungkus Waktu") == true) {
                        Tas temp;
                        CreateTas(&temp);
                        ElTypeTas sampah;
                        
                        int idx = 0;
                        boolean found = false;
                        while(!isEmptyTas(backpack) && !found) {
                            ElTypeNODELL itemDiInP = getElmtLL(_ListOfProggress, idx);
                            popTas(&backpack,&sampah);
                            if (sampah.itemtype == 'P') {
                                sampah.timelimit = sampah.timelimit_original;
                                itemDiInP.timelimit = sampah.timelimit;
                                setElmtLL(&_ListOfProggress, idx, itemDiInP);
                                pushTas(&backpack,sampah);
                                found = true;
                            } else {
                                pushTas(&temp,sampah);
                                idx++;
                            } 
                        }

                        while(!isEmptyTas(temp)) {
                            popTas(&temp, &sampah);
                            pushTas(&backpack, sampah);
                        }
                    }

                    if(strcmp_main(pakai_gadget, "Senter Pembesar") == true) {
                        _kapasitasTas = (_kapasitasTas*2)-100 < 0 ? (_kapasitasTas*2) : 100; 
                    }
                }
                break;
            default:
                printf("Command Anda Salah!\n");
                break;
        }
    } else if (IsCommandSama(currentWord,StringToKata("BUY"))) {
        if (EQPOINT(MakePOINT(x_hq, y_hq), _currentLocPOINT)) {
            printf("\nUang anda sekarang: %d Yen\n", _money);
            printf("Gadget yang tersedia:\n");
            printf("1. Kain Pembungkus Waktu (800 Yen)\n");
            printf("2. Senter Pembesar (1200 Yen)\n");
            printf("3. Pintu Kemana Saja (1500 Yen)\n");
            printf("4. Mesin Waktu (3000 Yen)\n");
            printf("Gadget mana yang ingin dibeli? (ketik 0 jika ingin kembali)\n\n");
            printf("ENTER COMMAND: "); startWordInput();
            int buy_item = KataToInt(currentWord);
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
                        printf("Uang tidak cukup untuk membeli gadget!\n");
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
                        printf("Uang tidak cukup untuk membeli gadget!\n");
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
                        printf("Uang tidak cukup untuk membeli gadget!\n");
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
                        printf("Uang tidak cukup untuk membeli gadget!\n");
                        break;
                    }
                    break;
                default:
                    printf("Command Anda Salah!\n");
                    break;
            }
        } else {
            printf("Anda harus ke HQ untuk membeli barang!\n");
        }
    }
    else if (IsCommandSama(currentWord,StringToKata("DROP_OFF"))) {
        dropoff_command();
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
    printf("masukkan nama file: "); startWordInput();
    endl;
    char* filenamewithext = KataToString(concatKata(StringToKata("savefile/"),(concatKata(currentWord, StringToKata(".txt")))));
    load_data(filenamewithext);
    if (!fileFound) {
        printf("Sorry, Failed to Load that...\nExiting...");
    } else {
        printf("%s has been loaded...\nEnjoy\n\n", filenamewithext);
        while (!EXIT && !FINISH) {
            displayStats();
            printf("\n");
        }
        if (EXIT) {
            printf("Terima Kasih telah bermain bersama kami\n");
        } else if (FINISH) {
            printf("Selamat, Anda telah menyelesaikan permainan!!\n");
            printf("---------------------------------------------\n");
            printf("Total pesanan diselesaikan : %d\n", jmlPesanan-_perishableLoss);
            printf("Waktu selesai  : %d\n", _time);
            printf("Uang terkumpul : %d Yen\n", _money);
        } else {
            printf("Error, Something went wrong...\n");
        }
        printf("Exiting...\n");
    }
}