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
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <curses.h>

key_t ipckey_1, ipckey_2;
int semid;
int shmid;
pthread_t tid[2];
pid_t pid;
WINDOW *list;

struct sembuf wl[2] = {{0, 0, 0}, {0, 1, 0}};
struct sembuf wu = {0, -1, 0};

struct message {
    size_t idm;
    pid_t pid;
    char text[100];
};

struct message message;
struct message *p_message;

void hdl () {
    if (semop(semid, wl, 2) == 0) {
        strcpy(p_message->text, "i'm out");
        p_message->pid = pid;
        p_message->idm = p_message->idm + 1;
        semop(semid, &wu, 1);
    }
    shmdt(p_message);
    endwin();
    printf("client killed\n");
    exit(0);
}

void *reader() {
    size_t cur_idm = 0;
    while (1) {
        if (p_message->idm != cur_idm) {
            // printw("#%zu %d: %s\n",p_message->idm, p_message->pid, p_message->text);
            wprintw(list, "%d: %s\n", p_message->pid, p_message->text);
            cur_idm = p_message->idm;
            move(LINES - 1, 0);
            wrefresh(list);
        }
        sleep(1);
    }
}

void *writer() {
    char string[100];
    while (1) {
        move(LINES - 1, 0);
        scanw("%99[^\n]", string);
        if (semop(semid, wl, 2) == 0) {
                strcpy(p_message->text, string);
                p_message->pid = pid;
                p_message->idm = p_message->idm + 1;
                semop(semid, &wu, 1);
        }
        clrtoeol();
    }
}

void initNcurces() {
    initscr();
    cbreak();
    keypad(stdscr, true);
}

int main () {
    struct sigaction sa;
    sa.sa_handler = hdl;
    sigaction(SIGINT, &sa, NULL);

    initNcurces();
    list = newwin(LINES-2, COLS, 0, 0);
    mvhline(LINES - 2, 0, ACS_HLINE, COLS);
    refresh();
    wrefresh(list);
    scrollok(list, true);

    pid = getpid();
    ipckey_1 = ftok("./shared_chat_server", 'M');
    ipckey_2 = ftok("./shared_chat_server", 'S');
    shmid = shmget(ipckey_1, sizeof(struct message), 0666 | IPC_CREAT);
    semid = semget(ipckey_2, 1, 0666 | IPC_CREAT);
    // printw("shmid:%d semid:%d\n", shmid, semid);

    if (semid < 0) {
        printw("Error - %s\n", strerror(errno));
        exit(1);
    }

    p_message = (struct message*) shmat(shmid,(void*) 0, 0);
    strcpy(p_message->text, "i'm join!");
    p_message->pid = pid;
    p_message->idm = p_message->idm + 1;
    pthread_create(&tid[0], NULL, reader, NULL);
    pthread_create(&tid[1], NULL, writer, NULL);

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    shmdt(p_message);
    return 0;
}

