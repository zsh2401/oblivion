#include "fx.h"
#include "functional"
using namespace std;
using namespace fx;
typedef struct LinkedStackNode
{
    data_t data;
    LinkedStackNode *next;
} LinkedStackNode, *LinkedStack;

typedef std::function<bool(data_t data, size_t index)> ForEachHandler;
ExecStatus LStack_init(LinkedStack &result);
ExecStatus LStack_getTop(LinkedStack stack, data_t &result);
ExecStatus LStack_pop(LinkedStack stack, data_t &result);
ExecStatus LStack_push(LinkedStack stack, data_t data);
ExecStatus LStack_lengthOf(LinkedStack stack, size_t &len);
ExecStatus LStack_destory(LinkedStack &stack);
bool LStack_empty(LinkedStack stack);
ExecStatus LStack_forEach(LinkedStack stack, ForEachHandler handler);
ExecStatus LStack_clear(LinkedStack stack);