#include <stdio.h>
#include "matrix.h"
#define endl printf("\n")

void CreateMatrix(int nRow, int nCol, Matrix *m) {
   ROWSMATRIX(*m) = nRow;
   ROWSMATRIX(*m) = nCol;
}
boolean isIdxValidMATRIX(int i, int j) {
   return (i >= 0 && i < ROW_CAP_MATRIX) && (j >= 0 && j < COL_CAP_MATRIX);
}
IndexMATRIX getLastIdxRowMATRIX(Matrix m) { 
   return ROWSMATRIX(m) - 1;
}
IndexMATRIX getLastIdxColMATRIX(Matrix m) {
   return ROWSMATRIX(m) - 1;
}
boolean isIdxEffMATRIX(Matrix m, IndexMATRIX i, IndexMATRIX j) {
   return (i >= 0 && i < ROWSMATRIX(m)) && (j >= 0 && j < ROWSMATRIX(m));
}
ElTypeMATRIX getElmtDiagonalMATRIX(Matrix m, IndexMATRIX i) {
   return ELMTMATRIX(m, i, i);
}
void copyMatrix(Matrix mIn, Matrix *mRes) {
   int i = 0;
   int j = 0;
   CreateMatrix(ROWSMATRIX(mIn), ROWSMATRIX(mIn), mRes);
   for (i = 0; i < ROWSMATRIX(mIn); i++) {
      for (j = 0; j < ROWSMATRIX(mIn); j++) {
         ELMTMATRIX(*mRes, i, j) = ELMTMATRIX(mIn, i, j);
      }
   }
}
void displayMatrix(Matrix m) {
   int i = 0;
   int j = 0;
   for (i = 0; i < ROWSMATRIX(m); i++) {
      for (j = 0; j < ROWSMATRIX(m); j++) {
         printf("%i", ELMTMATRIX(m, i, j));
         if (j != ROWSMATRIX(m)-1) {
            printf(" ");
         }
      }
      if (i != ROWSMATRIX(m)-1) {
         endl;
      }
   }
}
Matrix addMatrix(Matrix m1, Matrix m2) {
    Matrix out;
    CreateMatrix(ROWSMATRIX(m1), ROWSMATRIX(m1), &out);
    int i = 0;
    int j = 0;
    for (i = 0; i < ROWSMATRIX(out); i++) {
      for (j = 0; j < ROWSMATRIX(out); j++) {
         ELMTMATRIX(out, i, j) = ELMTMATRIX(m1, i, j) + ELMTMATRIX(m2, i, j);
      }
    }
    return out;
}
Matrix subtractMatrix(Matrix m1, Matrix m2) { 
    Matrix out;
    CreateMatrix(ROWSMATRIX(m1), ROWSMATRIX(m1), &out);
    int i = 0;
    int j = 0;
    for (i = 0; i < ROWSMATRIX(out); i++) {
      for (j = 0; j < ROWSMATRIX(out); j++) {
         ELMTMATRIX(out, i, j) = ELMTMATRIX(m1, i, j) - ELMTMATRIX(m2, i, j);
      }
    }
    return out;
}
Matrix multiplyMatrix(Matrix m1, Matrix m2) {
    Matrix out;
    CreateMatrix(ROWSMATRIX(m1), ROWSMATRIX(m2), &out);
    int i = 0;
    int j = 0;
    int k = 0;
    for (i = 0; i < ROWSMATRIX(out); i++) {
        for (j = 0; j < ROWSMATRIX(out); j++) {
            ELMTMATRIX(out, i, j) = 0;
            for (k = 0; k < ROWSMATRIX(m1); k++) {
                ELMTMATRIX(out, i, j) += ELMTMATRIX(m1, i, k)*ELMTMATRIX(m2, k, j);
            } 
        }
    }
    return out;
}
Matrix multiplyConstMATRIX(Matrix m, ElTypeMATRIX x) {
    Matrix out;
    CreateMatrix(ROWSMATRIX(m), ROWSMATRIX(m), &out);
    int i = 0;
    int j = 0;
    for (i = 0; i < ROWSMATRIX(out); i++) {
      for (j = 0; j < ROWSMATRIX(out); j++) {
         ELMTMATRIX(out, i, j) = ELMTMATRIX(m, i, j) * x;
      }
    }
    return out;
}
void pMultiplyConstMATRIX(Matrix *m, ElTypeMATRIX k) {
    int i = 0;
    int j = 0;
    for (i = 0; i < ROWSMATRIX(*m); i++) {
        for (j = 0; j < ROWSMATRIX(*m); j++) {
            ELMTMATRIX(*m, i, j) *= k;
        }
    }
}
boolean isEqualMATRIX(Matrix m1, Matrix m2) {
   boolean out = true;
   if (countMATRIX(m1) != countMATRIX(m2)) {
      out = false;
   } else
   if ((ROWSMATRIX(m1) != ROWSMATRIX(m2)) || (ROWSMATRIX(m1) != ROWSMATRIX(m2))) {
      out = false;
   }
   else {
      int i = 0;
      int j = 0;
      while (out && i < ROWSMATRIX(m1)) {
         j = 0;
         while (out && j < ROWSMATRIX(m1)) {
            if (ELMTMATRIX(m1, i, j) != ELMTMATRIX(m2, i, j)) out = false;
            j++;
         }
         i++;
      }
   }
   return out;
}
boolean isNotEqualMATRIX(Matrix m1, Matrix m2) {
   return !isEqualMATRIX(m1, m2);
}
boolean isSizeEqualMATRIX(Matrix m1, Matrix m2) {
   return countMATRIX(m1) == countMATRIX(m2);
}
int countMATRIX(Matrix m) {
    return ROWSMATRIX(m) * ROWSMATRIX(m);
}
boolean isSquareMATRIX(Matrix m) {
   return ROWSMATRIX(m) == ROWSMATRIX(m);
}
boolean isSymmetricMATRIX(Matrix m) {
   boolean out = true;
   if (!isSquareMATRIX(m)) {
      out = false;
   } else {
      int i = 1;
      int until = 1;
      int j = 0;
      while (out && i < ROWSMATRIX(m)) {
         j = 0;
         while (out && j < until) {
            if (ELMTMATRIX(m, i, j) != ELMTMATRIX(m, j, i)) {
               out = false;
            }
            j++;
         }
         until++;
         i++;
      }
   }
   return out;
}
boolean isIdentityMATRIX(Matrix m) {
   boolean out = true;
   if (!isSquareMATRIX(m)) {
      out = false;
   } else {
      int i = 0;
      int j = 0;
      while (out && i < ROWSMATRIX(m)) {
         j = 0;
         while (out && j < ROWSMATRIX(m)) {
            if (i == j) {
               if (ELMTMATRIX(m, i, j) != 1) { 
                  out = false; 
               }
            } else {
               if (ELMTMATRIX(m, i, j) != 0) { 
                  out = false;
               }
            }
            j++;
         }
         i++;
      }
   }
   return out;
}
boolean isSparseMATRIX(Matrix m) {
   float percent = 0;
   float treshold = 5/100.0f;
   int i = 0;
   int j = 0;
   int ctr = 0;
   for (i = 0; i < ROWSMATRIX(m); i++) {
      for (j = 0; j < ROWSMATRIX(m); j++) {
         if (ELMTMATRIX(m, i, j) != 0) ctr++;
      }
   }
   percent = (float)ctr/countMATRIX(m);
   return percent < treshold;
}
Matrix inverse1MATRIX(Matrix m) {
   Matrix out;
   CreateMatrix(ROWSMATRIX(m), ROWSMATRIX(m), &out);
   copyMatrix(m, &out);
   pMultiplyConstMATRIX(&out, -1);
   return out;
}
void pInverse1MATRIX(Matrix *m) {
   pMultiplyConstMATRIX(m, -1);
}
float determinantMATRIX(Matrix m) {
   float res = 0;
   if (ROWSMATRIX(m) == 0) {
      res = 0;
   } else
   if (ROWSMATRIX(m) == 1) {
      res = ELMTMATRIX(m, 0, 0);
   } else 
   if (ROWSMATRIX(m) == 2) {
      res = (ELMTMATRIX(m, 0, 0)*ELMTMATRIX(m, 1, 1)) - (ELMTMATRIX(m, 1,0) * ELMTMATRIX(m,0,1));
   } else {
      int i = 0;
      for(i = 0; i < ROWSMATRIX(m); i++) {
         Matrix subm;
         CreateMatrix(ROWSMATRIX(m)-1,ROWSMATRIX(m)-1, &subm);
         int rowsubm = 0;
         int colsubm = 0;
         int j = 0;
         int k = 0;
         for (j = 0; j < ROWSMATRIX(m); j++) {
            colsubm = 0;
            for (k = 0; k < ROWSMATRIX(m); k++) {
               if (j != 0 && k != i) {
                  ELMTMATRIX(subm, rowsubm, colsubm) = ELMTMATRIX(m, j, k);
                  colsubm++;
               } 
            }
            if (j != 0) {
               rowsubm++;
            }
         }
         if (i%2 == 0) {
            res += ELMTMATRIX(m,0,i)*determinantMATRIX(subm);
         } else {
            res += -1*ELMTMATRIX(m,0,i)*determinantMATRIX(subm);
         }
      }
   }
   return res; 
}
void transposeMATRIX(Matrix *m) {
   Matrix temp;
   CreateMatrix(ROWSMATRIX(*m), ROWSMATRIX(*m), &temp);
   copyMatrix(*m, &temp);
   int i = 0;
   int j = 0;
   for (i = 0; i < ROWSMATRIX(*m); i++) {
      for (j = 0; j < ROWSMATRIX(*m); j++) {
         ELMTMATRIX(*m, i, j) = ELMTMATRIX(temp, j, i);
      }
   }
}

