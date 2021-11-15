/* File: charmachine.c */
/* Implementasi Character Engine */

#include "charmachine.h"
#include <stdio.h>

char currentChar;
boolean eot;

static FILE * tape;
static int retval;

void start(char *filename) {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	tape = fopen(filename,"r");
   adv();
}

void adv() {
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
		      Jika  currentChar = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	retval = (fscanf(tape,"%c",&currentChar) == EOF);
    if (retval) {
       eot = true;
       fclose(tape);
    }
 	//printf("%d", retval);
}

// AKA: start without adv()
void startWOA(char *filename) {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	tape = fopen(filename,"r");
}

char getAdv() {
   char currChar;
   retval = fscanf(tape, "%c", &currChar);
   eot = (currentChar == MARK);
   return currChar;
}

void startInput() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	tape = stdin;
	advInput();
}

void advInput() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama, 
          currentChar mungkin = MARK
		      Jika  currentChar = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	retval = fscanf(tape,"%c",&currentChar);
	eot = (currentChar == '\n');
	if (eot) {
       return;
 	}
}



// void startCom() {
// /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
//    Karakter pertama yang ada pada pita posisinya adalah pada jendela.
//    I.S. : sembarang
//    F.S. : currentChar adalah karakter pertama pada pita
//           Jika currentChar != MARK maka EOP akan padam (false)
//           Jika currentChar = MARK maka EOP akan menyala (true) */

// 	/* Algoritma */
// 	tape = stdin;
//    advCommand();
// }

// void advCommand() {
// /* Pita dimajukan satu karakter.
//    I.S. : Karakter pada jendela = currentChar, currentChar != MARK
//    F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
//           currentChar mungkin = MARK
// 		      Jika  currentChar = MARK maka EOP akan menyala (true) */

// 	/* Algoritma */
// 	retval = fscanf(tape,"%c",&currentChar);
// 	eot = (currentChar == '\n');
//     if (eot) {
//        fclose(tape);
//     }
//  	//printf("%d", retval);
// }
