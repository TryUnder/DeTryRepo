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
        print(self.xWeight[1], self.xWeight[2])
        for i in range(len(self.xVector)):
            self.sigma.append(self.xVector[i][0] * self.xWeight[1] + self.xVector[i][1] * self.xWeight[2] + self.xWeight[0] * (-1.0))
            if self.sigma[i] >= 0:
                self.givenValue.append(1)
            else:
                self.givenValue.append(0)

            self.error.append(self.expectedValue[i] - self.givenValue[i])

    def CorrectWeights(self):
        for i in range(self.iters):
            self.PlotFigure()
            for j in range(len(self.xVector)):
                self.error.append(self.expectedValue[j] - self.givenValue[j])
                self.xWeight[0] = self.xWeight[0] + self.learningRate * self.error[j] * (-1)
                self.xWeight[1] = self.xWeight[1] + self.learningRate * self.error[j] * self.xVector[j][0]
                self.xWeight[2] = self.xWeight[2] + self.learningRate * self.error[j] * self.xVector[j][1]

    def PlotFigure(self):
        xGenerator = np.arange(-10,10)
        line = -(self.xWeight[1] / self.xWeight[2]) * xGenerator + (self.xWeight[0] / self.xWeight[2])
        plt.plot(xGenerator, line, 'r-')

        for i in range(len(self.xVector)):
            if self.expectedValue[i] == 1:
                plt.plot(self.xVector[i,0], self.xVector[i,1],"bo")
            else:
                plt.plot(self.xVector[i,0], self.xVector[i,1],"go")
        plt.show()

    def TestFunction(self):
        for i in range (len(self.xVector)):
            print("x1: ", self.xVector[i][0], " x2: ", self.xVector[i][1], " oczekiwany y: ", self.expectedValue[i], " obliczony: ", self.givenValue[i], " error: ", self.error[i])


            
            
perceptron = Perceptron(np.array([[-4,3],[-2,3],[-1,2],[1,2],[2,2],[2,1],[1,4],[1,5],[2,4],[4,4],
                         [4,3],[4,2],[4,1],[8,7],[6,1],[6,3],[6,5],[3,6],[5,6],[-5,7],
                         [-7,-1],[-6,-2],[-4,-2],[-2,-2],[-7,-4],[-6,-4],[-4,-4],[-2,-4],[-6,-7],[-4,-7],
                         [1,-7],[1,-5],[1,-2],[3,-7],[3,-4],[5,-6],[6,-5],[7,-5],[6,-7],[8,-7]]),
                         np.array([1,1,1,1,1,1,1,1,1,1,
                                   1,1,1,1,1,1,1,1,1,1,
                                   0,0,0,0,0,0,0,0,0,0,
                                   0,0,0,0,0,0,0,0,0,0]),
                         [np.random.uniform(1)-1, np.random.random(1)-1, np.random.random(1)-1], -1, 10, 0.1)
 
perceptron.ActivationFunction()
perceptron.TestFunction()
perceptron.CorrectWeights()