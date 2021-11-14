#ifndef TAS_H
#define TAS_H

#include "../boolean/boolean.h"
#include "../linked_list/nodeLL.h"
#include "../linked_list/list_linked.h"

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
void updatePerishable(Tas *s);

#endif