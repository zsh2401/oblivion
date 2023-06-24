#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
time_t seq()
{
    size_t len = 2 << 24;
    time_t start = time(NULL);
    int64_t *data = malloc(len * sizeof(int64_t));
    // printf("%lu",len);
    for (size_t i = 0; i < len; i++)
    {
        // printf("%lu\n",i);
        data[i] = data[i] + 2;
    }
    time_t end = time(NULL);
    return end - start;
}

time_t q()
{
    size_t len = 2 << 24;
    time_t start = time(NULL);
    int64_t *data = malloc(len * sizeof(int64_t));
        size_t N = sizeof(int64_t);
    for (size_t i = 0; i < len; i++)
    {
        // printf("%lu\n",i);
        size_t n = (i % 64);
        size_t b = (1 << (N - n)) | (1 >> n);
        b %= len;
        data[i] = data[b];
    }
    time_t end = time(NULL);
    return end - start;
}
int main(void)
{
    printf("Seq: %lu\n", seq());
    printf("Ran: %lu\n", q());
    return 0;
}
