#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

double input[3] = {0, 0, 0}, roots[2] = {0, 0};

void Input_coef(void)
{
    printf("%s\n", "Введите коэффициенты a,b,c:");
    if (scanf("%lf%lf%lf", &input[0], &input[1], &input[2]) != 3)
    {
        printf("%s\n", "неправильный ввод");
    }
}

void Output_function(void)
{
    switch (Solve_sqrt(input[0], input[1], input[2], roots)){
        case NONE_SOL:
            printf("нет действительных решений\n");
            break;
        case ONE_SOL:
            printf("%s%g\n", "одно решение: ",roots[0]);
            break;
        case TWO_SOL:
            printf("%s%g,%g\n", "два решения:",roots[0], roots[1]);
            break;
        case INF_SOL:
            printf("%s\n", "бесконечно много решений");
            break;
    }
}

int main(void){
    Input_coef();
    Output_function();
    return 0;
}
