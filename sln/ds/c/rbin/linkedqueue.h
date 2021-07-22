#include "fx.h"
#include "linkedlist.h"
typedef struct LinkedQueueNode
{
    LinkedQueueNode *next;
    data_t data;
} LinkedQueueNode;

typedef struct _LinkedQueue
{
    LinkedQueueNode *front;
    LinkedQueueNode *rear;
} * LinkedQueue;

ExecStatus LQueue_init(LinkedQueue &q);
ExecStatus LQueue_en(LinkedQueue q, data_t data);
ExecStatus LQueue_de(LinkedQueue q, data_t &data);
ExecStatus LQueue_clear(LinkedQueue q);
ExecStatus LQueue_lengthOf(LinkedQueue q);
bool LQueue_empty(LinkedQueue q);
ExecStatus LQueue_free(LinkedQueue &q);
