#include <stdio.h>
#include <stdlib.h>
#include "todolist.h"

/* Definisi ToDoList : */
/* ToDoList kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateTodoList(ToDoList *l)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isTodoEmpty(ToDoList l)
/* Mengirim true jika list kosong */
{
    return (FIRST(l) == NULL);
}

/****************** GETTER SETTER ******************/
TipeEl getTodoElmt(ToDoList l, int idx)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..lengthTodoList(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
{
    int i;
    for (i = 0; i < idx; i++){
        l = NEXT(l);
    }
    return (INFO(l));
}

int indexOfTodo(ToDoList l, TipeEl val)
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDXTODO_UNDEF jika tidak ditemukan */
{
    boolean found = false;
    int count = 0;
    while (!found && (l != NULL)){
        if (INFO(l).pickup == val.pickup && INFO(l).dropoff == val.dropoff && INFO(l).itemtype == val.itemtype && INFO(l).timelimit == val.timelimit){
            found = true;
        } else {
            l = NEXT(l);
            count++;
        }
    }
    if (found) {
        return count;
    } else {
        return IDXTODO_UNDEF;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirstTodo(ToDoList *l, jumlahPesanan val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
{
    ToDoList p;
    p = newNode(val);
    if (p != NULL) {
        NEXT(p) = *l;
        *l = p;
    }
}

void insertLastTodo(ToDoList *l, jumlahPesanan val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    ToDoList p, last;
    if (isTodoEmpty(*l)){
        insertFirstTodo(l, val);
    } else {
        p = newNode(val);
        if (p != NULL){
            last = *l;
            while (NEXT(last) != NULL){
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }
}

void insertAtTodo(ToDoList *l, jumlahPesanan val, int idx)
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..lengthTodoList(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    int counter;
    ToDoList p, loc;
    if (idx == 0){
        insertFirstTodo(l, val);
    } else {
        p = newNode(val);
        if (p != NULL) {
            counter = 0;
            loc = *l;
            while (counter < idx-1) {
                counter++;
                loc = NEXT(loc);
            }
            NEXT(p) = NEXT(loc);
            NEXT(loc) = p;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirstTodo(ToDoList *l, TipeEl *val)
/* I.S. ToDoList l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
{
    ToDoList p;
    p = *l;
    *val = INFO(p);
    *l = NEXT(p);
    free(p);
}
void deleteLastTodo(ToDoList *l, TipeEl *val)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
{
    ToDoList p, loc;
    p = *l;
    loc = NULL;
    while (NEXT(p) != NULL) {
        loc = p;
        p = NEXT(p);
    }
    if (loc == NULL) {
        *l = NULL;
    } else {
        NEXT(loc) = NULL;
    }
    *val = INFO(p);
    free(p);
}

void deleteAtTodo(ToDoList *l, int idx, TipeEl *val)
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..lengthTodoList(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
{
    int counter;
    ToDoList p, loc;
    if (idx == 0) {
        deleteFirstTodo(l, val);
    } else {
        counter = 0;
        loc = *l;
        while (counter < idx-1) {
            counter++;
            loc = NEXT(loc);
        }
        p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayTodoList(ToDoList l)
// void printInfo(ToDoList l);
/* I.S. ToDoList mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    int counter = 0;
    TipeEl val;
    while(counter < lengthTodoList(l)) {
        val = getTodoElmt(l, counter);
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
}

int lengthTodoList(ToDoList l)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int count = 0;
    while (l != NULL){
        l = NEXT(l);
        count++;
    }
    return count;
}


void addQueuetoTodo(ToDoList *l , SortedQueue *SQ){
    jumlahPesanan val = popSortedQueue(SQ);
    insertLastTodo(l, val);
}