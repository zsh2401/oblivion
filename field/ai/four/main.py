from cgitb import reset
import numpy as np
import math

def sigmoid(x):
  return 1.0 / (1.0 + np.exp(-x))

def main():
    N = 16 # 几个神经元进行运算
    P = 4 # 有几种分类结果

    np.random.seed(2401)

    X = np.array([[3.0,2.0]])
    W1 = np.random.rand(len(X[0]),N) # X个输入元素，N个神经元，
    b1 = np.random.rand(N)

    H1 = np.matmul(X,W1)[0] + b1
    H1 = activate(H1)

    # H1为N列向量

    W2 = np.random.rand(N,P) # N行，P列，p为结果的数量
    b2 = np.random.rand(P)
    Y = np.matmul([H1],W2)[0] + b2
    Y = activate(Y)
    
    P = softmax(Y)
    L = loss(P,[1,0,0,0])

    print(P)
    print(L)

    pass
def activate(vector):
    result = []
    for n in vector:
        result.append(sigmoid(n))
    return result;

def softmax(Y):
    probs = np.exp(Y - np.max(Y, keepdims=True))
    probs /= np.sum(probs, axis=0, keepdims=True)
    return probs

def loss(P,T):
    return np.sum(np.square(P - T)) / len(P)
    
if __name__ == "__main__":
    main()