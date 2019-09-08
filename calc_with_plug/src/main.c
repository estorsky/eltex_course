#include "../include/func.h"
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>
#include <malloc.h>
#include <dirent.h>
#include <sys/types.h>
#include <curses.h>
#include <unistd.h>

int main (int argc, char* argv[]) {

    int numFunc = 0;
    char *buff;
    void **ld;
    char p[NAME_MAX];
    void (*func)(char *);

    /* DIR *dir;
    struct dirent *entry;
    dir = opendir("plugins");
    if (!dir) {
        printf("not found dir plugins\n");
    }
    entry = readdir(dir);
    while (entry != NULL) {
        printf("%s\n", entry->d_name);
    }; */

    struct dirent **namelist;
    int n;
    int i = 2;
    if (chdir("plugins")) {
        printf("not found dir plugins\n");
        return 2;
    }
    n = scandir(".", &namelist, 0, alphasort);
    char namesFunc[n][NAME_MAX];
    ld = malloc (n * sizeof(void*));
    memset(namesFunc, 0, sizeof(namesFunc[0][0]) * argc * NAME_MAX);
    if (n < 0)
        perror("scandir");
    else {
        while(i < n) {
            // if (!strcmp(namelist[i]->d_name, ".")) continue;
            // printf("%s\n", namelist[i]->d_name);
            buff = calloc(1, strlen(namelist[i]->d_name) + 2);
            sprintf(buff, "./%s", namelist[i]->d_name);
            ld[numFunc] = dlopen(buff, RTLD_NOW);
            if (!ld[numFunc]) {
                fprintf(stderr, "dlopen() error: %s\n", dlerror());
            }
            else {
                *(void **) (&func) = dlsym(ld[numFunc], "info");
                func(p);
                strcat(namesFunc[numFunc], p);
                printf("%d - %s\n", numFunc + 1, namesFunc[numFunc]);
                numFunc++;
            }
            free(buff);
            free(namelist[i]);
            ++i;
        }
        free(namelist);
    }

    /* for (int n = 1; n < argc; n++) {
        buff = calloc(1, strlen(argv[n]) + 2);
        sprintf(buff, "./%s", argv[n]);
        ld[numFunc] = dlopen(buff, RTLD_NOW);
        if (!ld[numFunc]) {
            fprintf(stderr, "dlopen() error: %s\n", dlerror());
        }
        else {
            *(void **) (&func) = dlsym(ld[numFunc], "info");
            func(p);
            strcat(namesFunc[numFunc], p);
            printf("%d - %s\n", numFunc + 1, namesFunc[numFunc]);
            numFunc++;
        }
        free(buff);
    } */

    if (numFunc < 1) {
        printf("dynamic lib not found\n");
        return 2;
    }

    printf("select operation, enter num:\n");
    int num = 1;
    do {
        scanf("%d", &num);
    } while (num > numFunc || num == 0);

    cpx x, y, z;
    cpx (*ptr)(cpx, cpx);
    x.a = 3; x.b = -5; y.a = 4; y.b = 7;
    printf("enter complex numbers:\n");
    // scanf("%lf %lf %lf %lf", &x.a, &x.b, &y.a, &y.b);
    *(void **) (&ptr) = dlsym(ld[num - 1], namesFunc[num - 1]);
    z = ptr(x, y);
    print_cpx(z);
    printf("\n");

    // closedir(dir);
    for (int i = 0; i < numFunc; i++)
        dlclose(ld[i]);
    free(ld);
    return 0;
}

