/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#ifndef ArrDin_H
#define ArrDin_H

#include "boolean.h"
#include "point.h"
#include "wordmachine.h"

/*  Kamus Umum */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef char ElType; /* type elemen list */
typedef int IdxType;
typedef struct
{
   ElType *name; /* memori tempat penyimpan nama bangunan (container) */
   POINT *loct; /* Menyimpan koordinat gedung */
   int nEff;       /* >=0, banyaknya elemen efektif */
   int caps;   /* ukuran elemen */
} ArrDin;
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
#define NEFF(l) (l).nEff
#define NAME(l) (l).name
#define ELMT(l, i) (l).name[i]
#define CAPS(l) (l).caps
#define COOR(l) (l).loct
#define COORDINAT(l,i) (l).loct[i]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateArrDin(ArrDin *l, int max);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ArrDin l);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getLastIdx(ArrDin l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ArrDin l, int i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ArrDin l, IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void displayList(ArrDin l);
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
POINT indexOf(ArrDin l, ElType nama);
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */

ArrDin insertABuilding(int max);
/* I.S Kondisi array tidak penuh */
/* F.S Daftar semua gedung beserta koordinat akan tersimpan */

void insertBuildingInfo(ArrDin *list_bangunan, char nama_bangunan, int x_raw, int y_raw);

#endif