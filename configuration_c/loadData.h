#ifndef LOAD_DATA_H
#define LOAD_DATA_H

#include <stdio.h>
#include "listdin.h"
#include "charmachine.h"
#include "wordmachine.h"
#include "konfigurasi_c.h"
#include "point.h"
#include "../sorted_queue/sorted_queue.h"
#include "../linked_list/todolist.h"
#include "../linked_list/node.h"

int max,row,col;
int jmlPesanan;
int x_hq,y_hq;
jumlahPesanan* J; 
ArrDin tole;
adjM adjacencyMatrix;
POINT _currentLocPOINT;
char _currentLocBuilding;
int _time;
int _money;
SortedQueue* sq;
ToDoList TL;

void load_data(char* filename);

#endif