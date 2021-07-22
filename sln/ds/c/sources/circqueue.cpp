#include "../headers/circqueue.h"
#include <stdlib.h>
using namespace cqueue;
namespace cqueue
{
ExecStatus CQueue_init(CQueue &q)
{
    q = (CQueue)malloc(sizeof(CQueue));
    q->array = (data_t *)malloc(sizeof(data_t) * __CQUEUE_SPACE_SIZE);
    q->front = q->rear = 0;
    return RETCODE_SUCCESS;
}
size_t CQueue_sizeof(CQueue q)
{
    return (q->rear - q->front + __CQUEUE_SPACE_SIZE) % __CQUEUE_SPACE_SIZE;
}

ExecStatus CQueue_full(CQueue q)
{
    return (q->rear + 1) % __CQUEUE_SPACE_SIZE == q->front;
}
bool CQueue_empty(CQueue q)
{
    return q->front == q->rear;
}
ExecStatus CQueue_en(CQueue q, data_t data)
{
    if (CQueue_full(q))
    {
        return RETCODE_OVERFLOW;
    }
    size_t index = (q->rear % __CQUEUE_SPACE_SIZE);
    q->array[index] = data;
    q->rear = (q->rear + 1) % __CQUEUE_SPACE_SIZE;
    return RETCODE_SUCCESS;
}

ExecStatus CQueue_de(CQueue q, data_t &data)
{
    data = q->array[q->front];
    q->front = (q->front + 1 % __CQUEUE_SPACE_SIZE);
    return RETCODE_SUCCESS;
}
ExecStatus CQueue_clear(CQueue q)
{
    data_t buffer;
    while (!CQueue_empty(q))
    {
        CQueue_de(q, buffer);
    }
    return RETCODE_SUCCESS;
}

ExecStatus CQueue_destory(CQueue &q)
{
    CQueue_clear(q);
    free(q);
    q = NULL;
    return RETCODE_SUCCESS;
}
} // namespace cqueue