#include "func.h"
#include <stdio.h>

cpx add (cpx x, cpx y) {
    cpx z;
    z.a = x.a + y.a;
    z.b = x.b + y.b;
    return z;
}

cpx sub (cpx x, cpx y) {
    cpx z;
    z.a = x.a - y.a;
    z.b = x.b - y.b;
    return z;
}

cpx mul (cpx x, cpx y) {
    cpx z;
    z.a = x.a * y.a;
    z.b = x.b * y.b;
    return z;
}

cpx div (cpx x, cpx y) {
    cpx z;
    z.a = x.a / y.a;
    z.b = x.b / y.b;
    return z;
}

void printc (cpx z) {
    if (z.b > 0) {
        printf("%.2lf+%.2lfi", z.a, z.b);
    }
    else {
        printf("%.2lf%.2lfi", z.a, z.b);
    }
}

