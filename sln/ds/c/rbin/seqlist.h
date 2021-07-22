#ifndef __SEQLIST_H
#define __SEQLIST_H
#include "fx.h"
#include <stdarg.h>
namespace seqlist
{
typedef struct __seqlist
{
    int *dataArray;
    size_t length;
} * SeqList;

SeqList createFrom(size_t length, int firstNum, ...);
fx::ExecStatus set(SeqList list, size_t index, int data);
int get_unsafe(SeqList list, size_t index);
fx::ExecStatus get(SeqList list, size_t index, int &result);
} // namespace seqlist
#endif