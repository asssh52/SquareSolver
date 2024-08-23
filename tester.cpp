#include "tester.hpp"
#include "sqrt_solver.hpp"
#include "colors.hpp"
#include <math.h>

int Test_Square(int num_test)
{
    solutions roots = {0, 0};
    int n = Solve_Square(keys[num_test].coeffs, &roots);
    if (n != keys[num_test].nroots ||
        fabs(keys[num_test].expected.root1 - roots.root1) > epsilon ||
        fabs(keys[num_test].expected.root2 - roots.root2) > epsilon){
        printf(COLOR_RED "Test #%d Error\n" COLOR_RESET
               "a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg, nroots = %d\n"
               "Expected:\n"
               "x1 = %lg, x2 = %lg, nroots = %d \n\n",
               num_test,
               keys[num_test].coeffs.a, keys[num_test].coeffs.b, keys[num_test].coeffs.c, roots.root1, roots.root2, n,
               keys[num_test].expected.root1, keys[num_test].expected.root2, keys[num_test].nroots);
        return 0;
    }

    printf(COLOR_GREEN "Test #%d Correct\n\n" COLOR_RESET, num_test); // NOTE: total correct
    return 1;
}

void Do_Tests(int start_test, int end_test)
{
    int correct = 0;
    int num_tests = end_test-start_test+1;
    printf("\n"); // wtf
    for (int i = start_test; i <= end_test; i++){
        if (Test_Square(i)){
            correct++;
        }
    }
    if (correct == num_tests){
    printf(COLOR_GREEN "Total correct:%d/%d.\n\n" COLOR_RESET, correct, num_tests);
    }
    else {
    printf(COLOR_RED "Total correct:%d/%d.\n\n" COLOR_RESET, correct, num_tests);
    }
}

