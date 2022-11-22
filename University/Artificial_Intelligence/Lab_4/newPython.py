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
        self.Yarray = []

    def CalculateSigma(self):
        for i in range(0,len(self.xVector), 1):
            self.sigma.append(self.xVector[i][0] * self.xWeight[1] + self.xVector[i][1]
                             * self.xWeight[2] + self.xWeight[0] * self.thresholdValue)

    def ActivationFunction(self):
        for i in range(0, len(self.xVector), 1):
            if self.sigma[i] >= 0:
                self.givenValue.append(1)
            else:
                self.givenValue.append(0)

    def CalculateY(self):
        self.Yarray = -(self.xWeight[1] / self.xWeight[2]) * self.xVector[:,0] + (self.xWeight[0] / self.xWeight[2])

    def CorrectWeights(self):
        for i in range(0, len(self.xVector), 1):
            self.error.append(self.expectedValue[i] - self.givenValue[i])
            self.xWeight[0] = self.xWeight[0] + self.learningRate * self.error[i] * self.thresholdValue
            self.xWeight[1] = self.xWeight[1] + self.learningRate * self.error[i] * self.xVector[i][0]
            self.xWeight[2] = self.xWeight[2] + self.learningRate * self.error[i] * self.xVector[i][1]
        self.checkCorrectness()
    
    def checkCorrectness(self):
        for i in range(0, len(self.error), 1):
            if self.error[i] == 1:
                self.PlotFigure()

    def PlotFigure(self):
        plt.plot(self.xVector[:,0], self.Yarray, 'r-')
        for i in range(0,len(self.xVector),1):
            if self.expectedValue[i] == 0:
                if self.xVector[i,1] > self.Yarray[i]:
                    plt.plot(self.xVector[i,0], self.xVector[i,1], "bo")
                else:
                    plt.plot(self.xVector[i,0], self.xVector[i,1], "go")
            else:
                if self.xVector[i,1] < self.Yarray[i]:
                    plt.plot(self.xVector[i,0], self.xVector[i,1], "ro")
                else:
                    plt.plot(self.xVector[i,0], self.xVector[i,1], "m*")
        plt.show()


perceptron1 = Perceptron(np.array([[0,0], [0,1], [1,0], [1,1]]),
                         np.array([0,0,0,1]),
                         [np.random.random(1)-0.5, np.random.random(1)-0.25, np.random.random(1)-1], -1.0, 100, 0.1)

perceptron1.CalculateSigma()
perceptron1.ActivationFunction()
perceptron1.CalculateY()
print("Prosta przed nauka")
perceptron1.PlotFigure()
perceptron1.CorrectWeights()
