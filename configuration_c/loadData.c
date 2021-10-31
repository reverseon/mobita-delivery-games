#include <stdio.h>
#include "listdin.h"
#include "charmachine.h"
#include "wordmachine.h"
#include "konfigurasi_c.h"
#include "loadData.h"
#include "point.h"

void load_data(char* filename){
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
    //insertBuildingInfo(&tole,'8',x_hq,y_hq);

    advWord();

    // jumlah capacity array dinamis
    max=KataToInt(currentWord);
    
    advWord();

    // Masukin data semua bangunan ke array dinamis
    tole = insertABuilding(max);

    // masukin data adjacency matriks
    M = loadAdjM(max);
    
    // masukin data jumlahPesanan
    jmlPesanan = KataToInt(currentWord);
    advWord();
    J = konfigurasiC(jmlPesanan);
}