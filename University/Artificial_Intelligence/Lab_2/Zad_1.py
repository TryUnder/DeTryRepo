import numpy as np
import math
import matplotlib.pyplot as plt

x = np.arange(1,5, 0.2)
y = np.sin(x)
plt.plot(x, y)
plt.axis([0, 5,-1.1, 1.1])
plt.show()