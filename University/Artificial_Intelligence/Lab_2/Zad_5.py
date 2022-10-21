import matplotlib.pyplot as plt
import numpy as np
import random

N=100
p = np.random.random([N,2]) * 20 - 10
print(p)

plt.plot(p[:,0], p[:,1],'.',color='green')
x = np.arange(-10,10,1)
y = 6/10*x-9/10
plt.plot(x,y)

for i in range(0,N,1):
    if p[i,1] > 6/10 * p[i,0] -9/10:
        plt.plot(p[i,0], p[i,1],'.',color='blue')
    else:
        plt.plot(p[i,0], p[i,1],'.',color='violet')
plt.show()
