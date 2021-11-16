#include <stdio.h>
#include "inprogress.h"

void displayProgressList(ProgressList l)
// void printInfo(ProgressList l);
/* I.S. ProgressList mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    if(isEmptyLL(l)){
        printf("Tidak ada task yang sedang dikerjakan.\n");
    } else {
        Tas tempDis;
        CreateTas(&tempDis);
        AddressNODELL op = FIRSTLL(l);
        int counter = 0;
        ElTypeNODELL val;
        while(op != NULL) {
            pushTas(&tempDis, INFONODELL(op));
            op = NEXTNODELL(op);
        }
        while (!isEmptyTas(tempDis)) {
            popTas(&tempDis, &val);
            if (val.itemtype == 'N'){
                printf("%d. Normal Item (Tujuan: %c)\n", counter+1, val.dropoff);
            } else if(val.itemtype == 'H'){
                printf("%d. Heavy Item (Tujuan: %c)\n", counter+1, val.dropoff);
            } else if(val.itemtype == 'P'){
                printf("%d. Perishable Item (Tujuan: %c, sisa waktu: %d)\n", counter+1, val.dropoff, val.timelimit);
            } else if(val.itemtype == 'V'){
                printf("%d. VIP Item (Tujuan: %c)\n", counter+1, val.dropoff);
            }
            counter++;
        }
    }
}

void addTodotoProgress(ProgressList *l, ToDoList *tl, char locationbuilding)
{
    int index = indexOfPickupLL(*tl,locationbuilding);
    if(index >= 0){
        PesananLL pesanan = getElmtLL(*tl, index);
        insertFirstLL(l, pesanan);
    }
}