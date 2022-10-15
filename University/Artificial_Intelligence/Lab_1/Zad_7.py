import numpy as np

matrix1 = np.random.random([5,5])
matrix2 = np.random.random([5,5])

matrix3 = np.add(matrix1,matrix2)
matrix4 = np.subtract(matrix1,matrix2)
matrix5 = np.dot(matrix1,matrix2)

print(matrix5)

matrix6 = matrix5 * 2 / 10

print(matrix6)

for i in range(0, len(matrix6), 1):
    for j in range(0, len(matrix6), 1):
        if i>0 and j>0 and i<len(matrix6)-1 and j<len(matrix6)-1:
            print(matrix6[i][j])

matrix6 = matrix6.reshape(1,25)

print(matrix6)