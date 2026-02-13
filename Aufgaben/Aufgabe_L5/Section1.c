#include <stdio.h>

int main(void) {
    int x = 10;
    int *p = &x;
    int **pp = &p;

    // TODO: complete the output statements
    printf("x = %d\n", x);
    printf("x via p = %d\n", *p);
    printf("x via pp = %d\n", **pp);
    **pp=42;
    printf("x via pp = %d\n", **pp);
    /*
    x ->    Value of x
    p ->    Value of p / adress of x
    *p ->   value of x
    pp ->   value of pp / adress of p
    *pp ->  value of p / adress of x
    **pp -> value of x
    */
    return 0;
}