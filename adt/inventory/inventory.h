/* MODUL LIST INTEGER DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer dengan elemen
   positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori array statik */

#ifndef _INVENTORY_H_
#define _INVENTORY_H_

/*  Kamus Umum */
#define STRING_SIZE 256

typedef struct {
   char elmt0[STRING_SIZE];
   char elmt1[STRING_SIZE];
   char elmt2[STRING_SIZE];
   char elmt3[STRING_SIZE];
   char elmt4[STRING_SIZE];
} List_inventory;

void CreateList_inventory(List_inventory* l);

void SetElmnt_inventory(List_inventory* l, int index, char* newVal);

void GetElmt_inventory(List_inventory l, int index, char* returnVal);

void display_inventory(List_inventory l);

#endif
