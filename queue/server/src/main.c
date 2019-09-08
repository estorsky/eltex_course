#include "../include/func.h"
#include <sys/types.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS   3
#define MAX_TEXT_SIZE 100

struct mbuf {
    long mtype;
    char mtext[MAX_TEXT_SIZE];
};

pthread_t tid[NUM_THREADS];

key_t key_1;
key_t key_2;
int idq_1;
int idq_2;

void *sender () {
    pid_t pid_client;
    pthread_t tid = pthread_self();
    char string_time[100];
    struct mbuf msg;
    printf("thread start working tid = %ld\n", tid);
    while (1) {
        if (msgrcv(idq_2, &msg, sizeof(msg), 1, 0) < 0) {
            perror("msgrcv");
        } else {
            printf("***%ld: > get mes type:%6ld  text:%s \tfrom qid:%6d\n",
                    tid%1000,
                    msg.mtype,
                    msg.mtext,
                    idq_2);
            pid_client = atoi(msg.mtext);
            msg.mtype = pid_client;
            getTime(string_time);
            strcpy(msg.mtext, string_time);
            if((msgsnd(idq_1, &msg, sizeof(msg), 0)) < 0) {
                perror("msgsnd");
            } else {
                printf("***%ld: < snd mes type:%6ld  text:%s  to qid: %6d\n\n",
                        tid%1000,
                        msg.mtype,
                        msg.mtext,
                        idq_1);
            }
        }
    }
}

int main () {
    key_1 = ftok("/home/dmitry/Dropbox/courses/eltex/queue/Makefile", 'c');
    key_2 = ftok("/home/dmitry/Dropbox/courses/eltex/queue/Makefile", 's');
    idq_1 = msgget(key_1, 0666 | IPC_CREAT);
    idq_2 = msgget(key_2, 0666 | IPC_CREAT);
    struct mbuf msg;

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&tid[i], NULL, sender, NULL);
    }

    while (1) {
        if (msgrcv(idq_1, &msg, sizeof(msg), 1, 0) < 0) {
            perror("msgrcv");
        } else {
            printf("> get mes type:%6ld  text:%s from qid:%6d\n",
                    msg.mtype,
                    msg.mtext,
                    idq_1);
            if((msgsnd(idq_2, &msg, sizeof(msg), 0)) < 0) {
                perror("msgsnd");
            } else {
                printf("< snd mes type:%6ld  text:%s to   qid: %6d\n\n",
                        msg.mtype,
                        msg.mtext,
                        idq_2);
            }
        }
    }

    return 0;
}

