#include "../include/func.h"

void info (char * func) {
    func[0] = 'm';
    func[1] = 'u';
    func[2] = 'l';
    func[3] = 't';
    func[4] = 'i';
    func[5] = 'p';
    func[6] = 'l';
    func[7] = 'i';
    func[8] = 'c';
    func[9] = 'a';
    func[10] = 't';
    func[11] = 'i';
    func[12] = 'o';
    func[13] = 'n';
    func[14] = '\0';
}

cpx multiplication (cpx x, cpx y) {
    cpx z;
    z.a = x.a * y.a;
    z.b = x.b * y.b;
    return z;
}

