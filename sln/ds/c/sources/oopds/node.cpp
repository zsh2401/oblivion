#include "../../headers/oopds.h"
template <typename T>
oopds::SingleNode<T>::SingleNode(T data, SingleNode *next)
{
    this->data = data;
    this->next = next;
}
template <typename T>
oopds::DoubleNode<T>::DoubleNode(T data, DoubleNode *prev, DoubleNode *next)
{
    this->prev = prev;
}