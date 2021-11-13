#ifndef PROGRESSLIST_H
#define PROGRESSLIST_H

#include "../linked_list/list_linked.h"
#include "../load/loadadt.h"

typedef ListLL ProgressList;

void displayProgressList(ProgressList l);
// void printInfo(ToDoList l);
/* I.S. ToDoList mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

void addTodotoProgress(ProgressList *l, ToDoList *tl, char locationbuilding);

#endif