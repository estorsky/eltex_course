#ifndef FUNC_H
#define FUNC_H

#include <curses.h>

void init();
void print_help();
void save_file();

extern FILE *file;
extern char *file_name;

#endif

