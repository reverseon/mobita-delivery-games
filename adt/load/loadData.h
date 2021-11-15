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
int _waktuTambahan;
ProgressList _ListOfProggress;
List_inventory _inventory;
boolean _speedBoost;
boolean _incCapacity;
boolean _returnToSender;
int _moveCounter;
int _kapasitasTas;
jumlahPesanan* konfigurasiC(int a);
void load_data(char* filename);

#endif