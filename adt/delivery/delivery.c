#include "delivery.h"
#include <stdio.h>

ElTypeNODELL _sampah;
void pickup_command (){
      if (IDX_TOP_STACK(backpack) >= _kapasitasTas-1) {
          printf("Tas penuh, tidak dapat pickup\n");
      } else if (indexOfPickupLL(TL,_currentLocBuilding) != IDX_UNDEF_LL){
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
          printf("tidak ada pesanan untuk diambil di lokasi ini\n");
      }
}

void dropoff_command(){
  int idx = 0;
  ElTypeTas sampah;
  ElTypeNODELL sampahNode;
  if (_currentLocBuilding == (TOP_STACK(backpack).dropoff)){
    popTas(&backpack,&sampah);
    if(sampah.itemtype == 'H'){
      _speedBoost = true;
      _money+=400;
      _waktuTambahan--;
      printf("Heavy item telah diantarkan, kamu dapat 400 Yen\n");
    }
    else if(sampah.itemtype == 'P'){
      _incCapacity = true;
      _kapasitasTas++;
      _money+=400;
      printf("Perishable item telah diantarkan, kamu dapat 400 Yen\n");
      
    }
    else if (sampah.itemtype == 'N' || sampah.itemtype == 'V' ){
      _money += 200;
      printf("Normal item telah diantarkan, kamu dapat 200 Yen\n");
    }
    deleteAtLL(&_ListOfProggress,idx,&sampahNode);
  } else {
    printf("Bukan lokasi drop off!\n");
  }
}



void updatePerishable(Tas *s)
{
    Tas temp;
    CreateTas(&temp);
    ElTypeTas sampah;
    ElTypeNODELL sampahNode;
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
            _perishableLoss++;       
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
