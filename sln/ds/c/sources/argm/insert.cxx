#include "../../headers/argm.h"
namespace argm
{
void insertSort(seqlist::SeqList list)
{
    int temp, j;
    for (size_t i = 1; i < list->length; i++)
    {
        temp = seqlist::get_unsafe(list, i);
        for (j = i; j > 0 && temp < seqlist::get_unsafe(list, j - 1); j--)
        {
            if (seqlist::get_unsafe(list, j) < temp)
            {
                seqlist::set(list, j, seqlist::get_unsafe(list, j - 1));
            }
        }
        seqlist::set(list, j, temp);
    }
}
} // namespace argm