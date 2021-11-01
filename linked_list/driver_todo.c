#include "todolist.h"
#include "../configuration_c/wordmachine.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
    // driver uintuk contoh pemakaian todo list
    
    startWord("test.txt");

    ToDoList TL;

    jumlahPesanan* arr;
    int len = KataToInt(currentWord);
    advWord();advWord();
    arr = konfigurasiC(len);

    SortedQueue* sq = makeSQ(arr, len);

    printf("\n");

    // misalkan time = 4

    int time = 6;

    jumlahPesanan out = sq->root->data;
    while(out.time <= time){
        addQueuetoTodo(&TL, sq);
        out = sq->root->data;
    } 

    displayTodoList(TL);

    return 0;
}