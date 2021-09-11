#include <stdio.h>
#include <stdlib.h>

typedef unsigned int length_t;
typedef unsigned element_t;
typedef struct
{
    length_t m;
    length_t n;
    length_t l;
    element_t element;
} * Martix;

Martix *readMartix();

int *calculateGrayTable(Martix *m);

int main(int argc, char **argv)
{
    Martix *m = readMartix();
    int *result = calculateGrayTable(m);
    for (int i = 0; i < m->l; i++)
    {
        printf("%d", result[i]);
    }
    printf("\n");
    return 0;
}