#include <stdio.h>
int main()
{
    int myNumbers[5] = {10, 20, 30, 40, 50};
    int *p1 = (myNumbers + 1);
    int *p2 = &myNumbers[4];
    printf("Pointer 1 adress: %p\n", &p1);
    printf("Pointer 2 adress: %p\n", &p2);
    printf("Pointer diffrence: %d\n", (p2 - p1));
    /*  Pointer 1 adress: 00000000005FFE28
        Pointer 2 adress: 00000000005FFE20
        Pointer diffrence: 3
        Die Pointer liegen 3 Adressen nebeneinander was 8 Byte sind
    */
}