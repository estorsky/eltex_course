#include "../include/func.h"

void info (char * func) {
    func[0] = 'a';
    func[1] = 'd';
    func[2] = 'd';
    func[3] = 'i';
    func[4] = 't';
    func[5] = 'i';
    func[6] = 'o';
    func[7] = 'n';
    func[8] = '\0';
}

cpx addition (cpx x, cpx y) {
    cpx z;
    z.a = x.a + y.a;
    z.b = x.b + y.b;
    return z;
}

