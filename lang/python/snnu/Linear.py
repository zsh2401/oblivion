import random
eStr = "abc"
print(eStr[:-1])
print(eStr[1:])

eArr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
print(eArr[3:])
print(eArr[:3])
for n, i in enumerate(eArr):
    print(n)

d = {
    "a": {
        "c": 1
    }
}

random_arr: list[int] = [random.randint(0, 10) for i in range(10)]
print(random_arr)

print(d["a"]["c"])


def swap(arr: list[int], aIndex, bIndex: int):
    tmp = arr[aIndex]
    arr[aIndex] = arr[bIndex]
    arr[bIndex] = tmp


def quick_sort(arr: list[int]):
    def qs(low: int, high: int) -> int:
        pivot = arr[low]
        while low < high:
            while low < high and arr[low] < pivot:
                low += 1
            swap(arr, low, high)

            while low < high and arr[high] > pivot:
                high -= 1

            swap(arr, low, high)
            arr[low] = pivot
            return low

    qs(0, len(arr) - 1)


print(f"Before sorted {random_arr}")
quick_sort(random_arr)
# linear_sort()
print(f"Sorted {random_arr}")
