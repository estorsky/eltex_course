#include "../include/func.h"

void info (char * func) {
    func[0] = 'd';
    func[1] = 'i';
    func[2] = 'v';
    func[3] = 'i';
    func[4] = 's';
    func[5] = 'i';
    func[6] = 'o';
    func[7] = 'n';
    func[8] = '\0';
}

// char *info () {
    // return "division";
// }

cpx division (cpx x, cpx y) {
    cpx z;
    z.a = x.a / y.a;
    z.b = x.b / y.b;
    return z;
}

