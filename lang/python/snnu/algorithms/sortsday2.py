import random

# def heap_sort(a:list[int]):

def select_sort(a: list[int]):
    def swap(ai: int, bi: int):
        tmp = a[ai]
        a[ai] = a[bi]
        a[bi] = tmp
    for i in range(len(a)):
        min_index = i
        for j in range(i, len(a)):
            if a[j] < a[min_index]:
                min_index = j
        swap(i, min_index)


def bubble_sort(a: list[int]):
    def swap(ai: int, bi: int):
        tmp = a[ai]
        a[ai] = a[bi]
        a[bi] = tmp
    for i in range(len(a) - 1, 1, -1):
        changed = False
        for j in range(0, i):
            if(a[j] > a[j + 1]):
                swap(j, j+1)
                changed = True
        if not changed:
            break


def insert_sort(a: list[int]):
    for i in range(1, len(a)):
        t = a[i]
        j = i - 1
        while a[j] > t and j >= 0:
            a[j + 1] = a[j]
            j -= 1
        a[j + 1] = t


def quick_sort(a: list[int]):
    def qs(low: int, high: int):
        if low >= high:
            return
        ol, oh = low, high
        pivot = a[low]
        while low < high:
            while low < high and a[high] > pivot:
                high -= 1
            a[low] = a[high]
            while low < high and a[low] < pivot:
                low += 1
            a[high] = a[low]
        a[low] = pivot
        qs(ol, low)
        qs(low + 1, oh)
    qs(0, len(a) - 1)


def merge_sort(a: list[int]):

    def m(low: int, high: int):
        if low < high:
            mid = (low + high) // 2
            m(low, mid)
            m(mid + 1, high)
            # print("?")
            merge(low, mid, high)

    def merge(low: int, mid: int, high: int):
        r: list[int] = []
        i = low
        j = mid + 1
        while i <= mid and j <= high:
            if a[i] < a[j]:
                r.append(a[i])
                i += 1
            else:
                r.append(a[j])
                j += 1

        while i <= mid:
            r.append(a[i])
            i += 1
        while j <= high:
            r.append(a[j])
            j += 1
        for offset, item in enumerate(r):
            a[low + offset] = item

    m(0, len(a) - 1)


# a = [random.randint(0, 100) for i in range(10)]
# quick_sort(a)
# print(a)

# a = [random.randint(0, 100) for i in range(100)]
# merge_sort(a)
# print(a)


# a = [random.randint(0, 100) for i in range(100)]
# insert_sort(a)
# print(a)


a = [random.randint(0, 100) for i in range(100)]
select_sort(a)
print(a)

a = [random.randint(0, 100) for i in range(10)]
shell_sort(a)
print(a)
