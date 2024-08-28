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

/**
 * @brief Prints error message in stdout.
*/
void Start_Error(){
    printf(COLOR_RED "\nError!!!\n" COLOR_RESET "Type " COLOR_CYAN "\'help\'" COLOR_RESET " for help.\n\n");
}

/**
 * @brief Prints unknown flags message in stdout.
*/
void Start_ErrorFlags(){
    printf(COLOR_RED "\nError!!!\n" COLOR_RESET "Unknown flags. Type " COLOR_CYAN "\'help\'" COLOR_RESET " for help.\n\n");
}

/**
 * @brief Prints help message in stdout.
*/
void Start_Help(){
    printf(COLOR_BLUE "\nAvailable commands/flags:\n"
           COLOR_CYAN "\"help\""    COLOR_RESET " - gives descriptions of available commands.\n"
           COLOR_CYAN "\"test\""    COLOR_RESET " - launches unit test.\n"
           COLOR_CYAN "\"default\"" COLOR_RESET " - launches quadratic equations with input solver from console.\n"
           COLOR_CYAN "\"file "     COLOR_GREEN "file_name" COLOR_CYAN "\"" COLOR_RESET " - launches quadratic equations solver with input from linked file.\n\n"
    );
}
/**
 * @brief Gets coefficients from stdin.
 * @param Pointer to coefficients structure.
 * @return Return 0 if coefficients were assigned correctly, 1 in other cases.
*/
int Input_Coef(coefficients *coeffs){
    printf("\n%s\n", "Enter coefficients a,b,c:");
    if (scanf("%lf%lf%lf", &(coeffs->a), &(coeffs->b), &(coeffs->c)) != 3) //??????
    {
        printf("%s\n", "Wrong format");
        return 1;
    }
    MYASSERT(coeffs != NULL);
    if (!isfinite(coeffs->a) || !isfinite(coeffs->b) || !isfinite(coeffs->c)){
            printf("%s\n", "Enter finite coefficients");
            return 1;
        }
    return 0;
}

/**
 * @brief Outputs the results to console.
 * @param Coefficients structure.
 * @param Pointer to solutions structure.
*/

void Showanswer_Square(coefficients coeffs, solutions *roots)
{
    MYASSERT(roots != NULL);
    switch (Solve_Square(coeffs, roots)){
        case NONE_SOL:
            printf("No real solutions\n\n");
            break;
        case ONE_SOL:
            printf("%s%g\n\n", "One solution: ",roots->root1);
            break;
        case TWO_SOL:
            printf("%s%g,%g\n\n", "Two solutions:",roots->root1, roots->root2);
            break;
        case INF_SOL:
            printf("%s\n\n", "Infinite number of solutions");
            break;
    }
}
/**
 * @brief Starts default quadratic equations solver from console.
 * @param Pointer to coefficients structure.
 * @param Pointer to solutions structure.
*/
void Start_Default(coefficients *coeffs, solutions *roots){
    MYASSERT(coeffs != NULL && roots != NULL);
    if (!Input_Coef(coeffs)){
        Showanswer_Square(*coeffs, roots);
    }
}

/**
 * @brief Launches different branches of programm based on checked flags.
 * @param Pointer to coefficients structure.
 * @param Pointer to solutions structure.
 * @param Pointer to flags structure.
 * @return Returns 0 if programm ended succesfully.
*/
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
        Do_Tests(0, NUMTEST);
    }
    if (list_of_flags->main){
        Start_Default(coeffs, roots);
    }
    return 0;
}

/**
 * @brief Launches different branches of programm based on checked flags.
 * @param Pointer pointer to console arguments.
 * @param Pointer to number of current argument.
 * @param Number of total arguments.
 * @param Pointer to flags structure.
*/

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

/**
 * @brief Checks if file link can exist.
 * @param Number of argument.
 * @param Total number of arguments.
 * @return 0 if file link can exist, 1 in other cases.
*/

int Check_FileLinkExist(int num_arg, int argc){
    if (num_arg >= --argc){
        printf(COLOR_RED "\nFile link does not exist.\n" COLOR_RESET);
        return 1;
    }
    return 0;
}

/**
 * @brief Starts default quadratic equations solver with input from file.
 * @param Pointer to coefficients structure.
 * @param Pointer to solutions structure.
 * @param Pointer to file link name.
 * @return Returns 0 if programm ended succesfully.
*/

int Start_Default_FromFile(coefficients *coeffs, solutions *roots, const char *file_link){
    MYASSERT(coeffs != NULL && roots != NULL && file_link != NULL);

    FILE *fp = NULL;
    if (!Input_FileLink(file_link, &fp)){
        SolveSquare_FromFile(coeffs, roots, fp, file_link);
    }
    fclose(fp);
    return 0;
}

/**
 * @brief Solves the quadratic equation with provided coefficients from file, stores the information about roots in
 solutions structure. Returns number of roots: 0 if there is no solutions, 1 - one solution, 2 - two solutions, 3 - infinite number of solutions.
 * @return The number of roots.
 * @param Pointer to coefficients.
 * @param Pointer to solutions.
 * @param Pointer to file.
 * @param Pointer to file link name.
*/

int SolveSquare_FromFile(coefficients *coeffs, solutions *roots, FILE *fp, const char *file_link){
    MYASSERT(coeffs != NULL && roots != NULL && file_link != NULL && fp != NULL);

    if (InputCoef_FromFile(coeffs, fp)){
        printf("Wrong format in " COLOR_BLUE "%s" COLOR_RESET ".\n\n", file_link);
        fclose(fp);
        return 1;
    } else if (CheckFinite(coeffs)){
        printf("Enter finite numbers in " COLOR_BLUE "%s" COLOR_RESET ".\n\n", file_link);
        fclose(fp);
        return 1;
    }
    Showanswer_Square(*coeffs, roots);
    return 0;
}

 /**
 * @brief Gets the file link.
 * @param Pointer to file link name.
 * @param Pointer pointer to file.
 * @return Return 0 if file link was assigned correctly, 1 in other cases.
*/

int Input_FileLink(const char* file_link, FILE **fp){
    MYASSERT(file_link != NULL);
    *fp = fopen(file_link, "r");

    if(*fp == NULL) {
        perror(COLOR_RED "\nError!!!\n" COLOR_RESET "Cannot open file. Check file link");
        return 1;
    }

    printf(COLOR_CYAN "\nRead from file: " COLOR_BLUE "%s" COLOR_RESET "\n", file_link);
    return 0;
}

/**
 * @brief Inputs coefficients from file.
 * @param Pointer to coefficients structure.
 * @param Pointer to input file.
 * @return Return 0 if coefficients were assigned correctly, 1 in other cases.
*/

int InputCoef_FromFile(coefficients *coeffs, FILE *fp){
    MYASSERT(coeffs != NULL && fp != NULL);
    if (fscanf(fp, "%lf%lf%lf", &(coeffs->a), &(coeffs->b), &(coeffs->c)) == 3){
        return 0;
    }
    return 1;
}

/**
 * @brief Check if coefficients are not too big or small.
 * @param Pointer to coefficients structure.
 * @return Return 0 if coefficients were assigned correctly, 1 in other cases.
*/

int CheckFinite(coefficients *coeffs){
    MYASSERT(coeffs != NULL);
    if (isfinite(coeffs->a) && isfinite(coeffs->b) && isfinite(coeffs->c)){
        return 0;
    }
    return 1;
}
