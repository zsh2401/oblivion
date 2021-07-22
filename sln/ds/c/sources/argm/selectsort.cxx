#include "../../headers/argm.h"
namespace argm
{
size_t selectSort_findIndexOfMinBetween(seqlist::SeqList list, size_t start, size_t end)
{
    size_t result = 0;
    int lastNumber, currentNumber;
    seqlist::get(list, start, lastNumber);
    for (size_t i = start + 1; i < list->length; i++)
    {
        seqlist::get(list, i, currentNumber);
        if (currentNumber < lastNumber)
        {
            result = i;
        }
        lastNumber = currentNumber;
    }
    // std::cout<< "min is " << currentNumber << std::endl;
    return result;
}
void selectSort(seqlist::SeqList list)
{
    size_t start, min, end;
    int replacedBuffer, minBuffer;
    end = list->length - 1;
    for (start = 0; start < end; start++)
    {
        //find the index of min number in list
        min = selectSort_findIndexOfMinBetween(list, start, end);
        //exchange min number with first number in working space
        seqlist::get(list, start, replacedBuffer);
        seqlist::get(list, min, minBuffer);
        seqlist::set(list, min, replacedBuffer);
        seqlist::set(list, start, minBuffer);

        argm::printEachOf(list);
    }
}
} // namespace argm
