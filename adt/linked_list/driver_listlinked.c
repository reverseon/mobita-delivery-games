#include <stdio.h>
#include <stdlib.h>
#include "list_linked.h"

int main(){
    ListLL l;
    PesananLL pl;
    CreateListLL(&l);

    //inisiasi contoh list
    pl.pickup = 'A';
    pl.dropoff = 'B';
    pl.itemtype = 'N';
    pl.timelimit = -1;
    insertFirstLL(&l,pl);
    pl.pickup = 'G';
    pl.dropoff = 'C';
    pl.itemtype = 'H';
    pl.timelimit = -1;
    insertLastLL(&l,pl);
    pl.pickup = 'M';
    pl.dropoff = 'O';
    pl.itemtype = 'P';
    pl.timelimit = 10;
    insertAtLL(&l,pl,1);

    printf("Hasil inisiasi: ");
    displayListLL(l);
    printf("\n");

    
    return 0;
}