#ifndef functions_h
#define functions_h

#include <stdio.h>

int Solve_linear(double b, double c, double *roots);
int Solution_count(double a, double b, double c);
int Solve_sqrt(double a, double b, double c, double *roots);
int Check_zero(double a);
const double epsilon = 0.000001;
enum solutions{
    NONE_SOL,
    ONE_SOL,
    TWO_SOL,
    INF_SOL,
    ERROR
};
double input[3], roots[2];

#endif
