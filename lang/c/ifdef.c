#include <stdio.h>
#include <stdarg.h>
#define ONE 1
#define TWO (ONE + ONE)
#ifdef WINDOWS
#include <windows.h>
#else
#include <unistd.h>
#endif

// f = 2x
int f(int x)
{
    return x * TWO;
}
int main(int argc, char **argv, char **env)
{
    int y = f(2);
    printf("%d", y);
    return 0;
}