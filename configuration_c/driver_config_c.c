#include "konfigurasi_c.h"

#include <stdio.h>

int main()
{
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
