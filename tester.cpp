#include "tester.hpp"
#include "sqrt_solver.hpp"
#include <math.h>

#define COLOR_GREEN        "\x1b[32m"
#define RESET_ALL          "\x1b[0m"
#define COLOR_RED          "\x1b[31m"

int Test_Square(int num_test, equation *keys)
{
    double roots[2] = {0, 0};
    int n = Solve_Square(keys[num_test].coefficients, roots);
    if (n != keys[num_test].nroots ||
        fabs(keys[num_test].solutions[0] - roots[0]) > epsilon ||
        fabs(keys[num_test].solutions[1] - roots[1]) > epsilon){
        printf(COLOR_RED "Error test: %d.\n" RESET_ALL
               "a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg, nroots = %d\n"
               "Expected:\n"
               "x1 = %lg, x2 = %lg, nroots = %d \n\n",
               ++num_test,
               keys[num_test].coefficients[0], keys[num_test].coefficients[1], keys[num_test].coefficients[2], roots[0], roots[1], n,
               keys[num_test].solutions[0], keys[num_test].solutions[1], keys[num_test].nroots);
        return 0;
    }

    printf(COLOR_GREEN "Test #%d Correct\n\n" RESET_ALL, ++num_test); // NOTE: total correct
    return 1;
}

void Do_Tests(int start_test, int end_test, equation *keys)
{
    int correct = 0;
    printf("\n");
    for (int i = start_test; i <= end_test; i++){
        if (Test_Square(i, keys)){
            correct++;
        }
    }
    printf("Total correct:%d/%d.\n\n", correct, end_test-start_test+1); // color this
}

