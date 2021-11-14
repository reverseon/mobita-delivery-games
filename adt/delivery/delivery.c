#include "delivery.h"
#include <stdio.h>


ElTypeNODELL _sampah;
void pickup_command (){
      if(indexOfPickupLL(TL,_currentLocBuilding) != IDX_UNDEF_LL){
        int idxTodo = indexOfPickupLL(TL,_currentLocBuilding);
        pushTas(&backpack,getElmtLL(TL,idxTodo));
        deleteAtLL(&TL,idxTodo, &_sampah);
        addTodotoProgress(&_ListOfProggress,&TL,_currentLocBuilding);


        ElTypeNODELL item = _sampah;
        if (item.itemtype == 'N'){
          printf("Pesanan berupa Normal item berhasil diambil\n");
        } else if(item.itemtype == 'H'){
          printf("Pesanan berupa Heavy item berhasil diambil\n");
          _waktuTambahan++;
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

void updatePerishable(Tas *s)
{
    Tas temp;
    CreateTas(&temp);
    ElTypeTas sampah,sampahPermanent;
    ElTypeNODELL sampahNode;
    int idxIn;
    while(!isEmptyTas(*s)){
        popTas(s,&sampah);
        if (sampah.itemtype == 'P' && sampah.timelimit > 0) {
            sampah.timelimit--;
            pushTas(&temp,sampah);
        } else if (sampah.timelimit == 0) {
            popTas(s,&sampahPermanent);
            idxIn=indexOfExpiredPerish(_ListOfProggress,'P');
            deleteAtLL(&_ListOfProggress,idxIn,&sampahNode);        
        } 
    }

    while(!isEmptyTas(temp)) {
        popTas(&temp, &sampah);
        pushTas(s, sampah);
    }
}
