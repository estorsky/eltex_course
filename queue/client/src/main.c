#include "../include/func.h"
#include <sys/types.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_TEXT_SIZE 100

struct mbuf {
    long mtype;
    char mtext[MAX_TEXT_SIZE];
};

int main () {
    key_t key;
    int id_q;
    struct mbuf msg;
    pid_t pid;

    key = ftok("/home/dmitry/Dropbox/courses/eltex/queue/Makefile", 'c');
    id_q = msgget(key, 0);
    pid = getpid();
    msg.mtype = 1;

    // scanf("%s", msg.mtext);

    sprintf(msg.mtext, "%d", pid);
    // strcpy(msg.mtext, pid + '0');
    if((msgsnd(id_q, &msg, sizeof(msg), IPC_NOWAIT)) < 0) {
        perror("msgsnd");
        exit(1);
    } else {
        printf("< snd mes type:%6ld  text:%s\n", msg.mtype, msg.mtext);
    }

    // while (1) {
        // sleep(5);
        if (msgrcv(id_q, &msg, sizeof(msg), pid, 0) < 0) {
            perror("msgrcv");
        } else {
            printf("> get mes type:%6ld  text:%s\n", msg.mtype, msg.mtext);
        }
    // }

    return 0;
}

