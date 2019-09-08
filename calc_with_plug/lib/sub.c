#include "../include/func.h"

void info (char * func) {
    func[0] = 's';
    func[1] = 'u';
    func[2] = 'b';
    func[3] = 't';
    func[4] = 'r';
    func[5] = 'a';
    func[6] = 'c';
    func[7] = 't';
    func[8] = 'i';
    func[9] = 'o';
    func[10] = 'n';
    func[11] = '\0';
}

cpx subtraction (cpx x, cpx y) {
    cpx z;
    z.a = x.a - y.a;
    z.b = x.b - y.b;
    return z;
}

