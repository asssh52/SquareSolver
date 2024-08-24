#include "user_commands.hpp"
#include "sqrt_solver.hpp"
#include "tester.hpp"
#include "colors.hpp"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void Start_Help();
void Start_Error();
void Start_ErrorFlags();
int Input_Coef(coefficients *coeffs);
void Showanswer_Square(coefficients coeffs, solutions *roots);
int Start_Default_FromFile(coefficients *coeffs, solutions *roots, const char *file_link);
void Input_CommandInput(int argc, const char *argv[]);
int Check_FileLinkExist(int num_arg, int argc);
int Input_FileLink(const char* file_link, FILE **fp);
int InputCoef_FromFile(coefficients *coeffs, FILE *fp);
int CheckFinite(coefficients *coeffs);
int SolveSquare_FromFile(coefficients *coeffs, solutions *roots, FILE *fp, const char *file_link);

void Start_Error(){
    printf(COLOR_RED "\nError!!!\n" COLOR_RESET "Type " COLOR_CYAN "\'help\'" COLOR_RESET " for help.\n\n");
}

void Start_ErrorFlags(){
    printf(COLOR_RED "\nError!!!\n" COLOR_RESET "Unknown flags. Type " COLOR_CYAN "\'help\'" COLOR_RESET " for help.\n\n");
}

void Start_Help(){
    printf(COLOR_BLUE "\nAvailable commands/flags:\n"
           COLOR_CYAN "\"help\""    COLOR_RESET " - gives descriptions of available commands.\n"
           COLOR_CYAN "\"test\""    COLOR_RESET " - launches unit test.\n"
           COLOR_CYAN "\"default\"" COLOR_RESET " - launches quadratic equations with input solver from console.\n"
           COLOR_CYAN "\"file "     COLOR_GREEN "file_name" COLOR_CYAN "\"" COLOR_RESET " - launches quadratic equations solver with input from linked file.\n\n"
    );
}

int Input_Coef(coefficients *coeffs){
    printf("\n%s\n", "Введите коэффициенты a,b,c:");
    if (scanf("%lf%lf%lf", &(coeffs->a), &(coeffs->b), &(coeffs->c)) != 3) //??????
    {
        printf("%s\n", "Неправильный ввод");
        return 1;
    }
    MYASSERT(coeffs != NULL);
    if (!isfinite(coeffs->a) || !isfinite(coeffs->b) || !isfinite(coeffs->c)){
            printf("%s\n", "Введите конечные числа");
            return 1;
        }
    return 0;
}

void Showanswer_Square(coefficients coeffs, solutions *roots)
{
    MYASSERT(roots != NULL);
    switch (Solve_Square(coeffs, roots)){
        case NONE_SOL:
            printf("Нет действительных решений\n\n");
            break;
        case ONE_SOL:
            printf("%s%g\n\n", "Одно решение: ",roots->root1);
            break;
        case TWO_SOL:
            printf("%s%g,%g\n\n", "Два решения:",roots->root1, roots->root2);
            break;
        case INF_SOL:
            printf("%s\n\n", "Бесконечно много решений");
            break;
    }
}

void Start_Default(coefficients *coeffs, solutions *roots){
    MYASSERT(coeffs != NULL && roots != NULL);
    if (!Input_Coef(coeffs)){
        Showanswer_Square(*coeffs, roots);
    }
}

int Command_Output(coefficients *coeffs, solutions *roots, flags *list_of_flags){
    MYASSERT(coeffs != NULL && roots != NULL && list_of_flags != NULL);
    if (list_of_flags->error){
        Start_ErrorFlags();
        return 1;
    }
    if (list_of_flags->file){
        Start_Default_FromFile(coeffs, roots, list_of_flags->file_argv);
    }
    if (list_of_flags->help){
        Start_Help();
    }
    if (list_of_flags->test){
        Do_Tests(0, 9);
    }
    if (list_of_flags->main){
        Start_Default(coeffs, roots);
    }
    return 0;
}

