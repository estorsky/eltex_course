#ifndef FUNC_H
#define FUNC_H

typedef struct {
    double a, b;
} cpx;

cpx add (cpx a, cpx b);
cpx sub (cpx a, cpx b);
cpx mul (cpx a, cpx b);
cpx div (cpx a, cpx b);

#endif

