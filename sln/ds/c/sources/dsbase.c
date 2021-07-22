#include <stdlib.h>
#include <stdio.h>
#include "../headers/dsbase.h"
void *DS_malloc(DS_size_t size)
{
    return malloc(size);
}

void DS_free(void *ptr)
{
    free(ptr);
}
char *DS_Version()
{
    return "0.0.1-red";
}
void DS_EasterEgg()
{
    printf("Easter Egg!");
}
void DS_printf(const char* const format,...){
    printf(format);
}