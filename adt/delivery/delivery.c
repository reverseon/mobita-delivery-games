#include "delivery.h"
#include <stdio.h>


ElTypeNODELL _sampah;
void pickup_command (){
      if(indexOfPickupLL(TL,_currentLocBuilding) != IDX_UNDEF_LL){
        int idxTodo = indexOfPickupLL(TL,_currentLocBuilding);
        pushTas(&backpack,getElmtLL(TL,idxTodo));
        addTodotoProgress(&_ListOfProggress,&TL,_currentLocBuilding);
        deleteAtLL(&TL,idxTodo, &_sampah);
        ElTypeNODELL item = _sampah;
        if (item.itemtype == 'N'){
          printf("Pesanan berupa Normal item berhasil diambil\n");
        } else if(item.itemtype == 'H'){
          printf("Pesanan berupa Heavy item berhasil diambil\n");
          if (_speedBoost) {
            _speedBoost = false;
          }
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

void dropoff_command(){
  int idx = 0;
  ElTypeTas sampah;
  ElTypeNODELL sampahNode;
  ElTypeNODELL itemDiInP = getElmtLL(_ListOfProggress, idx);
  if (_currentLocBuilding == (TOP_STACK(backpack).dropoff)){
    popTas(&backpack,&sampah);
    if(sampah.itemtype == 'H'){
      _speedBoost = true;
      _money+=400;

    }
    else if(sampah.itemtype == 'P'){
      _incCapacity = true;
      _kapasitasTas++;
      _money+=400;
    }
    else if (sampah.itemtype == 'N' || sampah.itemtype == 'V' ){
      _money += 200;
    }
    deleteAtLL(&_ListOfProggress,idx,&sampahNode);
  } else {
    printf("Bukan lokasi drop off!");
  }
}



void updatePerishable(Tas *s)
{
    Tas temp;
    CreateTas(&temp);
    ElTypeTas sampah,sampahPermanent;
    ElTypeNODELL sampahNode;
    int idxIn;
    int idx = 0;
    while(!isEmptyTas(*s)){
        ElTypeNODELL itemDiInP = getElmtLL(_ListOfProggress, idx);
        popTas(s,&sampah);
        if (sampah.itemtype == 'P' && sampah.timelimit - 1 - _waktuTambahan > 0) {
            sampah.timelimit = sampah.timelimit - 1 - _waktuTambahan;
            itemDiInP.timelimit = sampah.timelimit;
            setElmtLL(&_ListOfProggress, idx, itemDiInP);
            pushTas(&temp,sampah);
            idx++;
        } else if (sampah.itemtype == 'P' && sampah.timelimit - 1 - _waktuTambahan <= 0) {
            deleteAtLL(&_ListOfProggress,idx,&sampahNode);        
        } else {
            pushTas(&temp,sampah);
            idx++;
        }
    } 

    while(!isEmptyTas(temp)) {
        popTas(&temp, &sampah);
        pushTas(s, sampah);
    }
}