/*void Check_Flag(const char *argv[], int *num_arg, int argc, flags *list_of_flags){
    MYASSERT(argv != NULL && num_arg != NULL && list_of_flags != NULL);
    if (strcmp(argv[*num_arg], "help") == 0){
            list_of_flags->help = 1;
        } else if (strcmp(argv[*num_arg], "test") == 0){
            list_of_flags->test = 1;
        } else if (strcmp(argv[*num_arg], "default") == 0){
            list_of_flags->main = 1;
        } else if (strcmp(argv[*num_arg], "file") == 0){
            if (!Check_FileLinkExist(*num_arg, argc)){
                list_of_flags->file = 1;
                (*num_arg)++;
                list_of_flags->file_argv = argv[*num_arg];
            }
        } else {
            list_of_flags->error = 1;
        }
}*/

void Check_Flag(const char *argv[], int *num_arg, int argc, flags *list_of_flags){

    MYASSERT(argv != NULL && num_arg != NULL && list_of_flags != NULL);

    if (strcmp(argv[*num_arg], "help") == 0){
            list_of_flags->help = 1;

        } else if (strcmp(argv[*num_arg], "test") == 0){
            list_of_flags->test = 1;

        } else if (strcmp(argv[*num_arg], "default") == 0){
            list_of_flags->main = 1;

        } else if (strcmp(argv[*num_arg], "file") == 0){
            if (!Check_FileLinkExist(*num_arg, argc)){
                list_of_flags->file = 1;
                (*num_arg)++;
                list_of_flags->file_argv = argv[*num_arg];
            }

        } else {
            list_of_flags->error = 1;
        }
}

int Check_FileLinkExist(int num_arg, int argc){
    if (num_arg >= --argc){
        printf(COLOR_RED "\nFile link does not exist.\n" COLOR_RESET);
        return 1;
    }
    return 0;
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
int Start_Default_FromFile(coefficients *coeffs, solutions *roots, const char *file_link){
    MYASSERT(coeffs != NULL && roots != NULL && file_link != NULL);
    FILE *fp = NULL;
    if (!Input_FileLink(file_link, &fp)){
        SolveSquare_FromFile(coeffs, roots, fp, file_link);
    }
    fclose(fp);
    return 0;
}
int SolveSquare_FromFile(coefficients *coeffs, solutions *roots, FILE *fp, const char *file_link){
    MYASSERT(coeffs != NULL && roots != NULL && file_link != NULL && fp != NULL);
    if (InputCoef_FromFile(coeffs, fp)){
        printf("Неправильный формат ввода в " COLOR_BLUE "%s" COLOR_RESET ".\n\n", file_link);
        fclose(fp);
        return 1;
    } else if (CheckFinite(coeffs)){
        printf("Введите конечные числа в " COLOR_BLUE "%s" COLOR_RESET ".\n\n", file_link);
        fclose(fp);
        return 1;
    }
    Showanswer_Square(*coeffs, roots);
    return 0;
}

int Input_FileLink(const char* file_link, FILE **fp){
    MYASSERT(file_link != NULL);
    *fp = fopen(file_link, "r");
    if(*fp == NULL) {
        perror(COLOR_RED "\nError!!!\n" COLOR_RESET "Не удалось открыть файл. Проверьте адрес файла");
        return 1;
    }
    printf(COLOR_CYAN "\nRead from file: " COLOR_BLUE "%s" COLOR_RESET "\n", file_link);
    return 0;
}

int InputCoef_FromFile(coefficients *coeffs, FILE *fp){
    MYASSERT(coeffs != NULL && fp != NULL);
    if (fscanf(fp, "%lf%lf%lf", &(coeffs->a), &(coeffs->b), &(coeffs->c)) == 3){
        return 0;
    }
    return 1;
}

int CheckFinite(coefficients *coeffs){
    MYASSERT(coeffs != NULL);
    if (isfinite(coeffs->a) && isfinite(coeffs->b) && isfinite(coeffs->c)){
        return 0;
    }
    return 1;
}

void Input_CommandInput(int argc, const char *argv[])
{
    flags command_flags = {0, 0, 0, 0, 0, NULL};
    coefficients coeffs = {0, 0, 0};
    solutions roots = {0, 0};
    if (argc == ONE_ARG){
        Start_Default(&coeffs, &roots);
    } else {
        for (int num_arg = 1; num_arg < argc; num_arg++){
            Check_Flag(argv, &num_arg, argc, &command_flags);
        }
        Command_Output(&coeffs, &roots, &command_flags);
    }
}
