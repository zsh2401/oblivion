#ifndef __SEQLIST_H
#define __SEQLIST_H
#include "dsbase.h"
#define MAX_SIZE 100
typedef struct
{
    DS_data_t *data;
    DS_size_t last;
    DS_size_t maxsize;
} * DS_SeqList;
DS_ExecStatus DS_SeqList_New(DS_SeqList* targetRecv,DS_size_t maxSize);
DS_ExecStatus DS_SeqList_Get(DS_SeqList list, DS_size_t index, DS_data_t *recv);
DS_ExecStatus DS_SeqList_Set(DS_SeqList list, DS_size_t index, DS_data_t data);
DS_ExecStatus DS_SeqList_MaxSize(DS_SeqList list, DS_size_t *recv);
DS_ExecStatus DS_SeqList_Insert(DS_SeqList list,DS_size_t position,DS_data_t data);
DS_ExecStatus DS_SeqList_Remove(DS_SeqList list,DS_size_t position);
DS_ExecStatus DS_SeqList_Add(DS_SeqList list,DS_data_t data);
#endif