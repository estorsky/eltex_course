#include "../include/func.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initStore (int *array, int n) {
    for (int i = 0; i < n; i++) {
        array[i] = 900 + rand() % 200;
    }
}

void statStore (int *array, int n) {
    printf("stores: ");
    for (int i = 0; i < n; i++) {
        printf("[%d]=%4d  ", i + 1, array[i]);
    }
    printf("\n");
}

int* getPrcnt(int *cur_capacity, int max_capacity) {
    int *prcnt = *cur_capacity * 100 / max_capacity;
    return prcnt;
}
