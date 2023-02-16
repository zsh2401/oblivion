#include <stdlib.h>
#include <stdio.h>
#define GB (1024l * 1024 * 1024)
int main(void)
{
	const size_t size = 15 * GB; // 3GB
	char *ptr = (char*)malloc(size);
	for(size_t i=0;i<size;i++){
		*ptr++ = 1;
	}
	printf("%ld bytes memory has been allocated to this process", size);
	getchar();
	return 0;
}
