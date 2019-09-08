#include "func.h"
#include <stdio.h>
#include <dlfcn.h>

int main () {
    int num;
    cpx x, y, z;
    void (*res)(cpx);
    cpx (*ptr)(cpx, cpx);
    x.a = 3; x.b = -5; y.a = 4; y.b = 7;
    // printf("enter complex numbers:\n");
    // scanf("%lf %lf %lf %lf", &x.a, &x.b, &y.a, &y.b);
    void *ld;
    ld = dlopen("./libfunc.so", RTLD_NOW);
    if (!ld) {
        fprintf(stderr, "dlopen() error: %s\n", dlerror());
        return 2;
    }
    printf("select operation (+ - * /)\nenter num:");
    scanf("%d", &num);
    switch (num) {
        case 1:
            ptr = dlsym(ld, "add");
            z = ptr( x, y);
            break;
        case 2:
            ptr = dlsym(ld, "sub");
            z = ptr( x, y);
            break;
        case 3:
            ptr = dlsym(ld, "mul");
            z = ptr( x, y);
            break;
        case 4:
            ptr = dlsym(ld, "div");
            z = ptr( x, y);
            break;
        default:
            printf("bed num operation\n");
            return 1;
    }
    res = dlsym(ld, "printC");
    res(z);
    printf("\n");
    dlclose(ld);
    return 0;
}

