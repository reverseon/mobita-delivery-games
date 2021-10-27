#include <stdio.h>
#include "listdin.h"
#include "charmachine.h"
#include "wordmachine.h"
#include "point.h"



int main(){
    ArrDin tole;
    int max;
    char konf[20] = "rutin.txt";
    startWord(konf);

    // space buat baca ukuran map, headquarter
    // new line pake advWord() 2x
    
    max=KataToInt(currentWord);
    
    advWord();
    advWord();

    tole = insertABuilding(max);
    displayList(tole);
}