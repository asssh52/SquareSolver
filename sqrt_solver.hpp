#ifndef functions_hpp
#define functions_hpp

#include <stdio.h>

int Solve_Linear(double *input, double *roots);
int Solution_count(double *input);
int Solve_Square(double *input, double *roots);
int If_Zero(double a);
static const double epsilon = 1e-5;
enum solutions{
    NONE_SOL,
    ONE_SOL,
    TWO_SOL,
    INF_SOL,
    ERROR
};

#endif
