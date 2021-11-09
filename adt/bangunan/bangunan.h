/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#ifndef BANGUNAN_H
#define BANGUNAN_H

#include "../point/point.h"
#include "../input_process/wordmachine.h"
#include "../boolean/boolean.h"

/*  Kamus Umum */
#define IDX_UNDEF_ListBangunan -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef char ElType_ListBangunan; /* type elemen list */
typedef int IdxType_ListBangunan;
typedef struct
{
   ElType_ListBangunan *name; /* memori tempat penyimpan nama bangunan (container) */
   POINT *loct; /* Menyimpan koordinat gedung */
   int nEff;       /* >=0, banyaknya elemen efektif */
   int caps;   /* ukuran elemen */
} ListBangunan;
/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah : ListBangunan, cara deklarasi dan akses: */
/* Deklarasi : l : ListBangunan */
/* Maka cara akses:
   l.nEff      untuk mengetahui banyaknya elemen
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  list kosong: l.nEff = 0
  Definisi elemen pertama : l.buffer[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.nEff */

/* ********** SELEKTOR ********** */
#define NEFF_ListBangunan(l) (l).nEff
#define NAME_ListBangunan(l) (l).name
#define ELMT_ListBangunan(l, i) (l).name[i]
#define CAPS_ListBangunan(l) (l).caps
#define COOR_ListBangunan(l) (l).loct
#define COORDINAT_ListBangunan(l,i) (l).loct[i]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void Create_ListBangunan(ListBangunan *l, int max);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length_ListBangunan(ListBangunan l);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType_ListBangunan getLastIdx_ListBangunan(ListBangunan l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid_ListBangunan(ListBangunan l, int i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff_ListBangunan(ListBangunan l, IdxType_ListBangunan i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void displayList_ListBangunan(ListBangunan l);
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
POINT showLocation_ListBangunan(ListBangunan l, ElType_ListBangunan nama);
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF_ListBangunan */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF_ListBangunan) jika List l kosong */
/* Skema Searching yang digunakan bebas */

ListBangunan insertABuilding_ListBangunan(int max);
/* I.S Kondisi array tidak penuh */
/* F.S Daftar semua gedung beserta koordinat akan tersimpan */

void insertBuildingInfo_ListBangunan(ListBangunan *list_bangunan, char nama_bangunan, int x_raw, int y_raw);

#endif