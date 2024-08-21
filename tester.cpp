#include "tester.hpp"
#include "sqrt_solver.hpp"
#include <math.h>

int Test_Square(int num_test, equation *keys)
{
    double roots[2] = {0, 0};
    int n = Solve_Square(keys[num_test].coefficients, roots);
    if (n != keys[num_test].nroots ||
        fabs(keys[num_test].solutions[0] - roots[0]) > epsilon ||
        fabs(keys[num_test].solutions[1] - roots[1]) > epsilon){
        printf("Error test: %d.\n"
               "a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg, nroots = %d\n"
               "Expected:\n"
               "x1 = %lg, x2 = %lg, nroots = %d \n\n",
               num_test,
               keys[num_test].coefficients[0], keys[num_test].coefficients[1], keys[num_test].coefficients[2], roots[0], roots[1], n,
               keys[num_test].solutions[0], keys[num_test].solutions[1], keys[num_test].nroots);
        return 1;
    }
    printf("Test #%d Correct\n\n", num_test); // NOTE: total correct
    return 0;
}

void Do_Tests(int start_test, int end_test, equation *keys)
{
    for (int i = start_test; i <= end_test; i++){
        Test_Square(i, keys);
    }
}

