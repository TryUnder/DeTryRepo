#------------------------------------------------------------------------------------------------------------------
#Zad_2
print("------------------------------------------------------------------------------------------------------------")
print("Rozpoznawanie Versicolor")

import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from sklearn.model_selection import train_test_split
from keras.models import Sequential
from keras.layers import Dense, Activation

file = 'https://marcingabryel.pl/ai/iris.csv'
dataframe = pd.read_csv(file)

dataframe['y'] = dataframe['variety']
dataframe['y'] = dataframe['y'].replace('Setosa', 0.0)
dataframe['y'] = dataframe['y'].replace('Versicolor', 1.0)
dataframe['y'] = dataframe['y'].replace('Virginica', 0.0)

x = dataframe[ ['sepal.length', 'sepal.width', 'petal.length', 'petal.width'] ]
y = dataframe['y']

x_train, x_test, y_train, y_test = train_test_split(x, y, stratify = y, test_size = 0.2)

x_train = x_train.to_numpy()
x_test = x_test.to_numpy()
y_train = y_train.to_numpy()
y_test = y_test.to_numpy()


model = Sequential()
model.add(Dense(10, activation='relu', input_dim=4))
model.add(Dense(13, activation='relu'))
model.add(Dense(11, activation='relu'))
model.add(Dense(9, activation='relu'))
model.add(Dense(7, activation='relu'))
model.add(Dense(5, activation='relu'))
model.add(Dense(3, activation='relu'))
model.add(Dense(2, activation='relu'))
model.add(Dense(1, activation='sigmoid'))
model.compile(optimizer="adam", loss='binary_crossentropy')

history = model.fit(x_train, y_train,  epochs=200 ,batch_size=1, verbose=0)

plt.plot(history.history['loss'])
plt.title('Model loss')
plt.ylabel('Loss')
plt.xlabel('Epoch')
plt.legend(['Train'], loc='upper left')
plt.show()

y_result_train = model.predict(x_train)
y_result_train = np.round(y_result_train)

bledy = 0

for i in range(len(y_train)):
  if y_result_train[i] != y_train[i]:
    bledy += 1

print("Liczba bledow ciagu treningowego: ", bledy)

y_result_test = model.predict(x_test)
y_result_test = np.round(y_result_test)

bledy = 0

for i in range(len(y_test)):
  if y_result_test[i] != y_test[i]:
    bledy += 1

print("Liczba bledow ciagu testowego: ", bledy)

