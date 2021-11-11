#include "inventory.h"

int main()
{
    List_inventory l;
    CreateList_inventory(&l);

    printf("List mula-mula\n");
    display_inventory(l);

    printf("\n");

    printf("List setelah diisi\n");
    SetElmnt_inventory(&l, 0, "Senter Pembesar");
    SetElmnt_inventory(&l, 3, "Mesin Waktu");
    display_inventory(l);

    printf("\n");

    printf("List setelah senter pembesar digunakan\n");
    char returnStr[STRING_SIZE];
    GetElmt_inventory(l, 0, returnStr);
    SetElmnt_inventory(&l, 0, "-");
    printf("%s\n", returnStr);
    display_inventory(l);
}
