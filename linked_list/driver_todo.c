#include "inprogress.h"
#include "../configuration_c/wordmachine.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
    // driver uintuk contoh pemakaian todo list
    
    startWord("test.txt");

    ToDoList TL;
    CreateTodoList(&TL);

    ProgressList PL;
    CreateProgressList(&PL);

    jumlahPesanan* arr;
    int len = KataToInt(currentWord);
    advWord();advWord();
    arr = konfigurasiC(len);

    SortedQueue* sq = makeSQ(arr, len);

    printf("\n");

    // misalkan time = 6

    int time = 6;

    jumlahPesanan out = sq->root->data;
    while(out.time <= time){
        addQueuetoTodo(&TL, sq);
        out = sq->root->data;
    } 

    displayTodoList(TL);

    char locationbuilding = 'C';
    addTodotoProgress(&PL,TL,locationbuilding);

    return 0;
}