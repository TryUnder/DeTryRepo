import random
import math
 
L = 2
mi = 0.2
N = [2, 2, 1]
 
w = [
    [],
    [ [], [0,0,0], [0,0,0]],
    [ [], [0,0,0], ]
]
 
s = [
    [],
    [None, 0, 0],
    [None, 0]
]
 
x = [
    [],
    [-1,0,0],
    [-1,0,0]
]
 
y = [
    [],
    [None, 0, 0],
    [None, 0]
]
 
e = [
    [],
    [None, 0, 0],
    [None, 0]
]
 
dlt = [
    [],
    [None, 0, 0],
    [None, 0]
]
 
 
def losuj_w():
    for k in range(1, L+1):
        for i in range(1, N[k]+1):
            for j in range(0, N[k-1]+1):
                w[k][i][j] = random.random() * 2 - 1
 
def licz_y(u):
    for k in range(1, L+1):
        for i in range(1, N[k-1] + 1):
            if k == 1:
                x[k][i] = u[i-1]
            else:
                x[k][i] = y[k-1][i]
 
        for i in range(1, N[k] + 1):
            s[k][i] = 0
            for j in range(0, N[k-1] + 1):
                s[k][i] += w[k][i][j] * x[k][j]
            y[k][i] = f(s[k][i])
    return y[L][1]
 
def f(s):
    return 1 / (1 + math.exp(-s))
 
def f_poch(s):
    return f(s) * (1 - f(s))
 
def licz_e(d):
    for k in range(L, 1-1, -1):
        for i in range(1, N[k] + 1):
            if k == L:
                e[k][i] = d - y[k][i]
            else:
                e[k][i] = 0
                for j in range(1, N[k+1] + 1):
                    e[k][i] += dlt[k+1][j] * w[k+1][j][i]
            dlt[k][i] = e[k][i] * f_poch(s[k][i])
 
u = [[0,0],
     [0,1],
     [1,0],
     [1,1]]
 
d = [0,
     1,
     1,
     0]
 
losuj_w()
print(w)
n=1
yy = [1,0,0,1]
max_n = 10000
partial_sum = 0

for n in range(max_n):
    partial_sum = 0
    for m in range(len(u)):
        uu = u[m]
        dd = d[m]
        yy[m] = licz_y(uu)
        partial_sum += math.pow(dd - yy[m], 2)
        licz_e(dd)
        for k in range(1, L+1):
            for i in range(1, N[k]+1):
                for j in range(0, N[k-1]+1):
                    w[k][i][j] = w[k][i][j] + 2 * mi * dlt[k][i] * x[k][j]
    Q = 1 / len(u) * partial_sum
    if (Q < 0.01):
        print("Iteracja: ", n, " Blad: ", Q)
        break
    
 
print(yy)
