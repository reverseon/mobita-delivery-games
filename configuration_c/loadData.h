#ifndef LOAD_DATA_H
#define LOAD_DATA_H

#include <stdio.h>
#include "listdin.h"
#include "charmachine.h"
#include "wordmachine.h"
#include "konfigurasi_c.h"
#include "point.h"

int max,row,col;
int jmlPesanan;
int x_hq,y_hq;
jumlahPesanan* J; 
ArrDin tole;
adjM M;

int load_data(char* filename);

#endif