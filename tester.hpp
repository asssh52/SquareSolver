#ifndef tester_hpp
#define tester_hpp

typedef struct{
    double coefficients[3];
    double solutions[2];
    int nroots;
} equation;

#define COLOR_GREEN        "\x1b[32m"
#define COLOR_RESET         "\x1b[0m"
#define COLOR_RED          "\x1b[31m"
#define COLOR_BLUE         "\x1b[34m"
#define COLOR_CYAN         "\x1b[36m"

int Test_Square(int num_test, equation *keys);
void Do_Tests(int start_test, int end_test, equation *keys);

#endif /* tester_hpp */
