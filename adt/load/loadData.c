#include <stdio.h>
#include "loadData.h"
#include "../inventory/inventory.h"

jumlahPesanan* konfigurasiC(int jumlah) {

    jumlahPesanan* array = malloc(sizeof(jumlahPesanan)*jumlah);
    int len = jumlah;
    int index = 0;

    while(jumlah--)
    {
        array[index].time = KataToInt(currentWord);
        advWord();
        array[index].pickup = KataToChar(currentWord);
        advWord();
        array[index].dropoff = KataToChar(currentWord);
        advWord();
        array[index].itemtype = KataToChar(currentWord);
        
        if (array[index].itemtype=='P')
        {
            advWord();
            array[index].timelimit = KataToInt(currentWord);
            advWord();
        }
        /// Apabila bukan perishable ditandai dengan -1 biar gampang aja
        else
        {
            array[index].timelimit = -1;
            advWord();
        }

        index += 1;
    }

    return array;
}

void load_data(char* filename){
    // Membuat inventory kosong
    CreateList_inventory(&_inventory);
    // SetElmnt_inventory(&_inventory, 0, "Senter Pembesar");
    // SetElmnt_inventory(&_inventory, 3, "Mesin Waktu");

    _time = 0;
    _waktuTambahan=0;
    _money = 0;
    jmlPesanan = 0;
    startWord(filename);

    // input atas buat ukuran matriks
    row = KataToInt(currentWord);
    advWord();advWord();
    col = KataToInt(currentWord);
    
    advWord();

    /*masukin headquarter ke array dinamis */
    x_hq = KataToInt(currentWord);
    advWord();
    y_hq = KataToInt(currentWord);
    _currentLocPOINT = MakePOINT(x_hq, y_hq);
    _currentLocBuilding = '8';
    //insertBuildingInfo(&tole,'8',x_hq,y_hq);

    advWord();

    // jumlah capacity array dinamis
    max=KataToInt(currentWord);
    
    advWord();

    // Masukin data semua bangunan ke array dinamis
    tole = insertABuilding_ListBangunan(max);

    // masukin data adjacency matriks
    adjacencyMatrix = loadAdjM(max);
    
    // masukin data jumlahPesanan
    jmlPesanan = KataToInt(currentWord);
    advWord();
    J = konfigurasiC(jmlPesanan);

    sq = makeSQ(J, jmlPesanan);
    jumlahPesanan out = sq->root->data;
    while(out.time <= _time){
        addQueuetoTodo(&TL, sq);
        out = sq->root->data;
    } 

    CreateTas(&backpack);
    CreateListLL(&_ListOfProggress);
    CreateListLL(&TL);
}