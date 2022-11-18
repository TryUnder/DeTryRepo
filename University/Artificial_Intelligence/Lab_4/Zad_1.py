import numpy as np
import matplotlib.pyplot as plt 
 
class Perceptron:
    def __init__(self, xVector, expectedValue, xWeight, thresholdValue, iters, learningRate):
        self.xVector = xVector
        self.expectedValue = expectedValue
        self.xWeight = xWeight
        self.thresholdValue = thresholdValue
        self.iters = iters
        self.learningRate = learningRate
        self.sigma = []
        self.error = []
        self.givenValue = []
 
    def ActivationFunction(self):
        for i in range(0,len(self.xVector),1):
            self.sigma.append(self.xVector[i][0] * self.xWeight[1] + self.xVector[i][1] * self.xWeight[2] + self.xWeight[0] * self.thresholdValue)
            if self.sigma[i] >= 0:
                self.givenValue.append(1)
            else:
                self.givenValue.append(0)
            #self.error.append(self.expectedValue[i] - self.givenValue[i])
 
    def CorrectWeights(self):
        y = self.PlotFigure(parameter3 = "Prosta przed nauka")
        for i in range(0,self.iters,1):
            self.ActivationFunction()
            counter = 0
            for j in range(0,len(self.xVector),1):
                self.error.append(self.expectedValue[j] - self.givenValue[j])
                self.xWeight[0] = self.xWeight[0] + self.learningRate * self.error[j] * self.thresholdValue
                self.xWeight[1] = self.xWeight[1] + self.learningRate * self.error[j] * self.xVector[j][0]
                self.xWeight[2] = self.xWeight[2] + self.learningRate * self.error[j] * self.xVector[j][1]
            for k in range(0,len(self.error),1):
                if self.error[k] == 0:
                    counter += 1
                if counter == len(self.error):
                    print("Koncze nauke. Calosc zajela: ", i+1, " iteracji")
                    self.givenValue.clear()
                    self.ActivationFunction()
                    y = self.PlotFigure(parameter3 = "Prosta po procesie nauki")
                    return y
 
            self.error.clear()
            self.sigma.clear()
            self.givenValue.clear()
 
    def PlotFigure(self, parameter3):
        #xGenerator = np.arange(-10,10)
        #self.TestFunction()
        #print(len(self.xVector))
        line = -(self.xWeight[1] / self.xWeight[2]) * self.xVector[:,0] + (self.xWeight[0] / self.xWeight[2])
        plt.plot(self.xVector[:,0], line, 'r-', label = parameter3)
        plt.legend()
        for i in range(0,len(self.xVector),1):
            if self.expectedValue[i] == 1:
                if self.xVector[i,1] > line[i]:
                    plt.plot(self.xVector[i,0], self.xVector[i,1], "bo")
                else:
                    plt.plot(self.xVector[i,0], self.xVector[i,1], "go")
            else:
                if self.xVector[i,1] < line[i]:
                    plt.plot(self.xVector[i,0], self.xVector[i,1], "ro")
                else:
                    plt.plot(self.xVector[i,0], self.xVector[i,1], "m*")
        plt.axis([-4,4,-4,4])
        plt.show()
        return 
 
    #def TestFunction(self):
        #for i in range(len(self.xVector)):
            #print("x1: ", self.xVector[i][0], " x2: ", self.xVector[i][1], " oczekiwany y: ", self.expectedValue[i])
 
    def PrintGV(self):
        return self.givenValue
        #for i in range(len(self.givenValue)):
            #print(self.givenValue[i])
 
perceptron1 = Perceptron(np.array([[0,0], [0,1], [1,0], [1,1]]),
                         np.array([0,0,0,1]),
                         [np.random.random(1)-0.5, np.random.random(1)-0.25, np.random.random(1)-1], -1.0, 100, 0.1)
 
perceptron2 = Perceptron(np.array([[0,0], [0,1], [1,0], [1,1]]),
                         np.array([1,0,0,0]),
                         [np.random.random(1)-0.5, np.random.random(1)-0.25, np.random.random(1)-1], -1.0, 100, 0.1)
 
 
y1 = perceptron1.CorrectWeights()
y2 = perceptron2.CorrectWeights()
yy1 = perceptron1.PrintGV()
yy2 = perceptron2.PrintGV()

print(yy1[0],yy2[0])
print(yy1[1],yy2[1])
print(yy1[2],yy2[2])
print(yy1[3],yy2[3])
perceptron3 = Perceptron(np.array([[yy1[0], yy2[0]],
                                   [yy1[1], yy2[1]],
                                   [yy1[3], yy2[3]]]),
                         np.array([1,0,1]),
                         [np.random.random(1) - 0.5, np.random.random(1) - 0.25, np.random.random(1) - 1], -1.0, 100, 0.1)





y3 = perceptron3.CorrectWeights()
#perceptron3.PrintGV()
