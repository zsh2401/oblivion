#ifndef __CIRCQUEUE
#define __CIRCQUEUE
#include "fx.h"
using namespace fx;

namespace cqueue
{
#define __CQUEUE_ELE_CAPCITY 6
#define MOD %
#define __CQUEUE_SPACE_SIZE (__CQUEUE_ELE_CAPCITY+1)

typedef struct queue
{
    size_t front;
    size_t rear;
    data_t *array;
} * CQueue;

//f(rear,front,mqs) = (r - f + mqs ) % mqs
size_t CQueue_sizeof(CQueue q);
//rear = front = 0;
ExecStatus CQueue_init(CQueue &q);
//(rear+1)%MaxQSize == front
ExecStatus CQueue_full(CQueue q);
//rear==front
bool CQueue_empty(CQueue q);
//rear = (rear + 1) % MaxQSize
ExecStatus CQueue_en(CQueue q, data_t data);
//rear = (front + 1) % MaxQSize
ExecStatus CQueue_de(CQueue q, data_t &data);
ExecStatus CQueue_clear(CQueue q);
ExecStatus CQueue_destory(CQueue &q);

} // namespace cqueue
#endif