float rowMeanMATRIX(Matrix m, IndexMATRIX i) {
    float res = 0;
    int j = 0;
    for (j = 0; j < ROWSMATRIX(m); j++) {
        res += ELMTMATRIX(m, i, j);
    }
    res /= ROWSMATRIX(m);
    return res;
}

float colMeanMATRIX (Matrix m, IndexMATRIX j) {
        float res = 0;
    int i = 0;
    for (i = 0; i < ROWSMATRIX(m); i++) {
        res += ELMTMATRIX(m, i, j);
    }
    res /= ROWSMATRIX(m);
    return res;
}

void rowExtremesMATRIX(Matrix m, IndexMATRIX i, ElTypeMATRIX * max, ElTypeMATRIX * min) {
    *max = ELMTMATRIX(m, i, 0);
    *min = *max;
    int j = 0;
    for (j = 1; j < ROWSMATRIX(m); j++) {
        if (ELMTMATRIX(m, i, j) > *max) {
            *max = ELMTMATRIX(m, i, j);
        }
        if (ELMTMATRIX(m, i, j) < *min) {
            *min = ELMTMATRIX(m, i, j);
        }
    }
}

void colExtremesMATRIX(Matrix m, IndexMATRIX j, ElTypeMATRIX * max, ElTypeMATRIX * min) {
    *max = ELMTMATRIX(m, 0, j);
    *min = *max;
    int i = 0;
    for (i = 1; i < ROWSMATRIX(m); i++) {
        if (ELMTMATRIX(m, i, j) > *max) {
            *max = ELMTMATRIX(m, i, j);
        }
        if (ELMTMATRIX(m, i, j) < *min) {
            *min = ELMTMATRIX(m, i, j);
        }
    }
}

int countMATRIXValOnRow (Matrix m, IndexMATRIX i, ElTypeMATRIX val) {
    int out = 0;
    int j = 0;
    for (j = 0; j < ROWSMATRIX(m); j++) {
        if (ELMTMATRIX(m,i,j) == val) out++;
    }
    return out;
}

int countMATRIXValOnCol (Matrix m, IndexMATRIX j, ElTypeMATRIX val) {
    int out = 0;
    int i = 0;
    for (i = 0; i < ROWSMATRIX(m); i++) {
        if (ELMTMATRIX(m,i,j) == val) out++;
    }
    return out;
}