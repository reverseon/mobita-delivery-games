#ifndef LOAD_DATA_H
#define LOAD_DATA_H

#include <stdio.h>
#include "loadadt.h"
// #include "../sorted_queue/sorted_queue.h"
// #include "../linked_list/todolist.h"
// #include "../linked_list/node.h"
// #include "../stack/stack.h"

typedef struct jumlahPesanan jumlahPesanan;
struct jumlahPesanan
{
    int time;
    char pickup;
    char dropoff;
    char itemtype;
    int timelimit;
};

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
SortedQueue* sq;
ToDoList TL;


jumlahPesanan* konfigurasiC(int a);
void load_data(char* filename);

#endif