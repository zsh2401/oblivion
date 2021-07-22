#include "../../headers/argm.h"
namespace argm
{
void printEachOf(seqlist::SeqList seqList)
{
    int buffer;
    std::cout << "[";
    for (int i = 0; i < seqList->length; i++)
    {
        seqlist::get(seqList, i, buffer);
        std::cout << buffer;
        if (i < seqList->length - 1)
        {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;
}
}