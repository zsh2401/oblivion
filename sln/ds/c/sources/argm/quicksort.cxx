#include "../../headers/argm.h"
namespace argm
{
#define LEFT true
#define RIGHT false
typedef bool POSTION;
void quickSort(seqlist::SeqList list)
{
    int low = 0;
    int high = list->length - 1;
    int lowBuffer, highBuffer;
    POSTION basePosition = LEFT;
    while (low < high)
    {
        seqlist::get(list, low, lowBuffer);
        seqlist::get(list, high, highBuffer);
        if (lowBuffer > highBuffer)
        {
            seqlist::set(list, low, highBuffer);
            seqlist::set(list, high, lowBuffer);
            basePosition = !basePosition;
        }
        if (basePosition == LEFT)
        {
            high--;
        }
        else
        {
            low++;
        }
    }
}
} // namespace argm