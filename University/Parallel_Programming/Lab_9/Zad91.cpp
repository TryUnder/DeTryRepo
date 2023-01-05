#include <iostream>
#include <omp.h>
#include <time.h>
#include <unistd.h>

int main() {
	sleep(rand()%4);
	srand(time(NULL));
	double* a;
	double* b;
	double* c;
	unsigned int size;
	std::cout << "Podaj rozmiar wektorow: " << std::endl;
	std::cin >> size;
	omp_set_num_threads(4);
	a = new double[size];
	b = new double[size];
	c = new double[size];
	for (int i = 0; i < size; ++i) {
		a[i] = ((float)rand() / RAND_MAX) + rand() % 10;
		b[i] = ((float)rand() / RAND_MAX) + rand() % 10;
		c[i] = ((float)rand() / RAND_MAX) + rand() % 10;
	}
	
	for (int i = 0; i < size; ++i) {
		std::cout << "a[" << i+1 << "]: " << a[i] << " "   << "b[" << i+1 << "]: " << b[i] << " " "c[" << i+1 << "]: " << c[i] << std::endl;
	}
	
	//1 - sekwencyjnie
	for (int i = 0; i < size; ++i) {
		a[i] = c[i] + c[i];
		b[i] = b[i] + c[i];
	}
	
	std::cout << "Po obliczeniach nr 1: " << std::endl;
	
	for (int i = 0; i < size; ++i) {
		std::cout << "a[" << i+1 << "]: " << a[i] << " "   << "b[" << i+1 << "]: " << b[i] << " " "c[" << i+1 << "]: " << c[i] << std::endl;
	}
	
	//2 - rownolegle - dyrektywa sections
	#pragma omp parallel sections
	{
		#pragma omp section
			for (int i = 0; i < size; ++i) {
				a[i] = c[i] + c[i];
			}
		#pragma omp section
			for (int i = 0; i < size; ++i) {
				b[i] = b[i] + c[i];
			}
	}
	
	std::cout << "Po obliczeniach nr 2: " << std::endl;
	
	for (int i = 0; i < size; ++i) {
		std::cout << "a[" << i+1 << "]: " << a[i] << " "   << "b[" << i+1 << "]: " << b[i] << " " "c[" << i+1 << "]: " << c[i] << std::endl;
	}
	
	//3 - rownolegle - dyrektywa for i parallel
	#pragma omp parallel
	#pragma omp for
	
	for (int i = 0; i < size; ++i) {
		a[i] = c[i] + c[i];
		b[i] += c[i];
	}
	
	std::cout << "Po obliczeniach nr 3: " << std::endl;
	
	for (int i = 0; i < size; ++i) {
		std::cout << "a[" << i+1 << "]: " << a[i] << " "   << "b[" << i+1 << "]: " << b[i] << " " "c[" << i+1 << "]: " << c[i] << std::endl;
	}
}
