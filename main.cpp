#include <stdio.h>
#include <stdlib.h>
#include "sqrt_solver.hpp"
#include "tester.hpp"
#include "user_commands.hpp"

equation keys[10] = { // База данных для проверки программы
    {{  1,  2, 3}, {        0,        0}, NONE_SOL},
    {{  1, -4, 3}, {        1,        3}, TWO_SOL },
    {{100, -4,-3}, {-0.154356, 0.194356}, TWO_SOL },
    {{  1,  0,-9}, {       -3,       +3}, TWO_SOL },
    {{  0,  2, 3}, {     -1.5,        0}, ONE_SOL },
    {{  0,  2, 0}, {        0,        0}, ONE_SOL },
    {{  0,  0, 3}, {        0,        0}, NONE_SOL},
    {{  7, -9, 2}, { 0.285714,        1}, TWO_SOL },
    {{  0,  0, 0}, {        0,        0}, INF_SOL },
    {{ -4,  9,-3}, {  0.40693,  1.84307}, TWO_SOL }
};

int main(void){
    Choose_Path(keys);
    return 0;
}
