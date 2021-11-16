// Nama : Aloysius Gilang Pramudya
// NIM : 13520147 
// Topik : Mesin karakter
// Deskripsi : Implementasi header wordmachine.h

#include <stdio.h>
#include <stdlib.h>
#include "../boolean/boolean.h"
#include "charmachine.h"
#include "wordmachine.h"


/* Word Engine State */
boolean endWord;
Word currentWord;
extern int retval;

void ignoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
   while (currentChar == BLANK || currentChar == NEWLINE) {
      adv();
   }
   
}

void startWord(char *filename)
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
   start(filename);
   endWord = false;
   if(currentChar == EOF || !fileFound) {
      endWord = true;
   } else {
      ignoreBlank();
      copyWord();
   }
}

void startWordInput()
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
   startInput();
   copyInput();

}


void advWord()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */
{
   endWord =false;
   if (currentChar == MARK){
      endWord = true;
   } else {
      copyWord();
      ignoreBlank();
   }
}

void copyInput()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
{

   //kamus lokal
   int i;

   //Algoritma
   i = 0;
   while (currentChar != MARK && currentChar != BLANK && currentChar != NEWLINE && i< CAPACITYWORDMACHINE){
      currentWord.contents[i] = currentChar;
      advInput();
      i++;
   }
   currentWord.length = i;
}

void copyWord()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
{

   //kamus lokal
   int i;

   //Algoritma
   i = 0;
   while (currentChar != MARK && currentChar != BLANK && currentChar != NEWLINE && i< CAPACITYWORDMACHINE && !eot){
      currentWord.contents[i] = currentChar;
      adv();
      i++;
   }
   currentWord.length = i;
}

int KataToInt (Word kata) {
   int num = 0; int i = 0;
   while (i < kata.length) {
      num *= 10;
      switch (kata.contents[i])
      {
         case '0' : num += 0; break;
         case '1' : num += 1; break;
         case '2' : num += 2; break;
         case '3' : num += 3; break;
         case '4' : num += 4; break;
         case '5' : num += 5; break;
         case '6' : num += 6; break;
         case '7' : num += 7; break;
         case '8' : num += 8; break;
         case '9' : num += 9; break;
         default : return -1000;
         }
         i++;
   }

   return num;
}

void displayKata (Word kata)
{
  int i = 0;
  while (i<kata.length)
  {
    printf("%c", kata.contents[i]);
    i++;
  }
}
char KataToChar (Word K)
{
      if (K.length > 1) {
         return '@';
      } else {
         return (K.contents[0]);
      }
}

char* KataToString (Word K){
   char* toret = (char*)malloc(sizeof(char)*(CAPACITYWORDMACHINE)); 
   int i = 0;
   for (i = 0; i < K.length; i++) {
         toret[i] = K.contents[i];
   }
   toret[i] = '\0';
   return toret;
}

Word concatKata(Word w1, Word w2) {
   Word toret;
   int i = 0;
   for (i = 0; i < w1.length; i++) {
      toret.contents[i] = w1.contents[i];
   }
   for (i = 0; i < w2.length; i++) {
      toret.contents[i+w1.length] = w2.contents[i];
   }
   toret.length = w1.length + w2.length;
   return toret;
}

Word StringToKata (char s[] ) 
{
   Word K;
   int i = 0;
   while (s[i]!='\0')
    {
        (K).contents[i] = s[i];
        ++i;
    }
   (K).length = i;
   return K;
}

boolean IsCommandSama (Word W1, Word W2)

{
	int i;
	boolean equal;
	equal = true;

	if (W1.length != W2.length){
		return false;
	} else {
		i = 0;
		while ((equal)&&(i < W1.length)){
			equal = (W1.contents[i] == W2.contents[i]);
			i++;
		}
		return (equal);
	}
}

void readCommand (Word *K)
/* I.S. Sembarang */
/* F.S. menginput masukan kata dari user dan menyimpannya di K */
{
	char c;
	int i = 0;
	scanf("%c",&c);
	while (c != '\n')
	{
		(*K).contents[i] = c;
		++i;
		scanf("%c",&c);
	}
	(*K).length = i;
}

// int main () {

//    Word command;
//    printf("ENTER COMMAND:");readCommand(&command);
//    if (IsCommandSama(command, StringToKata("MOVE"))){
//       // insert code here
//    }

   
//    return 0;
// }