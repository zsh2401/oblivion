#ifndef ___LINKED_LIST
#define ___LINKED_LIST

#include <stdlib.h>
#include <functional>

#define LL_RETCODE_ERR_UNKNOWN -1
#define LL_RETCODE_ERR_EMPTY 1
#define LL_RETCODE_SUCCESS 0

#include "fx.h"
using namespace fx;
//链表节点
typedef struct ll_node
{
    ll_node *prev;
    data_t data;
    ll_node *next;
} LinkedListNode, *LinkedList;

//遍历器
typedef std::function<bool(data_t data, size_t index)> LL_ForEachHandler;

/*
初始化一个链表
T(n) = O(1)
*/
ExecStatus LL_init(LinkedList &result);

/*
获取长度
Avg T(n) = O(n)
*/
ExecStatus LL_lengthOf(LinkedList list, size_t &result);

/*
获取指定index的数据
Avg T(n) = O(n)
*/
ExecStatus LL_get(LinkedList list, int index, data_t &result);

/*
遍历数据,可终止
Avg T(n) = O(n)
*/
ExecStatus LL_forEach(LinkedList list, LL_ForEachHandler handler);

/*
在末尾添加新的数据
Avg T(n) = O(1)
*/
ExecStatus LL_append(LinkedList list, data_t data);

/*
设置某个位置的数据
Avg T(n) = O(1)
*/
ExecStatus LL_set(LinkedList list, int index, data_t data);

/*
清空链表
T(n) = O(n)
*/
ExecStatus LL_clear(LinkedList list);

/*
获取某个数据的位置
Avg T(n) = O(n)
*/
ExecStatus LL_indexOf(LinkedList list, data_t data, int &result);

/*
移除某个位置的数据
Avg T(n) = O(n) 
*/
ExecStatus LL_removeAt(LinkedList list, int index);

/*
在某个位置插入数据
Avg T(n) = O(n)
*/
ExecStatus LL_insertAt(LinkedList list, int index, data_t data);

/*
摧毁一个链表
Avg T(n) = O(n)
*/
ExecStatus LL_destory(LinkedList list);

/*
判断是否为空链表
T(n) = O(1)
*/
bool LL_empty(LinkedList list);


void LL_printInfo(LinkedList list, bool printElements = true);

#endif