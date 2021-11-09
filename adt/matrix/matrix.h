/* ********** Definisi TYPE Matrix dengan IndexMATRIX dan elemen integer ********** */

#ifndef Matrix_H
#define Matrix_H

#include "../boolean/boolean.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define ROW_CAP_MATRIX 100
#define COL_CAP_MATRIX 100

typedef int IndexMATRIX; /* IndexMATRIX baris, kolom */
typedef int ElTypeMATRIX;
typedef struct
{
   ElTypeMATRIX contents[ROW_CAP_MATRIX][COL_CAP_MATRIX];
   int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
   int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matrix;
/* rowEff >= 1 dan colEff >= 1 */
/* Indeks matriks yang digunakan: [0..ROW_CAP-1][0..COL_CAP-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void CreateMatrix(int nRow, int nCol, Matrix *m);
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define ROWSMATRIX(M) (M).rowEff
#define COLSMATRIX(M) (M).colEff
#define ELMTMATRIX(M, i, j) (M).contents[(i)][(j)]

/* *** Selektor "DUNIA Matrix" *** */
boolean isIdxValid(int i, int j);
/* Mengirimkan true jika i, j adalah IndexMATRIX yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IndexMATRIX getLastIdxRowMATRIX(Matrix m);
/* Mengirimkan IndexMATRIX baris terbesar m */
IndexMATRIX getLastIdxColMATRIX(Matrix m);
/* Mengirimkan IndexMATRIX kolom terbesar m */
boolean isIdxEffMATRIX(Matrix m, IndexMATRIX i, IndexMATRIX j);
/* Mengirimkan true jika i, j adalah IndexMATRIX efektif bagi m */
ElTypeMATRIX getElmtDiagonalMATRIX(Matrix m, IndexMATRIX i);
/* Mengirimkan elemen m(i,i) */

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mRes);
/* Melakukan assignment MRes = MIn */

void displayMatrix(Matrix m);
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: Menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2);
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
Matrix subtractMatrix(Matrix m1, Matrix m2);
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
Matrix multiplyMatrix(Matrix m1, Matrix m2);
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
Matrix multiplyConstMATRIX(Matrix m, ElTypeMATRIX x);
/* Mengirim hasil perkalian setiap elemen m dengan x */
void pMultiplyConstMATRIX(Matrix *m, ElTypeMATRIX k);
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isEqualMATRIX(Matrix m1, Matrix m2);
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan IndexMATRIX baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
boolean isNotEqualMATRIX(Matrix m1, Matrix m2);
/* Mengirimkan true jika m1 tidak sama dengan m2 */
boolean isSizeEqualMATRIX(Matrix m1, Matrix m2);
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */

/* ********** Operasi lain ********** */
int countMATRIX(Matrix m);
/* Mengirimkan banyaknya elemen m */

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquareMATRIX(Matrix m);
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
boolean isSymmetricMATRIX(Matrix m);
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
boolean isIdentityMATRIX(Matrix m);
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
boolean isSparseMATRIX(Matrix m);
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
Matrix inverse1MATRIX(Matrix m);
/* Menghasilkan salinan m dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
void pInverse1MATRIX(Matrix *m);
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
float determinantMATRIX(Matrix m);
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
void transposeMATRIX(Matrix *m);
/* I.S. m terdefinisi dan isSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */

float rowMeanMATRIX(Matrix m, IndexMATRIX i);
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
float colMeanMATRIX(Matrix m, IndexMATRIX j);
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
void rowExtremesMATRIX(Matrix m, IndexMATRIX i, ElTypeMATRIX * max, ElTypeMATRIX * min);
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
void colExtremesMATRIX(Matrix m, IndexMATRIX j, ElTypeMATRIX * max, ElTypeMATRIX * min);
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
int countValOnRowMATRIX(Matrix m, IndexMATRIX i, ElTypeMATRIX val);
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
int countValOnColMATRIX(Matrix m, IndexMATRIX j, ElTypeMATRIX val);
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */

#endif