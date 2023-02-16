#include <stdarg.h>
int sum(int count, ...)
{
    int r = 0;
    va_list ap;
    va_start(ap, count);
    int i = count;
    while (i-- > 0)
    {
        r += va_arg(ap, int);
    }
    va_end(ap);
    return r;
}