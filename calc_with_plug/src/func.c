#include "../include/func.h"
#include <string.h>
#include <stdio.h>

void print_cpx (cpx z) {
    if (z.b > 0) {
        printf("%.2lf+%.2lfi", z.a, z.b);
    }
    else {
        printf("%.2lf%.2lfi", z.a, z.b);
    }
}

