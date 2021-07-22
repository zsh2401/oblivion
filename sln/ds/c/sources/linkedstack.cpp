#include "../headers/linkedstack.h"
ExecStatus LStack_init(LinkedStack &result)
{
    LinkedStack stack = (LinkedStackNode *)malloc(sizeof(LinkedStackNode));
    stack->next = NULL;
    stack->data = NULL;
    result = stack;
    return RETCODE_SUCCESS;
}
ExecStatus LStack_getTop(LinkedStack stack, data_t &result)
{
    if (LStack_empty(stack))
    {
        return RETCODE_EMPTY;
    }
    result = stack->next->data;
    return RETCODE_SUCCESS;
}
ExecStatus LStack_pop(LinkedStack stack, data_t &result)
{
    if (LStack_empty(stack))
    {
        return RETCODE_EMPTY;
    }
    result = stack->next->data;
    auto popingNode = stack->next;
    stack->next = popingNode->next;
    free(popingNode);
    return RETCODE_SUCCESS;
}
ExecStatus LStack_push(LinkedStack stack, data_t data)
{
    auto pNewNode = (LinkedStackNode *)malloc(sizeof(LinkedStackNode));
    pNewNode->next = stack->next;
    pNewNode->data = data;
    stack->next = pNewNode;
    return RETCODE_SUCCESS;
}
ExecStatus LStack_lengthOf(LinkedStack stack, size_t &len)
{
    LStack_forEach(stack, [&len](data_t data, size_t index) -> bool {
        len++;
        return true;
    });
    return RETCODE_SUCCESS;
}
ExecStatus LStack_destory(LinkedStack &stack)
{
    LStack_clear(stack);
    free(stack);
    return RETCODE_SUCCESS;
}
bool LStack_empty(LinkedStack stack)
{
    return (!stack) && (!stack->next);
}
ExecStatus LStack_forEach(LinkedStack stack, ForEachHandler handler)
{
    if (LStack_empty(stack))
    {
        return RETCODE_EMPTY;
    }
    LinkedStackNode *pCurrent = stack->next;
    size_t count = 0;
    while (pCurrent && handler(pCurrent->data, count))
    {
        pCurrent = pCurrent->next;
        count++;
    }
    return RETCODE_SUCCESS;
}
ExecStatus LStack_clear(LinkedStack stack)
{
    if (LStack_empty(stack))
    {
        return RETCODE_SUCCESS;
    }
    size_t len;
    LStack_lengthOf(stack, len);
    data_t buffer;
    for (int i = 0; i < len; i++)
    {
        LStack_pop(stack, buffer);
    }
    return RETCODE_SUCCESS;
}