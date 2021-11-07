/* File: point.c */
/* Tanggal: 28 Agustus 2016 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"
#include "boolean.h"
#define PI 3.14159265358979323846


/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y)
{
    POINT* P = (POINT*)malloc(sizeof(POINT));
    Absis(*P) = X;
    Ordinat(*P) = Y;

    return *P;
}

/* Membentuk sebuah POINT dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P)
{
    int x,y;

    scanf("%d %d",&x,&y);
    *P = MakePOINT(x,y);
}
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
void TulisPOINT (POINT P)
{
    printf("(%d,%d)",Absis(P),Ordinat(P));
}
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2)
{
    return((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
        
}
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
boolean NEQ (POINT P1, POINT P2)
{
    return((Absis(P1) != Absis(P2)) || (Ordinat(P1) != Ordinat(P2)));
        
}
/* Mengirimkan true jika P1 tidak sama dengan P2 */

/* *** Kelompok menentukan di mana P berada *** */

/* Menghasilkan true jika P adalah titik origin */
boolean IsOnSbX (POINT P)
{
    return(Ordinat(P)==0);
        
}
/* Menghasilkan true jika P terletak Pada sumbu X */
boolean IsOnSbY (POINT P)
{
    return(Absis(P)==0);
        
}
/* Menghasilkan true jika P terletak pada sumbu Y */
int Kuadran (POINT P)
{
    if (((Absis(P)>0) && (Ordinat(P)>0)))
        return 1;
    else if (((Absis(P)>0) && (Ordinat(P)<0)))
        return 4;
    else if (((Absis(P)<0) && (Ordinat(P)>0)))
        return 2;
    else
        return 3;
}
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */


/* Mengirim salinan P dengan ordinat ditambah satu */
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
int Panjang (POINT P1, POINT P2)
{   int x,y;
    x= Absis(P1)-Absis(P2);
    y= Ordinat(P1)-Absis(P2);
    return sqrt(pow(x,2) + pow(y,2));
}
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */


