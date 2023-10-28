import random


# 生成随机数字
def rand_num(random_signal=True, max_abs=1.0):
    signal = -1 if random.random() < 0.5 and random_signal else 1
    return random.random() * signal * max_abs
