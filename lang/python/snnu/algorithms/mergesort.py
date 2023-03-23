from math import ceil


# 归并排序
def merge_sort(a: list[int]):
    merge_sort_(a, 0, len(a) - 1)

# 归并排序的内部
def merge_sort_(a: list[int], low: int, high: int):
    # 仍然在合法范围内
    if low < high:
        mid = (low + high) // 2
        # 先把左边合并
        merge_sort_(a, low, mid)
        # 再把右边合并
        merge_sort_(a, mid + 1, high)
        # 将所有结果合并
        merge(a, low, mid, high)

# 将一个区域内的数据合并
def merge(a: list[int], low: int, mid: int, high: int):

    # 辅助数组，用于存放合并结果
    # 归并排序空间复杂度为O(n)
    # 时间复杂度为O(n lb n)
    r = []

    i = low
    j = mid + 1

    # 从两边的头揪出来最小的放到结果数组里
    # 前提是两边集合已经有序
    # 当两边各只有一个时，也是有序的
    # 注意是小于等于号
    while i <= mid and j <= high:
        if a[i] < a[j]:
            r.append(a[i])
            i = i + 1
        else:
            r.append(a[j])
            j = j + 1

    # 把左右剩下的追加进去
    # 同样的，小于等于号
    while i <= mid:
        r.append(a[i])
        i = i + 1
    while j <= high:
        r.append(a[j])
        j = j + 1
    
    for offset,item in enumerate(r):
        a[low + offset] = ite