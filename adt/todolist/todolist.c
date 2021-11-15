#include <stdio.h>
#include "todolist.h"

void displayTodoList(ToDoList l)
// void printInfo(ToDoList l);
/* I.S. ToDoList mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    int counter = 0;
    ElTypeNODELL val;
    while(counter < lengthLL(l)) {
        val = getElmtLL(l, counter);
        if (val.itemtype == 'N'){
            printf("%d. %c -> %c (Normal Item)\n", counter+1, val.pickup, val.dropoff);
        } else if(val.itemtype == 'H'){
            printf("%d. %c -> %c (Heavy Item)\n", counter+1, val.pickup, val.dropoff);
        } else if(val.itemtype == 'P'){
            printf("%d. %c -> %c (Perishable Item, sisa waktu %d)\n", counter+1, val.pickup, val.dropoff, val.timelimit);
        } else if(val.itemtype == 'V'){
            printf("%d. %c -> %c (VIP Item)\n", counter+1, val.pickup, val.dropoff);
        }
        counter++;
    }
    if(isEmptyLL(l)){
        printf("Tidak ada task yang harus dikerjakan.\n");
    }
}

void addQueuetoTodo(ToDoList *l , sorted_pesanan *SQ){
    jumlahPesanan val = popsorted_pesanan(SQ);
    PesananLL pesanan;
    pesanan.pickup = val.pickup;
    pesanan.dropoff = val.dropoff;
    pesanan.itemtype = val.itemtype;
    pesanan.timelimit = val.timelimit;
    pesanan.timelimit_original = val.timelimit;
    insertLastLL(l, pesanan);
}