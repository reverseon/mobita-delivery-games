#ifndef JUMLAH_PESANAN_H
#define JUMLAH_PESANAN_H

typedef struct jumlahPesanan jumlahPesanan;
struct jumlahPesanan
{
    int time;
    char pickup;
    char dropoff;
    char itemtype;
    int timelimit;
};

#endif