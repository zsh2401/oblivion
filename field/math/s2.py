import numpy as np
X=[2.14,2.10,2.13,2.15,2.13,2.12,2.13,2.10,2.15,2.12,2.14,2.10,2.13,2.11,2.14,2.11]


def avg_X(x):
    sum = 0
    for i in range(0,len(x)):
        sum += x[i]
    return sum/ len(x)

def s2(x):
    sum = 0
    avg = avg_X(x)
    for i in range(0,len(x)):
        sum += (x[i] - avg) ** 2
    return sum / (len(x) - 1)

def s(x):
    sum = 0
    avg = avg_X(x)
    for i in range(0,len(x)):
        sum += (x[i] - avg) ** 2
    return sum / len(x)
print(avg_X(X))
print(s2(X))
print(np.average(X))
print(np.var(X))
print(np.mean(X))
print(f"均值 {np.median(X)}")
print(f"极差 {np.range(X)}")
print(f"中程数 {np.mid(X)}")
print(s2(X) ** 0.5)