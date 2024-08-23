#ifndef user_commands_hpp
#define user_commands_hpp

#include <stdio.h>
typedef struct{
    int help;
    int test;
    int main;
    int error;
    int file;
} flags;
void Input_CommandInput(int argc, char *argv[]);
#endif
