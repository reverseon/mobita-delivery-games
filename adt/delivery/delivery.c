#include "delivery.h"
#include <stdio.h>

void pickup_command (){
      if(indexOfPickupLL(TL,_currentLocBuilding) != IDX_UNDEF_LL){
        int idxTodo = indexOfPickupLL(TL,_currentLocBuilding);
        pushTas(&backpack,getElmtLL(TL,idxTodo));
        ElTypeNODELL item = getElmtLL(TL, idxTodo);
        if (item.itemtype == 'N'){
          printf("Pesanan berupa Normal item berhasil diambil\n");
        } else if(item.itemtype == 'H'){
          printf("Pesanan berupa Heavy item berhasil diambil\n");
        } else if(item.itemtype == 'P'){
          printf("Pesanan berupa Perishable item berhasil diambil\n");  
        } else if(item.itemtype == 'V'){
          printf("Pesanan berupa VIP item berhasil diambil\n"); 
        }
        printf("Tujuan Pesanan %c\n", item.dropoff);

      } else {
        printf("tidak ada pesanan untuk diambil di lokasi ini");
      }
}


