#ifndef user_commands_hpp
#define user_commands_hpp
#include "colors.hpp"
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
void Input_CommandInput(int argc, const char *argv[]);
void myassert(int statement);
#endif
