#!/usr/bin/env python
import multiprocessing
import psutil
import random
import sys

def use_memory(size_in_mb):
    num_elements = size_in_mb * (1024 * 1024) // sys.getsizeof(0)  # 以整数0的大小估算可以存储的元素数量
    large_list = [0] * num_elements  # 创建一个大列表
    return large_list  # 返回列表保持引用，防止被垃圾回收

mem = use_memory(8 * 1024)  
def random_access():
    while True:
        mem[random.randrange(0,len(mem))] = random.random()

def cpu_intensive_task():
    while True:
        pass

if __name__ == '__main__':
    
    num_cores = multiprocessing.cpu_count()
    print(f"启动 {num_cores} 个进程，对应于每个CPU核心.")

    # 创建和启动与CPU核心数量相同的进程
    processes = [multiprocessing.Process(target=cpu_intensive_task) for _ in range(num_cores)]
    for p in processes:
        p.start()
    multiprocessing.Process(target=random_access()).start()
    
    # 等待所有进程完成（实际上它们永远不会完成）
    for p in processes:
        p.join()

