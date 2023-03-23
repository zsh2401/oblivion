import random
fd = open("/dev/random","rb")


random_arr: list[int] = [random.randint(0,1024) for i in range(1000)]
print(random_arr)

# qwq:list[float] = []

