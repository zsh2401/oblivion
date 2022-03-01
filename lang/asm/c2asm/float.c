#include <stdio.h>
double sum(double a, double b)
{
    return a * b;
}
int main(void)
{
    printf("%lf", sum(1.5, 1.5));
    return 0;
}