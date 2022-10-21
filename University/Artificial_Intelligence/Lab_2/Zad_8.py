import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import math
from matplotlib import cm

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

#generowanie danych
X = np.arange(1,7,0.15)
Y = np.arange(2,6,0.20)
X, Y = np.meshgrid(X, Y)
Z = (np.sqrt((X * X) + (Y * Y))) + 3*np.cos(np.sqrt((X*X)+(Y*Y))+5)

#rysowanie powierzchni
surf = ax.plot_surface(X,Y,Z, cmap=cm.inferno, linewidth=0, antialiased=False)
plt.show()