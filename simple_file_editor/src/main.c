#include "../include/func.h"
#include <malloc.h>
#include <string.h>

bool exit_fe = false;
FILE *file;
char *file_name;

int main (int argc, char* argv[]) {
    init();
    file_name = malloc(strlen(argv[1]));
    if (argc < 3 && argc > 1) {
        file_name = argv[1];
        file = fopen(file_name, "r");
        if(file == NULL) {
            printw("file cant open '%s'\n", file_name);
            getch();
            endwin();
            return 2;
        }
    }
    else {
        printw("enter one file name in arg\n");
        getch();
        endwin();
        return 1;
    }

    char c;
    c = fgetc(file);
    while ( c != EOF) {
        printw("%c", c);
        c = fgetc(file);
    }
    print_help();

    int input;
    int x=0, y=0;
    move(x,y);
    while (exit_fe != true) {
        input = getch();
        switch (input) {
            case KEY_F(3):
                exit_fe = true;
                break;
            case KEY_F(2):
                save_file();
                move(x, y);
                break;
            case KEY_LEFT:
                if (y > 0) {
                    y--;
                    move(x, y);
                }
                break;
            case KEY_RIGHT:
                if (y < COLS - 1) {
                    y++;
                    move(x, y);
                }
                break;
            case KEY_DOWN:
                if (x < LINES - 2) {
                    x++;
                    move(x, y);
                }
                break;
            case KEY_UP:
                if (x > 0) {
                    x--;
                    move(x, y);
                }
                break;
            default:
                y++;
                printw("%c", input);
                break;
        }
    }
    refresh();
    endwin();
    fclose(file);

    return 0;
}

