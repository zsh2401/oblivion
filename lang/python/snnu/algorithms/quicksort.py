def quick_sort(a: list[int]):
    def swap(aIndex: int, bIndex: int):
        tmp = a[aIndex]
        a[aIndex] = a[bIndex]
        a[bIndex] = tmp

    def p(low: int, high: int):
        ol = low
        oh = high
        if low is high or low > high:
            return
        pivot = a[low]
        while low < high:

            while low < high and pivot <= a[high]:
                high -= 1
            a[low] = a[high]

            while low < high and a[low] <= pivot:
                low += 1
            a[high] = a[low]

        a[low] = pivot
        
        # print(f"range {ol}-{low} {low + 1}-{oh}")
        p(ol, low)
   
        p(low + 1, oh)

    p(0, len(a) - 1)
