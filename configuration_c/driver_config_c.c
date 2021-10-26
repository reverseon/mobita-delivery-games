#include "konfigurasi_c.h"
#include "charmachine.h"
#include <stdio.h>

// ONLY FOR DISPLAY PURPOSES
void dispRel(adjM a) {
    for (int i = 0; i < 18; i++) {
        if (i == 0) {
            printf("Relasi ke HQ: ");
        } else {
            printf("Relasi Bangunan ke-%i: ", i);
        }
        for (int j = 0; j < 18; j++) {
            if (a.a[i][j] == 1) {
                printf("%i ", j);
            }
        }
        printf("\n");
    }
}

int main()
{
    start("test.txt");
    dispRel(loadAdjM(17));
    printf("\n");
    jumlahPesanan* arr;
    int len;
    arr = konfigurasiC(&len);
    printf("%d\n", len);

    for (int i=0; i < len; i++)
    {
        printf("%d %c %c %c %d\n",  arr[i].time, arr[i].pickup, arr[i].dropoff, arr[i].itemtype, arr[i].timelimit);
    }

    return 0;
}
