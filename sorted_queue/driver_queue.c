// 10
// 1 G N N
// 3 G N H
// 2 B M N
// 1 M B H
// 5 C D N
// 3 F E N
// 10 P Q P 20
// 5 G N P 10
// 8 O P V
// 8 Q L V

#include "sorted_queue.h"
#include "../configuration_c/charmachine.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // jumlahPesanan variable1;
    // jumlahPesanan variable2;
    // jumlahPesanan variable3;

    // variable1.time = 1;
    // variable1.pickup = 'G';
    // variable1.dropoff = 'N';
    // variable1.itemtype = 'N';
    // variable1.timelimit = -1;

    // variable2.time = 10;
    // variable2.pickup = 'P';
    // variable2.dropoff = 'Q';
    // variable2.itemtype = 'P';
    // variable2.timelimit = 20;

    // variable3.time = 5;
    // variable3.pickup = 'C';
    // variable3.dropoff = 'D';
    // variable3.itemtype = 'N';
    // variable3.timelimit = -1;

    // SortedQueue* sq = createSortedQueue();

    // pushSortedQueue(sq, variable1);
    // pushSortedQueue(sq, variable2);
    // pushSortedQueue(sq, variable3);

    // printf("%d %d %d\n", sq->root->data.time, sq->root->next->data.time, sq->root->next->next->data.time);

    startWOA("test.txt");

    jumlahPesanan* arr;
    int len;
    arr = konfigurasiC(&len);
    printf("%d\n", len);

    for (int i=0; i < len; i++)
    {
        printf("%d %c %c %c %d\n",  arr[i].time, arr[i].pickup, arr[i].dropoff, arr[i].itemtype, arr[i].timelimit);
    }

    SortedQueue* sq = makeSQ(arr, len);


    printf("\nSetelah di sort:\n");
    while(!isEmptySortedQueue(sq)) {
        jumlahPesanan out = popSortedQueue(sq);
        printf("%d %c %c %c %d\n",  out.time, out.pickup, out.dropoff, out.itemtype, out.timelimit);

    }
    return 0;
}

// Hasil Terminal:
// ---------------

// 10
// 1 G N N -1
// 3 G N H -1
// 2 B M N -1
// 1 M B H -1
// 5 C D N -1
// 3 F E N -1
// 10 P Q P 20
// 5 G N P 10
// 8 O P V -1
// 8 Q L V -1

// Setelah di sort:
// 1 G N N -1
// 1 M B H -1
// 2 B M N -1
// 3 G N H -1
// 3 F E N -1
// 5 C D N -1
// 5 G N P 10
// 8 O P V -1
// 8 Q L V -1
// 10 P Q P 20