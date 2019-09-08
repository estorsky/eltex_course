#include "../include/func.h"

FILE *file;
char *file_name;

void init() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, true);
}

void print_help() {
    attron(A_REVERSE);
    attron(A_BOLD);
    mvprintw(LINES-1, 0, " F2 - save file  |  F3 - exit ");
    clrtoeol();
    attroff(A_BOLD);
    attroff(A_REVERSE);
}

void save_file() {
    fclose(file);
    file = fopen(file_name, "w");
    char c = '\0';
    for (int x=0; x < LINES - 1; x++) {
        for (int y=0; y < COLS - 4; y++) {
            c = mvinch(x, y) & A_CHARTEXT;
            fputc(c, file);
        }
        fputc('\n', file);
    }
    fclose(file);
    file = fopen(file_name, "r");
}

