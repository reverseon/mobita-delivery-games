#ifndef KONFIGURASI_C_H
#define KONFIGURASI_C_H

#include "charmachine.h"
#include <stdlib.h>

typedef struct jumlahPesanan jumlahPesanan;
struct jumlahPesanan
{
    int time;
    char pickup;
    char dropoff;
    char itemtype;
    int timelimit;
};

typedef struct {
    int a[27][27];
    int rEff;
    int cEff;
} adjM;


jumlahPesanan* konfigurasiC(int a);
// Mereturn array of struct yang terbentuk
// lalu menggantii arrlen menjadi panjang array of struct


// OPERASI TENTANG adjM
adjM loadAdjM(int nBuild);
void displayRel(adjM a);

#endif