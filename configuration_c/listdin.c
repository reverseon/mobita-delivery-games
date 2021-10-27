/* NIM : 13520148
   Nama : Fikri Ihsan Fadhiilah
   Tanggal : 16-9-2021
   Topik Praktikum : ADT list dinamis
   Deskripsi :
*/

/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */
#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"
#include "boolean.h"

/*  Kamus Umum */

/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */

/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah : ArrDin, cara deklarasi dan akses: */
/* Deklarasi : l : ArrDin */
/* Maka cara akses:
   l.nEff      untuk mengetahui banyaknya elemen
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  list kosong: l.nEff = 0
  Definisi elemen pertama : l.buffer[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.nEff */

/* ********** SELEKTOR ********** */


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateArrDin(ArrDin *l, int max)
{
    NAME(*l)=(char *) malloc (max * sizeof(char));
    COOR(*l)=(POINT *) malloc (max * sizeof(POINT));
    CAPS(*l) = max;
    NEFF(*l) = 0;
}
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ArrDin l)
{
    return NEFF(l);
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getLastIdx(ArrDin l){
    return (NEFF(l)-1);
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ArrDin l, int i)
{
    return ((i>=0)&&(i<CAPS(l)));
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ArrDin l, IdxType i){
    return ((i>=0)&&(i<=NEFF(l)-1));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */

/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void displayList(ArrDin l)
{
    int i;
    for(i=0;i<NEFF(l);i++){
        printf("%c (%d %d)\n",ELMT(l,i),COORDINAT(l,i).X,COORDINAT(l,i).Y);
    }
}
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
POINT showLocation(ArrDin l, ElType namaGedung){
    boolean temu=false;
    int i=0;
    while(!temu){
        if(namaGedung == ELMT(l,i)){
            temu = true;
        }
        i++;
    }
    return COORDINAT(l,i);
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */

ArrDin insertABuilding(int max){
    ArrDin list_bangunan;
    CreateArrDin(&list_bangunan,max);
    int i,x_raw,y_raw;
    char b_name;
    printf("%d\n",max);
    for(i = 1; i <= max; i++){
        b_name = KataToChar(currentWord);
        advWord();
        x_raw = KataToInt(currentWord);
        advWord();
        y_raw = KataToInt(currentWord);
        insertBuildingInfo(&list_bangunan,b_name,x_raw,y_raw);
        advWord();
    }
    
    return list_bangunan;
}
void insertBuildingInfo(ArrDin *list_bangunan, char nama_bangunan, int x_raw, int y_raw){
    POINT titik;
    titik = MakePOINT(x_raw,y_raw);
    ELMT(*list_bangunan,NEFF(*list_bangunan))=nama_bangunan;
    COORDINAT(*list_bangunan,NEFF(*list_bangunan))=titik;
    NEFF(*list_bangunan)++;
}
/* I.S Kondisi array tidak penuh */
/* F.S Daftar semua gedung beserta koordinat akan tersimpan */