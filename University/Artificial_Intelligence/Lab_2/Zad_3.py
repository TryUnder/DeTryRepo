import numpy as np
import matplotlib.pyplot as plt
a = np.random.rand(10)
b = np.random.rand(10)

x = np.arange(0,1,0.1)
y = a * x + b

plt.plot(x,y)
plt.show()