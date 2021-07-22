/*
一个双向循环链表
Dec 3,2019
v0.1
by zsh2401 <zsh2401@163.com>
*/

#include "../headers/linkedlist.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

/*
初始化一个链表
T(n) = O(1)
*/
ExecStatus LL_init(LinkedList &result)
{
    LinkedListNode *head = (LinkedListNode *)malloc(sizeof(LinkedListNode));
    (*head).next = head;
    (*head).prev = head;
    result = head;
    return LL_RETCODE_SUCCESS;
}
/*
!!不公开的方法!!
从关系和数据上移除一个节点
*/
void LL_removeNode_unsafe(LinkedListNode *pNode)
{
    pNode->prev->next = pNode->next;
    pNode->next->prev = pNode->prev;

    free(pNode);
}

typedef std::function<bool(LinkedListNode *pNode, size_t index)> LL_ForEachNodeHandler;
/*
!!不公开的方法!!
遍历每一个节点
Avg T(n) = O(n)
*/
void LL_forEachNode_unsafe(LinkedList list, LL_ForEachNodeHandler handler)
{
    LinkedListNode *pHead = list;
    LinkedListNode *pCurrent = pHead->next;
    int index = 0;
    while (pCurrent != pHead)
    {
        if (!handler(pCurrent, index))
        {
            break;
        }
        pCurrent = pCurrent->next;
        index++;
    }
}
/*
获取长度
Avg T(n) = O(n)
*/
ExecStatus LL_lengthOf(LinkedList list, size_t &result)
{
    int count = 0;
    ExecStatus status = LL_forEach(list, [&count](data_t data, size_t index) {
        count++;
        return true;
    });
    result = count;
    return status;
}
/*
遍历数据,可终止
Avg T(n) = O(n)
*/
ExecStatus LL_forEach(LinkedList list, LL_ForEachHandler handler)
{
    if (LL_empty(list))
    {
        return LL_RETCODE_ERR_EMPTY;
    }
    LL_forEachNode_unsafe(list, [handler](LinkedListNode *pNode, size_t index) -> bool {
        return handler(pNode->data, index);
    });
    return LL_RETCODE_SUCCESS;
}
/*
!!不公开的方法!!
获取节点指针
Avg T(n) = O(n)
*/
LinkedListNode *LL_getNode_unsafe(LinkedList list, int index)
{
    LinkedListNode *pNode = NULL;
    LL_forEachNode_unsafe(list, [index, &pNode](LinkedListNode *_pNode, size_t _index) -> bool {
        if (index == _index)
        {
            pNode = _pNode;
            return false;
        }
        else
        {
            return true;
        }
    });
    return pNode;
}
/*
获取指定index的数据
Avg T(n) = O(n)
*/
ExecStatus LL_get(LinkedList list, int index, data_t &result)
{
    if (LL_empty(list))
    {
        return LL_RETCODE_ERR_EMPTY;
    }
    result = LL_getNode_unsafe(list, index)->data;
    return LL_RETCODE_SUCCESS;
}
/*
在末尾添加新的数据
Avg T(n) = O(1)
*/
ExecStatus LL_append(LinkedList list, data_t data)
{
    LinkedListNode *pNewNode = (LinkedListNode *)malloc(sizeof(LinkedListNode));
    auto last = list->prev;
    last->next = pNewNode;
    list->prev = pNewNode;

    pNewNode->prev = last;
    pNewNode->next = list;
    pNewNode->data = data;
    return LL_RETCODE_SUCCESS;
}
/*
!!不公开的方法!!
设置某个位置的节点
Avg T(n) = O(n)
*/
void LL_setNode_unsafe(LinkedList list, int index, LinkedListNode *pNewNode)
{
    LinkedListNode *target = LL_getNode_unsafe(list, index);
    if (target == NULL)
    {
        return;
    }
    LinkedListNode *prev = target->prev;
    LinkedListNode *next = target->next;

    prev->next = pNewNode;
    next->prev = pNewNode;

    pNewNode->prev = prev;
    pNewNode->next = next;

    free(target);
}
/*
!!不公开的方法!!
设置某个位置的数据
Avg T(n) = O(n)
*/
ExecStatus LL_set(LinkedList list, int index, data_t data)
{
    if (LL_empty(list))
    {
        return LL_RETCODE_ERR_EMPTY;
    }
    LinkedListNode *pNewNode = (LinkedListNode *)malloc(sizeof(LinkedListNode));
    pNewNode->data = data;
    LL_setNode_unsafe(list, index, pNewNode);
    return LL_RETCODE_SUCCESS;
}
/*
判断是否为空链表
T(n) = O(1)
*/
bool LL_empty(LinkedList list)
{
    return list == list->next;
}
/*
清空链表
T(n) = O(n)
*/
ExecStatus LL_clear(LinkedList list)
{
    if (LL_empty(list))
    {
        return LL_RETCODE_SUCCESS;
    }
    LL_forEachNode_unsafe(list, [list](LinkedListNode *node, size_t index) -> bool {
        LL_removeNode_unsafe(node);
        return true;
    });
    return LL_RETCODE_SUCCESS;
}
/*
获取某个数据的位置
Avg T(n) = O(n)
*/
ExecStatus LL_indexOf(LinkedList list, data_t data, int &result)
{
    int index = -1;
    ExecStatus status = LL_forEach(list, [data, &index](data_t _data, size_t _index) -> bool {
        if (_data == data)
        {
            index = _index;
            return false;
        }
        else
        {
            return true;
        }
    });
    result = index;
    return status;
}
/*
移除某个位置的数据
Avg T(n) = O(n) 
*/
ExecStatus LL_removeAt(LinkedList list, int index)
{
    if (LL_empty(list))
    {
        return LL_RETCODE_ERR_EMPTY;
    }

    auto node = LL_getNode_unsafe(list, index);
    if (node == NULL)
    {
        return LL_RETCODE_ERR_UNKNOWN;
    }
    LL_removeNode_unsafe(node);

    return LL_RETCODE_SUCCESS;
}
/*
在某个位置插入数据
Avg T(n) = O(n)
*/
ExecStatus LL_insertAt(LinkedList list, int index, data_t data)
{
    if (LL_empty(list))
    {
        return LL_RETCODE_ERR_EMPTY;
    }
    auto targetNode = LL_getNode_unsafe(list, index);
    if (targetNode == NULL)
    {
        return LL_RETCODE_ERR_UNKNOWN;
    }
    auto newNode = (LinkedListNode *)malloc(sizeof(LinkedListNode));

    newNode->prev = targetNode->prev;
    newNode->next = targetNode;
    newNode->data = data;

    targetNode->prev->next = newNode;
    targetNode->prev = newNode;

    return LL_RETCODE_SUCCESS;
}
/*
摧毁一个链表
Avg T(n) = O(n)
*/
ExecStatus LL_destory(LinkedList list)
{
    LL_clear(list);
    free(list);
    return LL_RETCODE_SUCCESS;
}

void LL_printInfo(LinkedList list, bool printElements)
{
    std::cout << "head address: [" << list << "]" << endl;
    size_t len;
    LL_lengthOf(list, len);
    std::cout << "length: " << len << endl;
    if (printElements)
    {
        LL_forEach(list, [](data_t data, size_t index) -> bool {
            std::cout << "[" << index << "]: " << data << endl;
            return true;
        });
    }
}
