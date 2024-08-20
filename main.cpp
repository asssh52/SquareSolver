#include <stdio.h>
#include <stdlib.h>
#include "sqrt_solver.h"

void Input_coef(void)
{
    printf("%s\n", "Введите коэффициенты a,b,c:");
    if (scanf("%lf%lf%lf", &input[0], &input[1], &input[2]) != 3)
    {
        printf("%s\n", "Неправильный ввод");
    }
}

void Output_function(void)
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

int main(void){
    double input[3] = {0, 0, 0}, roots[2] = {0, 0};
    Input_coef();
    Output_function();
    return 0;
}
