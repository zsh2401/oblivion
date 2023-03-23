import random
import time
from typing import Callable

from quicksort import quick_sort
from mergesort import merge_sort


def ranArr(count=1_000_000) -> list[int]:
    return [random.randint(0, 100) for i in range(count)]

def test(algorithm: Callable[[list[int]], None]):
    start = time.time() * 1000
    a = ranArr()
    algorithm(a)
    end = time.time() * 1000
    # print(a)
    print(f"{algorithm.__name__} used {round(end - start,1)} ms")
    pass


# test(quick_sort)
test(merge_sort)
