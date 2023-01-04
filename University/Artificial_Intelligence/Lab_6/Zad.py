import matplotlib.pyplot as plt
import numpy as np
import math
 
xx1 = np.zeros([100,2])
xx1[:,0] = np.random.normal(-1, 1, 100)
xx1[:,1] = np.random.normal(-1, 1, 100)
 
xx2 = np.zeros([100,2])
xx2[:,0] = np.random.normal(-3, 1, 100)
xx2[:,1] = np.random.normal(+3, 1, 100)

x = np.concatenate([xx1, xx2])

xx3 = np.zeros([100,2])
xx3[:,0] = np.random.normal(-5, 1, 100)
xx3[:,1] = np.random.normal(+5, 1, 100)
x = np.concatenate([x, xx3])

N = 3
M = 2
wagi = np.random.random([N, M]) * 4 - 2
 
plt.plot(wagi[:,0], wagi[:,1], 'bo', label='neurony')
plt.plot(x[:, 0], x[:, 1], 'c.', label='punkty')
plt.legend()
plt.show()


print("Wartosci wag: ", wagi)
 
def zwyciezca(xx):
    d = np.zeros(N)
    for i in range(N):
        for n in range(M):
            d[i] += (xx[n] - wagi[i, n])**2
        d[i] = math.sqrt(d[i])
        #print("Odleglosc neuronu nr", i, wagi[i], " od punktu", xx, " wynosi: ", d[i])
    z = np.argmin(d)
    #print("Zwyciezca jest neuron nr: ", z)
    return z,d[z]
 
E = []
for m in range(1000):  
    sumx = 0
    for i in range(0,len(x), 1):
        z,dz = zwyciezca(x[i])
        for j in range(M):
            wagi[z,j] = wagi[z,j] + 0.01 * (x[i,j] - wagi[z,j])
        sumx += dz
    E.append(1/len(x) * sumx)
    if m != 0:
        if E[m] == E[m-1]:
            print (E[m-1], E[m])
            print ("Nauczono w: ", m, " iteracjach")
            break;
     

klasa = np.zeros(len(x))
for i in range(len(x)):
    z,dz = zwyciezca(x[i])
    klasa[i] = z
    
plt.plot(x[klasa[:]==0,0], x[klasa[:]==0,1], 'g.', label="klasa 0")
plt.plot(x[klasa[:]==1,0], x[klasa[:]==1,1], 'r.', label="klasa 1")
plt.plot(wagi[:,0], wagi[:,1], 'bo', label="neuron")
plt.legend()
plt.show()

plt.plot(x[klasa[:]==0,0], x[klasa[:]==0,1], 'g*', label="klasa 1")
plt.plot(x[klasa[:]==1,0], x[klasa[:]==1,1], 'r*', label="klasa 2")
plt.plot(x[klasa[:]==2,0], x[klasa[:]==2,1], 'y*', label="klasa 3")
#plt.plot(x[klasa[:]==3,0], x[klasa[:]==3,1], 'c*', label="klasa 4")
plt.plot(wagi[:,0], wagi[:,1], 'bo', label="neuron")
plt.legend()
plt.show()
print("Wartosci wag: ", wagi)