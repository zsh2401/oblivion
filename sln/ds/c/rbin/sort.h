#ifndef __SORT_H
#define __SORT_H
#include "fx.h"
#include <stdbool.h>
void bubbleSort(data_t* list,size_t length,BOOLEAN zeroIsIdle);
void quickSort();
void insertSort();
void binInsertSort();
void shellSort();
void selectSort();
void heapSort();
void gbSort();
#endif
