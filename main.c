
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXLINE 1000
double atof(const char *);
int sqrtsolver(double a, double b, double c, double s[])
{
    double d, base;
    if (a == 0){
        return -1;
    }
    d = b * b - 4 * a * c; /* discrim*/
    base = -1 * b / (2 * a); /* base */
    if (d < 0){
        s[2] = -1;
        return 0;
    }
    else if (d == 0){
        s[0] = base;
        return 1;
    } else {
        s[0] = base + sqrt(d) / (2 * a);
        s[1] = base - sqrt(d) / (2 * a);
        s[2] = 0;
        return 2;
    }
}

int main() {
    double a, b, c, s[2];
    char *kek;
    size_t maxl = MAXLINE;
    kek = (char *)malloc(maxl * sizeof(char));
    
    scanf("%lf%lf%lf", &a, &b, &c);
    
    switch (sqrtsolver(a, b, c, s)) {
        case -1:
            printf("это не квадратное уравнение\n");
            break;
        case 0:
            printf("нет действительных решений\n");
            break;
        case 1:
            printf("%s%f\n", "одно решение: ",s[0]);
            break;
        case 2:
            printf("%s%f,%f\n", "два решения:",s[0], s[1]);
            break;
    }
    return 0;
}
