#include "../headers/linkedqueue.h"
#include <stdlib.h>
#include "functional"
typedef std::function<bool(LinkedQueueNode *node)> LinkedQueueForEachNodeHandler;
ExecStatus LQueue_init(LinkedQueue &q)
{
    q = (LinkedQueue)malloc(sizeof(_LinkedQueue));
    q->front = q->rear = (LinkedQueueNode *)malloc(sizeof(LinkedQueueNode));
    q->rear->next = NULL;
    return RETCODE_SUCCESS;
}
ExecStatus LQueue_en(LinkedQueue q, data_t data)
{
    if (!q)
    {
        return RETCODE_EMPTY;
    }
    auto pNewNode = (LinkedQueueNode *)malloc(sizeof(LinkedQueueNode));
    pNewNode->data = data;
    pNewNode->next = NULL;

    q->rear->next = pNewNode;
    q->rear = pNewNode;
    return RETCODE_SUCCESS;
}
ExecStatus LQueue_internal_forEachNode(LinkedQueue q, LinkedQueueForEachNodeHandler handler)
{
    LinkedQueueNode *pCurrent = q->rear;
    while (pCurrent->next)
    {
        pCurrent = pCurrent->next;
        if (!handler(pCurrent))
        {
            break;
        }
    }
    return RETCODE_SUCCESS;
}

ExecStatus LQueue_de(LinkedQueue q, data_t &data)
{
    if (LQueue_empty(q))
    {
        data = NULL;
        return RETCODE_EMPTY;
    }
    auto end = q->front->next;
    data = end->data;
    q->front->next = end->next;
    if (q->rear == end)
    {
        q->rear = q->front;
    }
    free(end);
    return RETCODE_SUCCESS;
}

ExecStatus LQueue_clear(LinkedQueue q)
{
    return RETCODE_SUCCESS;
}
ExecStatus LQueue_lengthOf(LinkedQueue q)
{
    return RETCODE_SUCCESS;
}
bool LQueue_empty(LinkedQueue q)
{
    bool has = q && q->front->next;
    return !has;
}
ExecStatus LQueue_free(LinkedQueue &q)
{
    return RETCODE_SUCCESS;
}