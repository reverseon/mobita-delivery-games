#include <stdio.h>
#include "listdin.h"
#include "charmachine.h"
#include "wordmachine.h"
#include "konfigurasi_c.h"
#include "loadData.h"
#include "point.h"
#include "../sorted_queue/sorted_queue.h"
#include "../linked_list/todolist.h"
#include "../linked_list/node.h"

void load_data(char* filename){
    _time = 0;
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
    tole = insertABuilding(max);

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
}