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
        for i in range(len(self.xVector)):
            self.sigma.insert(i,self.xVector[i][0] * self.xWeight[1] + self.xVector[i][1] * self.xWeight[2] + self.xWeight[0] * self.thresholdValue)
            if self.sigma[i] >= 0:
                self.givenValue.insert(i,1)
            else:
                self.givenValue.insert(i,0)
            #self.error.insert(i,self.expectedValue[i] - self.givenValue[i])

    def CorrectWeights(self):
        self.PlotFigure(parameter3 = "Prosta przed nauka")
        for i in range(self.iters):
            self.ActivationFunction()
            counter = 0
            for j in range(0,len(self.xVector),1):
                self.error.insert(j,self.expectedValue[j] - self.givenValue[j])
                self.xWeight[0] = self.xWeight[0] + self.learningRate * self.error[j] * self.thresholdValue
                self.xWeight[1] = self.xWeight[1] + self.learningRate * self.error[j] * self.xVector[j][0]
                self.xWeight[2] = self.xWeight[2] + self.learningRate * self.error[j] * self.xVector[j][1]
            for k in range(len(self.error)):
                if self.error[k] == 0:
                    counter += 1
                if counter == len(self.error):
                    print("Koncze nauke. Calosc zajela: ", i+1, " iteracji")
                    self.ActivationFunction()
                    self.PlotFigure(parameter3 = "Prosta po procesie nauki")
                    return
            self.error.clear()
            self.sigma.clear()
            self.givenValue.clear()
 

    def PlotFigure(self, parameter3):
        xGenerator = np.arange(-10,10)
        line = -(self.xWeight[1] / self.xWeight[2]) * xGenerator + (self.xWeight[0] / self.xWeight[2])
        plt.plot(xGenerator, line, 'r-', label = parameter3)
        plt.legend()
        for i in range(len(self.xVector)):
            if self.expectedValue[i] == 0:
                if self.xVector[i,1] > -(self.xWeight[1] / self.xWeight[2]) * self.xVector[i,0] + (self.xWeight[0] / self.xWeight[2]):
                    plt.plot(self.xVector[i,0], self.xVector[i,0], "ro")
                else:
                    plt.plot(self.xVector[i,0], self.xVector[i,1], "go")
            else:
                if self.xVector[i,1] < -(self.xWeight[1] / self.xWeight[2]) * self.xVector[i,0] + (self.xWeight[0] / self.xWeight[2]):
                    plt.plot(self.xVector[i,0], self.xVector[i,0], "ro")
                else:
                    plt.plot(self.xVector[i,0], self.xVector[i,1], "m*")
        plt.show()

    def TestFunction(self):
        for i in range (len(self.xVector)):
            print("x1: ", self.xVector[i][0], " x2: ", self.xVector[i][1], " oczekiwany y: ", self.expectedValue[i], " obliczony: ", self.givenValue[i], " error: ", self.error[i])


            
            
perceptron = Perceptron(np.array([[-4,3],[-2,3],[-1,2],[1,2],[2,2],[2,1],[1,4],[1,5],[2,4],[4,4],
                         [4,3],[4,2],[4,1],[8,7],[6,1],[6,3],[6,5],[3,6],[5,6],[-5,7],
                         [-7,-1],[-6,-2],[-4,2],[-2,-2],[-7,-4],[-6,-4],[-4,-4],[-2,-4],[-6,-7],[-4,-7],
                         [1,-7],[1,-5],[1,-2],[3,-7],[3,-4],[5,-6],[6,-5],[7,-5],[6,-7],[8,-7]]),
                         np.array([1,1,1,1,1,1,1,1,1,1,
                                   1,1,1,1,1,1,1,1,1,1,
                                   0,0,0,0,0,0,0,0,0,0,
                                   0,0,0,0,0,0,0,0,0,0]),
                         [np.random.random(1)-1, np.random.random(1)-1, np.random.random(1)-1], -1.0, 100, 0.02)

perceptron.CorrectWeights()