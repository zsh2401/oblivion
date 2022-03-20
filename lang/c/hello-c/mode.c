#include <stdio.h>
#include <stdlib.h>
int *get20num()
{
    int *nums = (int *)malloc(sizeof(int) * 20);
    nums[0] = 1;
    nums[1] = 1;
    nums[2] = 3;
    nums[3] = 3;
    nums[4] = 4;
    nums[5] = 3;
    nums[6] = 4;
    nums[7] = 3;
    nums[8] = 35;
    nums[9] = 40;
    nums[10] = 40;
    nums[11] = 40;
    nums[12] = 40;
    nums[13] = 2;
    nums[14] = 5;
    nums[15] = 9;
    nums[16] = 0;
    nums[17] = 0;
    nums[18] = 0;
    nums[19] = 0;
    return nums;
}
int main(void)
{
    int *flags = (int *)malloc(sizeof(int) * 40);
    int *nums = get20num();
    for (int i = 0; i < 20; i++)
    {
        int current = nums[i];
        flags[i * 2] = i;
        flags[i * 2 + 1] = i;
        int j;
        for (j = 1; j < 19; j++)
        {
            if (nums[i + j] != current)
            {
                break;
            }
        }
        if (j == 3)
        {
            printf("%d to %d\n", i - 1, i + j - 1);
        }
    }

    return 0;
}