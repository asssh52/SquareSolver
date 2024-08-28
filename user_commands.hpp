#ifndef user_commands_hpp
#define user_commands_hpp
#include "colors.hpp"
#include "tester.hpp"
#define MYASSERT(x) if (!(x)) { printf(COLOR_RED "\nThe programm has been aborted.\n"\
                                               "Line %d of file %s, function %s.\n\n" COLOR_RESET,\
                                            __LINE__, __FILE__, __func__); abort();}
#include <stdio.h>

typedef struct{
    int help;
    int test;
    int main;
    int error;
    int file;
    const char* file_argv;
} flags;

enum num_args{
ONE_ARG = 1,
TWO_ARG,
THR_ARG
};

/*********************************************************************
 * @file  user_commands.cpp
 *
 * @brief User commands and flags
 *********************************************************************/
 
void Start_Default(coefficients *coeffs, solutions *roots);
void Check_Flag(const char *argv[], int *num_arg, int argc, flags *list_of_flags);
int Command_Output(coefficients *coeffs, solutions *roots, flags *list_of_flags);
#endif
