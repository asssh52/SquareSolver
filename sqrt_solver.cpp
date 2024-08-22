#include "sqrt_solver.hpp"
#include <math.h>

int If_Zero(double a){
    if (fabs(a) <= epsilon){
        return 1;
    }
    return 0;
}

int Solve_Linear(double *input, double *roots)
{
    double b = input[1];
    double c = input[2];

    if (If_Zero(b) && !If_Zero(c))  {
        return NONE_SOL;
    } else if (If_Zero(b) && If_Zero(c))  {
        return INF_SOL;
    } else if (!If_Zero(b)) {
        roots[0] = -c / b;
        return ONE_SOL;
    } else {
        return ERROR;
    }
}

int Solution_count(double *input)
{
    double a = input[0];
    double b = input[1];
    double c = input[2];

    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0){
        return TWO_SOL;
    } else if (discriminant == 0){
        return ONE_SOL;
    } else {
        return NONE_SOL;
    }
}

int Solve_Square(double *input, double *roots)
{
    double a = input[0];
    double b = input[1];
    double c = input[2];

    if (a == 0){
        return Solve_Linear(input, roots);
    }

    switch (Solution_count(input)) {
        case TWO_SOL:
            roots[0] = (-b - sqrt(b * b - 4 * a * c))/(2 * a);
            roots[1] = (-b + sqrt(b * b - 4 * a * c))/(2 * a);
            if (a < 0){
                double temp;
                temp = roots[1];
                roots[1] = roots[0];
                roots[0] = temp;
            }
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
