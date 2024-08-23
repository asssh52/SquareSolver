#include "user_commands.hpp"
#include "sqrt_solver.hpp"
#include "tester.hpp"
#include <math.h>
#include <string.h>
#include <stdio.h>
void Input_CommandInput(int argc, char *argv[], equation *keys)
{
    flags command_flags = {0, 0, 0};
    double input[3] = {NAN, NAN, NAN}, roots[2] = {0, 0};
    if (argc == 1){
        Start_Default(input, roots);
    } else if (argc == 3 && strcmp(argv[1], "file") == 0) {
        Start_Default_Fromfile(input, roots, argv[2]);
    } else {
        for (int i = 1; i < argc; i++){
            Check_Flag(argv[i], &command_flags);
        }
        Command_Output(keys, input, roots, &command_flags);
    }
}
void Command_Output(equation *keys, double *input, double *roots, flags *list_of_flags){
    if (list_of_flags->list_flag[0]){
        Start_Help();
    }
    if (list_of_flags->list_flag[1]){
        Do_Tests(0, 9, keys);
    }
    if (list_of_flags->list_flag[2]){
        Start_Default(input, roots);
    }
}
void Check_Flag(char *flag, flags *list_of_flags){
    if (strcmp(flag, "help") == 0){
            list_of_flags->list_flag[0] = 1;
        } else if (strcmp(flag, "test") == 0){
            list_of_flags->list_flag[1] = 1;
        } else if (strcmp(flag, "default") == 0){
            list_of_flags->list_flag[2] = 1;
        } else {
            Start_CommandError();
        }
}
/* work in progress
char *GetConfig_InputFile(){
    FILE *fp = fopen("config.txt", "r");

    char storage[100][2];
    char* meow[2] = {&storage[0][0], &storage[0][1]};
    fscanf(fp, "%s%s", meow);
    printf("%s\n%s", storage);

    char str[1000];
    fscanf(fp, "%s", &str[0]);
    printf("%s", str);

    fclose(fp);
    return "config.txt";
}*/
int Start_Default_Fromfile(double *input, double *roots, char *file_link){
    FILE *fp = fopen(file_link, "r");
    printf(COLOR_CYAN "\nRead from file: " COLOR_BLUE "%s" COLOR_RESET "\n", file_link);

    if(fp == NULL) {
        printf("Не удалось открыть файл.\n\n");
        return 1;
    }
    if (fscanf(fp, "%lf%lf%lf", &input[0], &input[1], &input[2]) != 3){
        printf("Неправильный формат ввода в " COLOR_BLUE "%s" COLOR_RESET ".\n\n", file_link);
    } else {
        for (int i = 0; i < 3; i++){
            if (!isfinite(input[i])){
                printf("%s\n", "Введите конечные числа.\n\n");
                return 1;
            }
        }
        Showanswer_Square(input, roots);
    }
    fclose(fp);
    return 0;
}
void Start_Default(double *input, double *roots){
    if (!Input_Coef(input)){
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

int Input_Coef(double input[]){
    printf("\n%s\n", "Введите коэффициенты a,b,c:");
    if (scanf("%lf%lf%lf", &input[0], &input[1], &input[2]) != 3)
    {
        printf("%s\n", "Неправильный ввод");
        return 1;
    }
    for (int i = 0; i < 3; i++){
        if (!isfinite(input[i])){
            printf("%s\n", "Введите конечные числа");
            return 1;
        }
    }
    return 0;
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
