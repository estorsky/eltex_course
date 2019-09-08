#include "func.h"
#include <stdio.h>

int main () {
    int num;
    cpx x, y, z;
    x.a = 3; x.b = -5; y.a = 4; y.b = 7;
    // printf("enter complex numbers:\n");
    // scanf("%lf %lf %lf %lf", &x.a, &x.b, &y.a, &y.b);
    printf("select operation (+ - * /)\nenter num:");
    scanf("%d", &num);
    switch (num) {
        case 1:
            z = add( x, y);
            break;
        case 2:
            z = sub( x, y);
            break;
        case 3:
            z = mul( x, y);
            break;
        case 4:
            z = div( x, y);
            break;
        default:
            printf("bed num operation\n");
            return 1;
    }
    printc(z);
    printf("\n");
    return 0;
}

