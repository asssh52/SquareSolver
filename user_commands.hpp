#ifndef user_commands_hpp
#define user_commands_hpp

#include <stdio.h>
#include "tester.hpp"

void Input_CommandInput(int argc, char *argv[], equation *keys);
void Start_Default(double *input, double *roots);
void Start_Help();
void Start_CommandError();
void Showanswer_Square(double input[], double roots[]);
int Input_coef(double input[]);
void Choose_Path(equation *keys);
int Ask_User_Test();

#endif
