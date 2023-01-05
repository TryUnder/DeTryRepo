#include <iostream>

__global__ void emptyKernel() {}

__global__ void add(int* a, int* b, int* c) {
	c[blockIdx.x]  = a[blockIdx.x] + b[blockIdx.x];
}

int main() {
	unsigned int N;
	std::cout << "Podaj rozmiar" << std::endl;
	std::cin >> N;
	unsigned int size = N;
	int* a;
	int* src1 = new int[size];
	int* b;
	int* src2 = new int[size];
	int* c;
	int* src3 = new int[size];
	int* result = new int[size];
	
	int* cpuSum = new int[size];
	
	cudaMalloc((void **)&a, size * sizeof(int));
	cudaMalloc((void **)&b, size * sizeof(int));
	cudaMalloc((void **)&c, size * sizeof(int));
	
	for (int i = 0; i < size; ++i) {
		src1[i] = i;
		src2[i] = 10;
		src3[i] = 0;
	}
	
	for (int i = 0; i < size; ++i) {
		cpuSum[i] = src1[i] + src2[i];
	}
	
	std::cout << "Suma na CPU: \n" << std::endl;
	
	for (int i = 0; i < size; ++i) {
		std::cout << cpuSum[i] << std::endl;
	}
	
	cudaMemcpy(a, src1, sizeof(int) * size, cudaMemcpyHostToDevice); 
	cudaMemcpy(b, src2, sizeof(int) * size, cudaMemcpyHostToDevice);
	cudaMemcpy(c, src3, sizeof(int) * size, cudaMemcpyHostToDevice);
	
	
	add<<<N,1>>>(a, b, c);
	
	cudaMemcpy(result, c, sizeof(int) * size, cudaMemcpyDeviceToHost);
	std::cout << "Suma na GPU: \n" << std::endl;
	for (int i = 0; i < size; ++i) {
		std::cout << result[i] << std::endl;
	}
	
	return 0;
}
