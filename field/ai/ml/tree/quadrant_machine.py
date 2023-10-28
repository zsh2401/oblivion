import random
import time

from sklearn.tree import DecisionTreeClassifier

from tools import rand_num


# 获取象限生成数据
def get_quadrant_train_data(size=1000, max_abs=1000):
    def get_quadrant(point):
        if point[0] > 0 and point[1] > 0:
            return 1
        elif point[0] < 0 and point[1] > 0:
            return 2
        elif point[0] < 0 and point[1] < 0:
            return 3
        else:
            return 4

    X = []
    y = []
    for i in range(0, size):
        point = [rand_num(max_abs=max_abs), rand_num(max_abs=max_abs)]
        X.append(point)
        y.append(get_quadrant(point))
    return X, y


if __name__ == "__main__":
    刘钰洁 = DecisionTreeClassifier()
    name = f'{刘钰洁=}'.split('=')[0]
    k = time.time()
    print("生成训练数据")
    X, y = get_quadrant_train_data(10_000_000, 10_000_000)
    print(f"已生成训练数据，耗时{time.time() - k}s")
    print(f"正在训练{name}")
    k = time.time()
    刘钰洁.fit(X, y)
    print(f"{name}训练完成，耗时{time.time() - k}s")
    X_test = [[1, 1],
              [-1, 1],
              [-123, -1],
              [1, -12],
              [5,-5],
              [1000,-1000]
              ]
    for i,point in enumerate(X_test):
        print(f"{name}认为{point}是第{刘钰洁.predict([point])[0]}象限")

