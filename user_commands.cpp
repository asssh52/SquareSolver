#include "user_commands.hpp"
#include "sqrt_solver.hpp"
#include "tester.hpp"

int Input_coef(double input[])
{
    printf("%s\n", "Введите коэффициенты a,b,c:");
    if (scanf("%lf%lf%lf", &input[0], &input[1], &input[2]) != 3)
    {
        printf("%s\n", "Неправильный ввод");
        return 0;
    }
    return 1;
}

void Showanswer_Square(double input[], double roots[])
{
    switch (Solve_Square(input, roots)){
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
    double input[3] = {0, 0, 0}, roots[2] = {0, 0};
    switch (Ask_User_Test()){
    case 1:
        if (Input_coef(input)){
        Showanswer_Square(input, roots);
        }
        break;
    case 0:
        Do_Tests(0, 9, keys);
        break;
    default:
        printf("Неправильный ввод\n");
        break;
    }
}

int Ask_User_Test(){
    int a = -1;
    printf("Привет!\nНажми 1 для решения квадратных уравнений или 0 для проверки программы.\n");
    scanf("%d", &a);
    return a;
}
