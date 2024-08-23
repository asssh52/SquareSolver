#ifndef user_commands_hpp
#define user_commands_hpp

#include <stdio.h>
#include "globals.hpp"
typedef struct{
    int help;
    int test;
    int main;
} flags;
void Input_CommandInput(int argc, char *argv[]);
#endif
