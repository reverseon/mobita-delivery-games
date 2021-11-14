#ifndef LOAD_DATA_H
#define LOAD_DATA_H

#include <stdio.h>
#include "loadadt.h"
// #include "../sorted_queue/sorted_queue.h"
// #include "../linked_list/todolist.h"
// #include "../linked_list/node.h"
// #include "../stack/stack.h"

int max,row,col;
int jmlPesanan;
int x_hq,y_hq;
jumlahPesanan* J; 
ListBangunan tole;
Matrix adjacencyMatrix;
POINT _currentLocPOINT;
char _currentLocBuilding;
int _time;
int _money;
sorted_pesanan* sq;
ToDoList TL;
Tas backpack;
<<<<<<< HEAD
int _waktuTambahan;
ProgressList _ListOfProggress;
=======
>>>>>>> 7d58e1bd1b819bed2f7a560b43ac4067d8530fc8


jumlahPesanan* konfigurasiC(int a);
void load_data(char* filename);

#endif