import numpy as np
import math
import matplotlib.pyplot as plt

a = 0.9
t = np.arange(-2 * math.pi, 2 * math.pi, 0.1)
y = a * np.sin(t - 0.25)
plt.plot(t,y)

y = a * np.sin(t - 0.5)
plt.plot(t, y)
plt.axis([0,10,-1,1])
plt.show()
