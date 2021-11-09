/* MODUL LIST INTEGER */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi III : dengan banyaknya elemen didefinisikan secara implisit,
   memori list dinamik */

#ifndef _DYNAMICLIST_H
#define _DYNAMICLIST_H

#include "../boolean/boolean.h"
#include "../point/point.h"
/*  Kamus Umum */
#define IDX_UNDEFDYNAMIC -1
/* Indeks tak terdefinisi*/
#define VAL_UNDEFDYNAMIC NULL
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxTypeDYNAMIC; /* type indeks */
typedef int ElTypeDYNAMIC; /* type elemen list */
typedef struct
{
  ElTypeDYNAMIC *buffer; /* memori tempat penyimpan elemen (container) */
  int nEff; /* banyaknya elemen efektif */
  int capacity;  /* ukuran elemen */
} ListDin;
/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah ListDin, cara deklarasi dan akses: */
/* Deklarasi : l : ListDin */
/* Maka cara akses:
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  List kosong: semua elemen bernilai VAL_UNDEFDYNAMIC
  Definisi elemen pertama : l.buffer[i] dengan i=1
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i terbesar
                                             sehingga l.buffer[i] != VAL_UNDEFDYNAMIC
  Definisi nEff: jumlah elemen efektif, di mana l.buffer[nEff] == VAL_UNDEFDYNAMIC
                                             dan l.buffer[nEff-1] != VAL_UNDEFDYNAMIC */

/* ********** SELEKTOR ********** */
#define BUFFERDYNAMIC(l) (l).buffer
#define ELMTDYNAMIC(l, i) (l).buffer[i]
#define CAPACITYDYNAMIC(l) (l).capacity

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list l kosong dengan kapasitas capacity + 1 */
/* Proses: Inisialisasi semua elemen list l dengan VAL_UNDEFDYNAMIC */

void dealocateDYNAMIC(ListDin *l);
/* I.S. l terdefinisi; */
/* F.S. TI(l) dikembalikan ke system, CAPACITYDYNAMIC(l)=0; nEff(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthDYNAMIC(ListDin l);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */

/* *** Selektor INDEKS *** */
IdxTypeDYNAMIC getLastIdxDYNAMIC(ListDin l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidDYNAMIC(ListDin l, IdxTypeDYNAMIC i);
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEffDYNAMIC(ListDin l, IdxTypeDYNAMIC i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..getLastIdx(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyDYNAMIC(ListDin l);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFullDYNAMIC(ListDin l);
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void displayListDYNAMIC(ListDin l);
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusListDYNAMIC(ListDin l1, ListDin l2, boolean plus);
/* Prekondisi : l1 dan l2 memiliki nEff sama dan tidak kosong */
/*              Jika plus=false, tidak ada elemen l1-l2 yang menghasilkan nilai <= 0 */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqualDYNAMIC(ListDin l1, ListDin l2);
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
IdxTypeDYNAMIC indexOfDYNAMIC(ListDin l, ElTypeDYNAMIC val);
/* Search apakah ada elemen list l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan VAL_UNDEFDYNAMIC */
/* Menghasilkan indeks tak terdefinisi (VAL_UNDEFDYNAMIC) jika list l kosong */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremesDYNAMIC(ListDin l, ElTypeDYNAMIC *max, ElTypeDYNAMIC *min);
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */

/* ********** OPERASI LAIN ********** */
void copyListDYNAMIC(ListDin lIn, ListDin *lOut);
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan Capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
ElTypeDYNAMIC sumListDYNAMIC(ListDin l);
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
int countValDYNAMIC(ListDin l, ElTypeDYNAMIC val);
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
boolean isAllEvenDYNAMIC(ListDin l);
/* Menghailkan true jika semua elemen l genap. l boleh kosong */

/* ********** SORTING ********** */
void sortDYNAMIC(ListDin *l, boolean asc);
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastDYNAMIC(ListDin *l, ElTypeDYNAMIC val);
/* Proses: Menambahkan X sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastDYNAMIC(ListDin *l, ElTypeDYNAMIC *val);
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void growListDYNAMIC(ListDin *l, int num);
/* Proses : Menambahkan kapasitas sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkListDYNAMIC(ListDin *l, int num);
/* Proses : Mengurangi kapasitas sebanyak num */
/* I.S. List sudah terdefinisi, ukuran Capacity > num, dan nEff < Capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compactListDYNAMIC(ListDin *l);
/* Proses : Mengurangi kapasitas sehingga nEff = Capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran Capacity = nEff */

#endif