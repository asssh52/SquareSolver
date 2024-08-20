#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum solutions{
    NONE_SOL,
    ONE_SOL,
    TWO_SOL,
    INF_SOL,
    ERROR
};
const double epsilon = 0.000001;
double input[2] = {0, 0, 0}, roots[1] = {0, 0};

int Check_zero(double a){
    if (fabs(a) <= epsilon){return 1;}
    else {return 0;}
}

int Solve_linear(double b, double c, double *roots)
{
    if (Check_zero(b) && !Check_zero(c))  {
        return NONE_SOL;
    } else if (Check_zero(b) && Check_zero(c))  {
        return INF_SOL;
    } else if (!Check_zero(b)) {
        roots[0] = -c / b;
        return ONE_SOL;
    } else {
        return ERROR;
    }
}

int Solution_count(double a, double b, double c)
{
    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0){
        return TWO_SOL;
    } else if (discriminant == 0){
        return ONE_SOL;
    } else {
        return NONE_SOL;
    }
}

int Solve_sqrt(double a, double b, double c, double *roots)
{
    if (a == 0){
        return Solve_linear(b, c, &roots[0]);
    }
    
    switch (Solution_count(a, b, c)) {
        case TWO_SOL:
            roots[0] = (-b + sqrt(b * b - 4 * a * c))/(2 * a);
            roots[1] = (-b - sqrt(b * b - 4 * a * c))/(2 * a);
            return TWO_SOL;
            break;
        case ONE_SOL:
            roots[0] = -b / (2 * a);
            return ONE_SOL;
        default:
            return NONE_SOL;
            break;
    }
}

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
