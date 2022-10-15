import numpy as np

matrix = np.zeros([5,5])
matrix2 = np.zeros([5,5])

for i in range(0, len(matrix), 1):
    for j in range(0, len(matrix), 1):
        if ((i==0 and j>=0) or (i>=0 and j==0) or (i>=0 and j==len(matrix)-1) or (i==len(matrix)-1 and j>=0)):
            matrix2[i][j] = 200
            
def change_values(matrix,choice):
    for i in range(0, len(matrix), 1):
        for j in range(0, len(matrix), 1):
            if i>0 and j>0 and i<len(matrix)-1 and j<len(matrix)-1:
                #match choice:
                    #case "zero":
                        matrix2[i][j] = 0
                    #case "one":
                        matrix2[i][j] = 1
print(matrix2)
change_values(matrix2,"one")
print(matrix2)