#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
char *mem;
// 8GB
size_t len = 8 * 1024 * 1024 * 1024;
void allocate()
{
    printf("Allocating memory.");
    mem = malloc(sizeof(char) * len);
}
void *random_access(void *nothing)
{
    while (1)
    {
        size_t index = rand() % len;
        mem[index] = (char)rand();
    }
}
void *cpu_task(void *nothing)
{
    while (1)
    {
    }
    return NULL;
}
int main()
{
    
    allocate();
    pthread_t threads[9];
    printf("cr %d",threads[0]);
    // pthread_t amem_thread;
    int cr = pthread_create(threads, NULL, random_access, NULL);
    // printf("cr %d",threads[0]);
    for (size_t i = 0; i < 8; i++)
    {
        // pthread_t thread;
        pthread_create(&threads[i + 1], NULL, cpu_task, NULL);
    }
    // for (size_t i = 0; i < 9; i++) {
    pthread_join(threads[0], NULL);
    // }
    return 0;
}