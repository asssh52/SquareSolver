#ifndef tester_hpp
#define tester_hpp

typedef struct{
    double coefficients[3];
    double solutions[2];
    int nroots;
} equation;

int Test_Square(int num_test, equation *keys);
void Do_Tests(int start_test, int end_test, equation *keys);
double Round_To(double number, int digits);

#endif /* tester_hpp */
