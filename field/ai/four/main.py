from cgitb import reset
import numpy as np
import math

def sigmoid(x):
    return 1.0 / (1.0 + np.exp(-x))
    
def dsigmoid(x):
    return np.exp(-x) / np.square(1 + np.exp(-x))

def main():

    N = 16 # 由几个神经元进行运算
    P = 4 # 分为几类
    D = 2 # 输入层向量维数
    reg = 0.0001 # 正则化强度
    epsilon = 0.0001 # 学习率


    T = training_set(100000) # 训练集
    np.random.seed(2401)   # 设置随机数种子

    # D维，N个神经元，
    # 当1行D列的矩阵与D行N列的矩阵相乘
    # 得到1行N列的矩阵
    # 其中第一行看作向量，则是N维的隐藏层神经元向量
    W1 = np.random.rand(D,N) 
    b1 = np.random.rand(N)

    # 当1行N列的隐藏层与N行，P列的第二层相乘
    # 得出1行P列的矩阵作为结果
    # 其中第一行看作向量，则为P维的预测结果向量
    W2 = np.random.rand(N,P) # N行，P列，p为结果的数量
    b2 = np.random.rand(P)

    for teaching_data in T:
        point,t = teaching_data;
        # H1为隐藏层，Y为第二层计算结果
        # P为softmax(Y)，是一个P维向量
        # L为损失值，是一个数字，为L = LOSS(P,T)
        H1,Y,P,L = forward_once(np.array(point),W1,b1,W2,b2,t)
        dw1,db1,dw2,db2 = backward_once(H1,Y,P,L,t)
        learn(W1,b1,W2,b2,dw1,db1,dw2,db2,epsilon,reg)

    print(pred([1,1],W1,b1,W2,b2))

def learn(W1,b1,W2,b2,dw1,db1,dw2,db2,epsilon,reg):
    W1 -= epsilon * (dw1 + W1 * reg)
    W2 -= epsilon * (dw2 + W2 * reg)
    b1 -= epsilon * db1
    b2 -= epsilon * db2

# 反向传播
# H1为1行N列的移仓
def backward_once(H1,Y,P,L,t):
    dldp = dloss(P,t) # 当p变化时，l如何变化
    dpds = "" # 当softmax层结果变化时，p如何变化
    dsdy = "" # 当y结果变化时，s如何变化
    dydw = "" # 当w变化时，y如何变化
    return 

def pred(X,W1,b1,W2,b2):
    R = forward_once(X,W1,b1,W2,b2)
    return R[2]
    
def forward_once(X,W1,b1,W2,b2,t):
    H1,cache1 = affine_forward(X,W1,b1) # 输入层传播到隐藏层
    H1 = activate(H1) # 激活隐藏层

    Y,cache2 = affine_forward(H1,W2,b2) # 传播到第二层，得到一行N列的矩阵结果

    P = softmax(Y)          #   转化为概率值
    L = loss(P,t)   #   计算损失函数
    return H1,Y,P,L

# X为有i列元素的向量
# W为i行N列的矩阵
# b为N列向量
def affine_forward(X,W,b):
    Y = np.matmul([X],W)[0] + b
    return Y,(X,W,b)

def activate(vector):
    result = []
    for n in vector:
        result.append(sigmoid(n))
    return result;

def dsoftmax(Y):
    pass

def softmax(Y):
    P = np.exp(Y - np.max(Y, keepdims=True))
    P /= np.sum(P, axis=0, keepdims=True)
    return P

def loss(P,T):
    return np.sum(np.square(P - T)) / len(P)

def dloss(P,T):
    return -2 * (P - T) / len(P)

def training_set(size=1000):
    ABS_MAX = 1000;
    result = []
    
    def next_float():
        return np.random.random() * 2 * ABS_MAX - ABS_MAX

    for i in range(size):
        point = [next_float(),next_float()]
        if point[0] > 0 and point[1] > 0:
            result.append((point,[1,0,0,0]))
        elif point[0] < 0 and point[1] > 0 :
            result.append((point,[0,1,0,0]))
        elif point[0] < 0 and point[1] < 0:
            result.append((point,[0,0,1,0]))
        else:
            result.append((point,[0,0,0,1]))
            
    return result

if __name__ == "__main__":
    main()