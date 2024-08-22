#include "user_commands.hpp"
#include "sqrt_solver.hpp"
#include "tester.hpp"
#include <math.h>
#include <string.h>
void Input_CommandInput(int argc, char *argv[], equation *keys)
{
    double input[3] = {0, 0, 0}, roots[2] = {0, 0};
    switch(argc){
        case 1:
            Start_Default(input, roots);
            break;
        case 2:
            if (strcmp(argv[1], "help") == 0){
                Start_Help();
            } else if (strcmp(argv[1], "test") == 0){
                Do_Tests(0, 9, keys);
            } else if (strcmp(argv[1], "default") == 0){
                Start_Default(input, roots);
            } else {
                Start_CommandError();
            }
            break;
        default:
            Start_CommandError();
            break;
    }
}
void Start_Default(double *input, double *roots){
    if (Input_coef(input)){
        Showanswer_Square(input, roots);
        }
}
void Start_Help(){
    printf(COLOR_BLUE "\nCommands:\n" COLOR_CYAN "\'help\'" COLOR_RESET " - gives descriptions of available commands.\n"
    COLOR_CYAN "\'test\'" COLOR_RESET " - launches unit test.\n"
    COLOR_CYAN "\'default\'" COLOR_RESET " or " COLOR_CYAN "\'\'"COLOR_RESET " - launches quadratic equations solver.\n\n"
    );
}
void Start_CommandError(){
    printf(COLOR_RED "\nError!!!\n" COLOR_RESET "Type " COLOR_CYAN "\'help\'" COLOR_RESET " for help.\n\n");
}

int Input_coef(double input[])
{
    printf("\n%s\n", "Введите коэффициенты a,b,c:");
    if (scanf("%lf%lf%lf", &input[0], &input[1], &input[2]) != 3)
    {
        printf("%s\n", "Неправильный ввод");
        return 0;
    }
    for (int i = 0; i < 3; i++){
        if (!isfinite(input[i])){
            printf("%s\n", "Введите конечные числа");
            return 0;
        }
    }
    return 1;
}

void Showanswer_Square(double input[], double roots[])
{
    switch (Solve_Square(input, roots)){
        case NONE_SOL:
            printf("Нет действительных решений\n\n");
            break;
        case ONE_SOL:
            printf("%s%g\n\n", "Одно решение: ",roots[0]);
            break;
        case TWO_SOL:
            printf("%s%g,%g\n\n", "Два решения:",roots[0], roots[1]);
            break;
        case INF_SOL:
            printf("%s\n\n", "Бесконечно много решений");
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
