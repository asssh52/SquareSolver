#include <stdio.h>
#include <stdlib.h>
#include "sqrt_solver.hpp"
#include "tester.hpp"

void Input_coef(double input[])
{
    printf("%s\n", "Введите коэффициенты a,b,c:");
    if (scanf("%lf%lf%lf", &input[0], &input[1], &input[2]) != 3)
    {
        printf("%s\n", "Неправильный ввод");
    }
}

void Showanswer_Square(double input[], double roots[])
{
    switch (Solve_sqrt(input[0], input[1], input[2], roots)){
        case NONE_SOL:
            printf("Нет действительных решений\n");
            break;
        case ONE_SOL:
            printf("%s%g\n", "Одно решение: ",roots[0]);
            break;
        case TWO_SOL:
            printf("%s%g,%g\n", "Два решения:",roots[0], roots[1]);
            break;
        case INF_SOL:
            printf("%s\n", "Бесконечно много решений");
            break;
    }
}

equasion keys[9] {
    {  {1,  2, 3},{0, 0}, NONE_SOL},
    {  {1, -4, 3},{1, 3}, TWO_SOL},
    {{100, -4,-3},{-0.154356, 0.194356}, TWO_SOL},
    {  {1,  0,-9},{-3, +3}, TWO_SOL},
    {  {0,  2, 3},{-1.5, 0}, ONE_SOL},
    {  {0,  2, 0},{0, 0}, ONE_SOL},
    {  {0,  0, 3},{0, 0}, NONE_SOL},
    {  {7, -9, 2},{0.285714, 1}, TWO_SOL},
    {  {0,  0, 0},{0, 0}, INF_SOL}
};

int main(void){ // TODO: if for tests
    /*double input[3] = {0, 0, 0}, roots[2] = {0, 0};
    Input_coef(input);
    Output_function(input, roots);*/
    Do_Tests(0, 8, keys);
    return 0;
}
