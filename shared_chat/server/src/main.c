#include "../include/func.h"
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

key_t ipckey_1, ipckey_2;
int semid;
int shmid;
char *str;
pid_t pid;

struct sembuf wl[2] = {{0, 0, 0}, {0, 1, 0}};
struct sembuf wu = {0, -1, 0};

struct message {
    size_t idm;
    pid_t pid;
    char text[100];
};

void hdl (int sig) {
    shmdt(str);
    shmctl(shmid, IPC_RMID, 0);
    semctl(semid, 1, IPC_RMID);
    printf("server killed\n");
    exit(0);
}

int main () {
    struct sigaction sa;
    sa.sa_handler = hdl;
    sigaction(SIGINT, &sa, NULL);

    ipckey_1 = ftok("./shared_chat_server", 'M');
    ipckey_2 = ftok("./shared_chat_server", 'S');
    shmid = shmget(ipckey_1, sizeof(struct message), 0666 | IPC_CREAT);
    semid = semget(ipckey_2, 1, 0666 | IPC_CREAT);

    if (semid < 0) {
        printf("Error - %s\n", strerror(errno));
        exit(1);
    }

    struct message *p_message;
    p_message = (struct message*) shmat(shmid,(void*) 0, 0);
    p_message->idm = 1;
    pid = getpid();
    p_message->pid = pid;
    strcpy(p_message->text, "server starting");
    printf("server starting\nshmid:%d  semid:%d  pid:%d\n", shmid, semid, pid);

    pause();

    shmdt(str);
    shmctl(shmid, IPC_RMID, 0);
    return 0;
}

