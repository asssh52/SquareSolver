#include "user_commands.hpp"
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
    switch (Solve_Square(input[0], input[1], input[2], roots)){
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

void Choose_Path(equation *keys){
    if (Ask_User_Test() == 1){
        double input[3] = {0, 0, 0}, roots[2] = {0, 0};
        Input_coef(input);
        Showanswer_Square(input, roots);
    }
    else {
        Do_Tests(0, 8, keys);
    }
}

int Ask_User_Test(){
    int a = 1;
    printf("Привет!\nНажми 1 для решения квадратных уравнений или 0 для проверки программы.\n");
    scanf("%d", &a);
    return a;
}
