// #include "../include/func.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main () {
    printf("main: pid = %d\n\n", getpid());
    pid_t pid;
    pid_t ppid;
    int rv;

    pid = fork();
    if (pid == 0) {
        printf("pid = %d ppid = %d pid %d\n", getpid(), getppid(), pid);
        pid = fork();
        if (pid == 0) {
            printf("pid = %d ppid = %d pid %d\n", getpid(), getppid(), pid);
            exit(rv);
        } else {
            printf("pid = %d ppid = %d pid %d\n", getpid(), getppid(), pid);
            wait();
        }
        exit(rv);
    } else {
        printf("pid = %d ppid = %d pid %d\n", getpid(), getppid(), pid);
        wait();
    }

    pid = fork();
    if (pid == 0) {
        printf("pid = %d ppid = %d pid %d\n", getpid(), getppid(), pid);
        pid = fork();
        if (pid == 0) {
            printf("pid = %d ppid = %d pid %d\n", getpid(), getppid(), pid);
            exit(rv);
        } else {
            printf("pid = %d ppid = %d pid %d\n", getpid(), getppid(), pid);
            wait();
        }
        pid = fork();
        if (pid == 0) {
            printf("pid = %d ppid = %d pid %d\n", getpid(), getppid(), pid);
            exit(rv);
        } else {
            printf("pid = %d ppid = %d pid %d\n", getpid(), getppid(), pid);
            wait();
        }
        exit(rv);
    } else {
        printf("pid = %d ppid = %d pid %d\n", getpid(), getppid(), pid);
        wait();
    }

    return 0;
}

