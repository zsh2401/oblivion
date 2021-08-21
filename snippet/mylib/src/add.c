#include "../my.h"

#ifdef WIN32
#include <windows.h>
#include <winuser.h>
#else
#include <stdio.h>
#endif

int my_add(int a, int b)
{
    return a + b;
}
void alert(char *msg)
{
#ifdef WIN32
    MessageBox(NULL, TEXT(msg), TEXT("HELLO"), MB_OK);
#else
    printf("%s\n", msg);
#endif
}