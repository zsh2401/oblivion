#ifndef __SORT_SEARCH_H
#define __SORT_SEARCH_H
#include "fx.h"
#include "seqlist.h"
namespace argm
{
void printEachOf(seqlist::SeqList list);
/*
冒泡排序
平均时间:O(n²) 
最坏时间:O(n²) 
附加空间:O(1) 
稳定性: 稳定
*/
void bubbleSort(seqlist::SeqList list);
/*
进行一趟冒泡排序
*/
void bubbleSortSingle(seqlist::SeqList list);
/*
简单选择排序
平均时间复杂度 O(n)
空间复杂度 O(1)
*/
void selectSort(seqlist::SeqList list);
/*
快速排序
平均时间复杂度: O(n * log2n)
最坏所需时间: O(n)
附加空间: O(logn)
稳定性: 不稳定
*/
void quickSort(seqlist::SeqList list);
/*
直接插入排序
平均时间复杂度: O(n²)
最坏所需时间: O(n²)
附加空间: O(1)
稳定性: 稳定
*/
void insertSort(seqlist::SeqList list);
/*
堆排序
平均时间复杂度: O(nlog2n)
最坏所需时间: O(nlog2n)
附加空间: O(n)
稳定性: 不稳定

未实现
*/
void heapSort(seqlist::SeqList list);
/*
希尔排序
平均时间复杂度: O(n的1.3次方)
最坏所需时间: /
附加空间: O(1)
稳定性: 不稳定

未实现
*/
void shellSort(seqlist::SeqList list);
} // namespace argm
#endif
