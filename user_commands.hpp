#ifndef user_commands_hpp
#define user_commands_hpp

#include <stdio.h>
#include "tester.hpp"
typedef struct{
    int list_flag[3];
} flags;
int Start_Default_File(double *input, double *roots, char *file_link);
char *GetConfig_InputFile();
void Command_Output(equation *keys, double *input, double *roots, flags *list_of_flags);
void Check_Flag(char *flag, flags *list_of_flags);
void Input_CommandInput(int argc, char *argv[], equation *keys);
void Start_Default(double *input, double *roots);
void Start_Help();
void Start_CommandError();
void Showanswer_Square(double input[], double roots[]);
int Input_Coef(double input[]);
#endif
