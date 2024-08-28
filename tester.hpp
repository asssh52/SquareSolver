#ifndef tester_hpp
#define tester_hpp
#include <stdio.h>

enum num_solutions{
    NONE_SOL,
    ONE_SOL,
    TWO_SOL,
    INF_SOL,
    ERROR
};

typedef struct{
    double a;
    double b;
    double c;
} coefficients;

typedef struct{
    double root1;
    double root2;
} solutions;

typedef struct{
    coefficients coeffs;
    solutions expected;
    int nroots;
} test_equation;

const test_equation keys[] = { // База данных для проверки программы
    {  1,  2, 3,         0,        0, NONE_SOL},
    {  1, -4, 3,         1,        3, TWO_SOL },
    {100, -4,-3, -0.154356, 0.194356, TWO_SOL },
    {  1,  0,-9,        -3,       +3, TWO_SOL },
    {  0,  2, 3,      -1.5,        0, ONE_SOL },
    {  0,  2, 0,         0,        0, ONE_SOL },
    {  0,  0, 3,         0,        0, NONE_SOL},
    {  7, -9, 2,  0.285714,        1, TWO_SOL },
    {  0,  0, 0,         0,        0, INF_SOL },
    { -4,  9,-3,   0.40693,  1.84307, TWO_SOL }
};

const size_t NUMTEST = 9;
const double epsilon = 1e-5;
void Do_Tests(int start_test, int end_test);

/*********************************************************************
 * @file  tester.cpp
 *
 * @brief Tester functions
 *********************************************************************/

#endif
