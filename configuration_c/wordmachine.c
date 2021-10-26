// Nama : Aloysius Gilang Pramudya
// NIM : 13520147 
// Topik : Mesin karakter
// Deskripsi : Implementasi header wordmachine.h

#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"


/* Word Engine State */
boolean endWord;
Word currentWord;

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
   if(currentChar == MARK) {
      endWord = true;
   } else {
      ignoreBlank();
      copyWord();
   }
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
   while (currentChar != MARK && currentChar != BLANK && currentChar != NEWLINE && i< CAPACITY){
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
         }
   }
   return num;
}

void displayKata (Word kata)
{
  int i = 1;
  while (i<kata.length)
  {
    printf("%c", kata.contents[i]);
    i++;
  }
}
char KataToChar (Word K)
{
    return (K.contents[1]);
}
