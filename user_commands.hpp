#ifndef user_commands_hpp
#define user_commands_hpp

#include <stdio.h>
typedef struct{
    int help;
    int test;
    int main;
    int error;
    int file;
    char* file_argv;
} flags;
enum num_args{
ONE_ARG = 1,
TWO_ARG,
THR_ARG
};
void Input_CommandInput(int argc, char *argv[]);
#endif
