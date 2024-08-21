#ifndef tester_hpp
#define tester_hpp

typedef struct{
    double coefficients[3];
    double solutions[2];
    int nroots;
} equasion;

int Test_Square(int num_test, equasion keys[0]);
void Do_Tests(int start_test, int end_test, equasion *keys);
double Round_To(double number, int digits);

#endif /* tester_hpp */
