import numpy as np

matrix = np.random.random([10,10])

print(matrix)
for i in range(0, len(matrix), 1):
    print("Max w kolumnie",i+1,":",max(matrix[:,i]))
    
for i in range(0, len(matrix), 1):
    print("Max w wierszu",i+1,":",max(matrix[i,:]))