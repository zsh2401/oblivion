#include <stdio.h>
int sum(int a, int b, int c, int d, int e, int f, int g, int h)
{
    return a + b + c + d + e + f + g + h;
}
int fac(int x)
{
    if (x == 0)
    {
        return 1;
    }
    return x * fac(x - 1);
}
int main(void)
{
    printf("%d", sum(1, 2, 3, 4, 5, 6, 7, 8));
    return 0;
}