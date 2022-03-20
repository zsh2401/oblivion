#include <stdio.h>
#include <sys/types.h> /*提供类型pid_t,size_t的定义*/
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
int next()
{
	int fd = open("/dev/random", O_RDONLY);
	int rnum;
	read(fd, &rnum, 4);
	close(fd);
	if (rnum < 0)
	{
		rnum = 0 - rnum;
	}
	rnum %= 98;
	rnum++;
	return rnum;
}
int main(void)
{
	int* record = (int*)malloc(4 * 99);
	for (int i = 0; i < 200; i++)
	{
		int rnum = next();
		record[rnum - 1]++;
	}

	for (int i = 0; i < 99; i++)
	{
		if(i % 5 == 0){
			printf("\n");
		}
		printf("[%d]:\t%d\t", i + 1, record[i]);
	}
	return 0;
}
