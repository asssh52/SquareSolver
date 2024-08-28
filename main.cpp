#include <stdio.h>
#include "tester.hpp"
#include "user_commands.hpp"

int main(int argc, const char *argv[]){
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
    
    return 0;
}
