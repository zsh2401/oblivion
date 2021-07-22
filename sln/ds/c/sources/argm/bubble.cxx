#include "../../headers/argm.h"
namespace argm
{
void bubbleSortSingle(seqlist::SeqList seq)
{
    int left, right;
    for (int j = 0; j < seq->length - 1; j++)
    {
        seqlist::get(seq, j, left);
        seqlist::get(seq, j + 1, right);
        if (left > right)
        {
            seqlist::set(seq, j, right);
            seqlist::set(seq, j + 1, left);
        }
    }
}
void bubbleSort(seqlist::SeqList seq)
{
    bool hasChanged = true;
    int left, right;
    for (int i = 0; i < seq->length - 1 && hasChanged; i++)
    {
        hasChanged = false;
        for (int j = 0; j < seq->length - 1; j++)
        {
            seqlist::get(seq, j, left);
            seqlist::get(seq, j + 1, right);
            if (left > right)
            {
                hasChanged = true;
                seqlist::set(seq, j, right);
                seqlist::set(seq, j + 1, left);
            }
        }
    }
}
} // namespace argm