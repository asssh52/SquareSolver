#include "sqrt_solver.hpp"
#include "globals.hpp"
#include <math.h>

int If_Zero(double a){
    if (fabs(a) <= epsilon){
        return 1;
    }
    return 0;
}

int Solve_Linear(coefficients coeffs, solutions *roots)
{
    double b = coeffs.b;
    double c = coeffs.c;
    if (If_Zero(b) && !If_Zero(c))  {
        return NONE_SOL;
    } else if (If_Zero(b) && If_Zero(c))  {
        return INF_SOL;
    } else if (!If_Zero(b)) {
        roots->root1 = -c / b;
        return ONE_SOL;
    } else {
        return ERROR;
    }
}

int Solution_count(coefficients coeffs)
{
    double a = coeffs.a;
    double b = coeffs.b;
    double c = coeffs.c;
    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0){
        return TWO_SOL;
    } else if (discriminant == 0){
        return ONE_SOL;
    } else {
        return NONE_SOL;
    }
}

int Solve_Square(coefficients coeffs, solutions *roots)
{
    double a = coeffs.a;
    double b = coeffs.b;
    double c = coeffs.c;
    if (a == 0){
        return Solve_Linear(coeffs, roots);
    }

    switch (Solution_count(coeffs)) {
        case TWO_SOL:
            roots->root1 = (-b - sqrt(b * b - 4 * a * c))/(2 * a);
            roots->root2 = (-b + sqrt(b * b - 4 * a * c))/(2 * a);
            if (a < 0){
                double temp;
                temp = roots->root1;
                roots->root1 = roots->root2;
                roots->root2 = temp;
            }
            return TWO_SOL;
            break;
        case ONE_SOL:
            roots->root1 = -b / (2 * a);
            return ONE_SOL;
        default:
            return NONE_SOL;
            break;
    }
}
