#ifndef TAS_H
#define TAS_H

#include "../boolean/boolean.h"
#include "../linked_list/nodeLL.h"
<<<<<<< HEAD
#include "../linked_list/list_linked.h"
=======
>>>>>>> 7d58e1bd1b819bed2f7a560b43ac4067d8530fc8

#define IDX_UNDEF_STACK -1
#define CAPACITY_STACK 100

typedef PesananLL ElTypeTas;
typedef struct {
  ElTypeTas buffer[CAPACITY_STACK]; /* tabel penyimpan elemen */
  int idxTop;              /* alamat TOP: elemen puncak */
} Tas;

#define IDX_TOP_STACK(s) (s).idxTop
#define     TOP_STACK(s) (s).buffer[(s).idxTop]
void CreateTas(Tas *s);
boolean isEmptyTas(Tas s);
boolean isFullTas(Tas s);
void pushTas(Tas *s, ElTypeTas val);
void popTas(Tas *s, ElTypeTas *val);
<<<<<<< HEAD
void updatePerishable(Tas *s);
=======
>>>>>>> 7d58e1bd1b819bed2f7a560b43ac4067d8530fc8

#endif