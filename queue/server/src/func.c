#include "../include/func.h"
#include <time.h>
#include <stdio.h>

void getTime(char *string_time) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    sprintf(string_time, "%d-%d-%d %d:%d:%d",
            tm.tm_year + 1900,
            tm.tm_mon + 1,
            tm.tm_mday,
            tm.tm_hour,
            tm.tm_min,
            tm.tm_sec);
}

