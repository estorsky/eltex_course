#include "../include/func.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

#define WRITE_END 1
#define READ_END 0

int main () {
    pid_t pid;
    int fd[2];

    pipe(fd);
    pid = fork();

    if(pid==0) {
        dup2(fd[WRITE_END], STDOUT_FILENO);
        close(fd[READ_END]);
        close(fd[WRITE_END]);
        execlp("ls","ls","-lah", NULL);
        fprintf(stderr, "Failed to execute\n");
        exit(1);
    } else {
        pid=fork();
        if(pid==0) {
            dup2(fd[READ_END], STDIN_FILENO);
            close(fd[WRITE_END]);
            close(fd[READ_END]);
            // execlp("grep", "grep", "*inc*", NULL);
            execlp("wc", "wc", "-l", NULL);
            fprintf(stderr, "Failed to execute\n");
            exit(1);
        } else {
            int status;
            close(fd[READ_END]);
            close(fd[WRITE_END]);
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

