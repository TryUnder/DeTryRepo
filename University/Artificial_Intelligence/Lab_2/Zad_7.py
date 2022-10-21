import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import math
from matplotlib import cm

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

#generowanie danych
X = np.arange(0.1,20,0.5)
Y = np.arange(1,5,0.25)
X, Y = np.meshgrid(X, Y)
Z = np.sin(X*X + Y*Y)/(np.abs(X*Y)+1)

#rysowanie powierzchni
surf = ax.plot_surface(X,Y,Z, cmap=cm.inferno, linewidth=0, antialiased=False)
plt.show()