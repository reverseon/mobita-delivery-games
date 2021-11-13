#ifndef TODOLIST_H
#define TODOLIST_H

#include "../linked_list/list_linked.h"
#include "../queue_pesanan/queue_pesanan.h"
#include "../load/jumlahPesanan.h"

typedef ListLL ToDoList;

void displayTodoList(ToDoList l);
// void printInfo(ToDoList l);
/* I.S. ToDoList mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

void addQueuetoTodo(ToDoList *l , sorted_pesanan *SQ);

#endif