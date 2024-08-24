#include "sqrt_solver.hpp"
#include "tester.hpp"
#include "user_commands.hpp"
#include <math.h>

double Solve_Discriminant(coefficients coeffs);
int Solve_Linear(coefficients coeffs, solutions *roots);
int If_Zero(double a);
int Solution_count(double discriminant);
int Solve_Square(coefficients coeffs, solutions *roots);

int If_Zero(double a){
    if (fabs(a) <= epsilon){
        return 1;
    }
    return 0;
}
int Solve_Linear(coefficients coeffs, solutions *roots){
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

int Solution_count(double discriminant){
    if (discriminant > 0){
        return TWO_SOL;
    } else if (If_Zero(discriminant)){
        return ONE_SOL;
    } else {
        return NONE_SOL;
    }
}

double Solve_Discriminant(coefficients coeffs){
    return (coeffs.b * coeffs.b - 4 * coeffs.a * coeffs.c);
}

int Solve_Square(coefficients coeffs, solutions *roots)
{
    MYASSERT(roots != NULL);

    double a = coeffs.a;
    double b = coeffs.b;
    double c = coeffs.c;

    if (a == 0){
        return Solve_Linear(coeffs, roots);
    }

    double discriminant = Solve_Discriminant(coeffs);

    switch (Solution_count(discriminant)) {

        case TWO_SOL:
            roots->root1 = (-b - sqrt(discriminant))/(2 * a);
            roots->root2 = (-b + sqrt(discriminant))/(2 * a);

            if (a < 0){
                double temp = roots->root1;
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
