#include "sqrt_solver.hpp"
#include <math.h>

double Power(double a, int pow) // TODO: with epsilon
{
    double memory = 1;
    for (int i = 0; i < pow; i++) memory*=a;
    return memory;
}

int Check_zero(double a){ // TODO: rename
    if (fabs(a) <= epsilon){
        return 1;
    }
    return 0;
}

int Solve_linear(double b, double c, double *roots)
{
    if (Check_zero(b) && !Check_zero(c))  {
        return NONE_SOL;
    } else if (Check_zero(b) && Check_zero(c))  {
        return INF_SOL;
    } else if (!Check_zero(b)) {
        roots[0] = -c / b;
        return ONE_SOL;
    } else {
        return ERROR;
    }
}

int Solution_count(double a, double b, double c) // DO
{
    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0){
        return TWO_SOL;
    } else if (discriminant == 0){
        return ONE_SOL;
    } else {
        return NONE_SOL;
    }
}

int Solve_sqrt(double a, double b, double c, double *roots)
{
    if (a == 0){
        return Solve_linear(b, c, &roots[0]);
    }

    switch (Solution_count(a, b, c)) {
        case TWO_SOL:
            roots[0] = (-b - sqrt(b * b - 4 * a * c))/(2 * a);
            roots[1] = (-b + sqrt(b * b - 4 * a * c))/(2 * a);
            return TWO_SOL;
            break;
        case ONE_SOL:
            roots[0] = -b / (2 * a);
            return ONE_SOL;
        default:
            return NONE_SOL;
            break;
    }
}
