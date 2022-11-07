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
        self.ActivationFunction()
        self.PlotFigure(parameter3 = "Prosta przed nauka")
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
                    self.ActivationFunction()
                    self.PlotFigure(parameter3 = "Prosta po procesie nauki")
                    return
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
            if self.expectedValue[i] == 0:
                if self.xVector[i,1] > line[i]:
                    plt.plot(self.xVector[i,0], self.xVector[i,1], "bo")
                else:
                    plt.plot(self.xVector[i,0], self.xVector[i,1], "go")
            else:
                if self.xVector[i,1] < line[i]:
                    plt.plot(self.xVector[i,0], self.xVector[i,1], "ro")
                else:
                    plt.plot(self.xVector[i,0], self.xVector[i,1], "m*")
        plt.show()

    def TestFunction(self):
        for i in range(len(self.xVector)):
            print("x1: ", self.xVector[i][0], " x2: ", self.xVector[i][1], " oczekiwany y: ", self.expectedValue[i])
            
perceptron = Perceptron(np.array([[-4,3],[-2,3],[-1,2],[1,2],[2,2],[2,1],[1,4],[1,5],[2,4],[4,4],
                         [4,3],[4,2],[4,1],[8,7],[6,1],[6,3],[6,5],[3,6],[5,6],[-5,7],
                         [-7,-1],[-6,-2],[-4,2],[-2,-2],[-7,-4],[-6,-4],[-4,-4],[-2,-4],[-6,-7],[-4,-7],
                         [1,-7],[1,-5],[1,-2],[3,-7],[3,-4],[5,-6],[6,-5],[7,-5],[6,-7],[8,-7]]),
                         np.array([1,1,1,1,1,1,1,1,1,1,
                                   1,1,1,1,1,1,1,1,1,1,
                                   0,0,0,0,0,0,0,0,0,0,
                                   0,0,0,0,0,0,0,0,0,0]),
                         [np.random.random(1)-0.5, np.random.random(1)-0.25, np.random.random(1)-1], -1.0, 100, 0.01)

perceptron.CorrectWeights()