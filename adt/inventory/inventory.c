#include <stdio.h>
#include "inventory.h"

// Cek panjang string
int strlen_inventory(char* a)
{
    int result = 0;
    while(a[result++] != '\0') {
    }
    return result - 1;
}

// Untuk copy sebuah string
void strcpy_inventory(char* dest, char* source)
{
    int sourceLen = strlen_inventory(source);
    for(int i = 0; i < sourceLen; ++i)
    {
        dest[i] = source[i];
    }
    dest[sourceLen] = '\0';
}

// Membuat list inventory
void CreateList_inventory(List_inventory* l)
{
    strcpy_inventory(l->elmt0, "-\0");
    strcpy_inventory(l->elmt1, "-\0");
    strcpy_inventory(l->elmt2, "-\0");
    strcpy_inventory(l->elmt3, "-\0");
    strcpy_inventory(l->elmt4, "-\0");
}

// Mengedit list dari sebuah inventory sesuai dengna index yang diterima
void SetElmnt_inventory(List_inventory* l, int index, char* newVal)
{
    if (index == 0)
    {
        strcpy_inventory(l->elmt0, newVal);
    }
    if (index == 1)
    {
        strcpy_inventory(l->elmt1, newVal);
    }
    if (index == 2)
    {
        strcpy_inventory(l->elmt2, newVal);
    }
    if (index == 3)
    {
        strcpy_inventory(l->elmt3, newVal);
    }
    if (index == 4)
    {
        strcpy_inventory(l->elmt4, newVal);
    }
}

// Mengambil sesuatu dari sebuah inventory sesuai dengan index yang diterima
void GetElmt_inventory(List_inventory l, int index, char* returnVal)
{
    if (index == 0)
    {
        strcpy_inventory(returnVal, l.elmt0);
    }
    if (index == 1)
    {
        strcpy_inventory(returnVal, l.elmt1);
    }
    if (index == 2)
    {
        strcpy_inventory(returnVal, l.elmt2);
    }
    if (index == 3)
    {
        strcpy_inventory(returnVal, l.elmt3);
    }
    if (index == 4)
    {
        strcpy_inventory(returnVal, l.elmt4);
    }
}

// Menampilkan inventory
void display_inventory(List_inventory l)
{
    printf("1. %s\n", l.elmt0);
    printf("2. %s\n", l.elmt1);
    printf("3. %s\n", l.elmt2);
    printf("4. %s\n", l.elmt3);
    printf("5. %s\n", l.elmt4);
}
