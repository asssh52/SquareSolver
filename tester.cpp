#include "tester.hpp"
#include "sqrt_solver.hpp"
#include <math.h>

int Test_Square(int num_test, equasion *keys)
{
    double a = keys[num_test].coefficients[0];
    double b = keys[num_test].coefficients[1];
    double c = keys[num_test].coefficients[2];
    double x1_correct = keys[num_test].solutions[0];
    double x2_correct = keys[num_test].solutions[1];
    int nroots_correct = keys[num_test].nroots;
    double roots[2] = {0, 0};

    int n = Solve_sqrt(a, b, c, roots);
    if (n != nroots_correct ||
        Round_To(roots[0], 4)  != Round_To(x1_correct, 4) ||
        Round_To(roots[1], 4)  != Round_To(x2_correct, 4)){
        printf("Error test: %d.\n"
               "a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg, nroots = %d\n"
               "Expected:\n"
               "x1 = %lg, x2 = %lg, nroots = %d \n\n",
               num_test,
               a, b, c, roots[0], roots[1], n,
               x1_correct, x2_correct, nroots_correct);
        return 1;
    }
    printf("Test #%d Correct\n\n", num_test); // NOTE: total correct
    return 0;
}

void Do_Tests(int start_test, int end_test, equasion *keys)
{
    for (int i = start_test; i <= end_test; i++){
        Test_Square(i, keys);
    }
}

double Round_To(double number, int digits)
{
    return round(number * Power(10, digits))/Power(10, digits);
}
