#include <stdlib.h>
#include <stdio.h>
void test1()
{
    void *p = malloc(4);
    printf("%p\n", p);
    char *a = (char *)p;
    a[3] = 1;
    int *x = (int *)p;
    // printf("%p\n", p);
    printf("%d", *x);
}
void test2()
{
    int *p = (int *)malloc(sizeof(int) * 10);
    char *c = (char *)p;
    // c[1];
    // p[1];
}

typedef struct B
{
    int x;
    int y;
} A;

void test3()
{
    // printf("%ld", sizeof(A));
    char *sigma = (char *)malloc(100);
    sigma[0] = 10;
    sigma[4] = 10;
    A *a = (A *)sigma;
    printf("%d-%d", a->x, a->y);
    sigma++;
}
int main(void)
{
    test3();
    return 0;
}