#include "charmachine.h"
#include "konfigurasi_c.h"
#include "wordmachine.h"
#include <stdlib.h>
#include <stdio.h>

jumlahPesanan* konfigurasiC(int jumlah)
{

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

adjM loadAdjM(int nBuild) {
    adjM adjMap;
    adjMap.rEff = nBuild+1;
    adjMap.cEff = nBuild+1;
    int i ; // CONTROL
    int j ;
    for (i = 0 ; i < adjMap.rEff; i++ ){
        for (j = 0 ; j < adjMap.cEff; j++) {
            adjMap.a[i][j] = KataToInt(currentWord);
            advWord();
        }
    }
    return adjMap;
}

void displayRel(adjM a) {
    for (int i = 0; i < a.rEff; i++) {
        if (i == 0) {
            printf("Relasi ke HQ: ");
        } else {
            printf("Relasi Bangunan ke-%i: ", i);
        }
        for (int j = 0; j < a.cEff; j++) {
            if (a.a[i][j] == 1) {
                printf("%i ", j);
            }
        }
        printf("\n");
    }
}
