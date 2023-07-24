#include <stdio.h>
#include <math.h>

double f(double x) {
    return x - 1 - cos(x);
}

double df(double x) {
    return 1 + sin(x);
}

int main() 
{
    double x0 = 1.0;
    double x1;
    //int iter = 0;
    while (1) {
        x1 = x0 - f(x0) / df(x0);
        if (fabs(x1 - x0) < 0.00001) {
            break;
        }
        x0 = x1;
        //iter++;
    }
    printf("root=%lf\n", x1);
    //printf("Total iterations: %d\n", iter);
    return 0;
}
