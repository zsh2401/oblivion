/*
Version: 1.0
Author: Seymour Zhang <zsh2401@163.com> ->> https://zsh2401.top
Date: July 9,2020
*/

#ifndef __DS_BASE_H
#define __DS_BASE_H

typedef void* DS_data_t;
typedef unsigned int DS_size_t;
typedef int DS_ExecStatus;

//DS_METHOD(DS_PREFIXfind)(int x){}  >> DS_ExecStatus DS_find(int x);
#define DS_PREFIX DS_
#define DS_METHOD(N) DS_ExecStatus N


//Define error codes.
#define DS_FALSE 0 
#define DS_TRUE !DS_FALSE
#define DS_STATUS_SUCCESS 0
#define DS_STATUS_EMPTY 1
#define DS_STATUS_FULL 2
#define DS_STATUS_TARGET_NULL 3
#define DS_STATUS_UNKNOWN_ERROR 4
#define DS_STATUS_OS_ERROR 5
#define DS_STATUS_NEED_HANDLE_MORE_EXCEPTION_MESSAGE 6
#define DS_STATUS_KEY_NOT_FOUND 7
#define DS_STATUS_TARGET_NOT_FOUND 8
#define DS_STATUS_MEMORY_ERROR 9
#define DS_STATUS_PATTERN_FAILED 10

/*
Get an cotinuely memory space.
*/
void* DS_malloc(DS_size_t size);

/*
Free memory.
*/
void DS_free(void* ptr);

/*
This is the classic printf method which blocked difference between operating systems.
*/
void DS_printf(const char* const format,...);

/*
Get this library's version information.
*/
char* DS_Version();

/*
It's safe and won't break or destory anything.
But it's useless too.
*/
void DS_EasterEgg();

#endif
