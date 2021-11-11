// 10
// 1 G N N
// 3 G N H
// 2 B M N
// 1 M B H
// 5 C D N
// 3 F E N
// 10 P Q P 20
// 5 G N P 10
// 8 O P V
// 8 Q L V

#include <stdio.h>
#include <stdlib.h>
#include "queue_pesanan.h"

boolean isEmptysorted_pesanan(sorted_pesanan* self) {
    return self->root == NULL;
}

sorted_pesanan* createsorted_pesanan() {
    sorted_pesanan* self = malloc(sizeof(sorted_pesanan));
    self->root = NULL;
    return self;
}

void pushsorted_pesanan(sorted_pesanan* self, jumlahPesanan val) {
    if(self->root == NULL) {
        self->root = malloc(sizeof(queue_pesanan));
        self->root->data = val;
        self->root->next = NULL;
    } else {
        //make double pointer to traverse
        queue_pesanan** temp = &self->root;
        queue_pesanan** prev = NULL;
        //looping untuk mencari elemen di queue, dimana elemen memiliki data time lebih besar dari
        //yang dimasukkan
        while(*temp != NULL) {
            if((*temp)->data.time > val.time) {
                break;
            }
            prev = temp;
            temp = &(*temp)->next;
        }

        //membuat node baru untuk dimasukkan kepada sorted queue
        queue_pesanan* newData = malloc(sizeof(queue_pesanan));
        newData->data = val;
        newData->next = NULL;

        //apabila elemen dimasukkan di paling depan
        if(prev == NULL) {
            newData->next = self->root;
            self->root = newData;
        }
        //apabila elemen dimasukkan di paling akhir
        else if(*temp == NULL) {
            (*prev)->next = newData;
        }
        //apabila elemen dimasukkan di bagian tengah
        else {
            newData->next = *temp;
            (*prev)->next = newData;
        }
    }
}

jumlahPesanan popsorted_pesanan(sorted_pesanan* self) {
    if(self->root == NULL) {
        jumlahPesanan test;
        test.time = -1;
        return test;
    }
    jumlahPesanan temp = self->root->data;
    //menyimpan variable sementara untuk free
    queue_pesanan* toFree = self->root;
    self->root = self->root->next;
    free(toFree);
    return temp;
}

//menerima masukkan array dan mengubahnya menjadi sorted queue
sorted_pesanan* makeSQ(jumlahPesanan* arr, int len) {
    sorted_pesanan* self = createsorted_pesanan();
    for(int i = 0; i < len; ++i) {
        pushsorted_pesanan(self, arr[i]);
    }
    return self;
}
