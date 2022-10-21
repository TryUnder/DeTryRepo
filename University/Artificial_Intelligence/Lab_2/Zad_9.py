import random
import numpy as np
import matplotlib.pyplot as plt
x = np.random.normal(170, 10, 250)

plt.hist(x)
plt.show()

#z wykresu można odczytać, że dystrybucja wartości zorientowała się w największym stopniu
# w przedziale ~170 na x