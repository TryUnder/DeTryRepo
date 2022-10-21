import matplotlib.pyplot as plt
import numpy as np
import random
import math

N = 100
p = np.random.random([N,2]) * 10 - 5
print(p)

plt.plot(p[:,0], p[:,1],'.',color='green')
x = np.arange(-5,5,0.25)
y = 2 * np.sin(x) - x / 2
plt.plot(x,y)

d = np.zeros(100)
for i in range(0,N,1):
    if p[i,1] > 2 * math.sin(p[i,0]) - p[i,0] / 2:
        plt.plot(p[i,0], p[i,1],'.',color='blue')
        d[i] = 1
    else:
        plt.plot(p[i,0], p[i,1],'.',color='violet')
        d[i] = 0

print(d)
plt.show()


