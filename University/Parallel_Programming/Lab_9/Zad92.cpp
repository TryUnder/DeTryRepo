#include <iostream>
#include <omp.h>
#include <unistd.h>
#include <time.h>
#include <iomanip>

int main() {
	sleep(rand() % 2);
	srand(time(NULL));
	double* a;
	unsigned int size;
	std::cout << "Podaj rozmiar wektora: " << std::endl;
	std::cin >> size;
	a = new double[size];
	double tBegin, tEnd;
	
	for (int i = 0; i < size; ++i) {
		a[i] = ((float)rand() / RAND_MAX) + rand() % 10; 
	}
	
	std::cout << "Wektor wylosowanych liczb: " << std::endl;
	
	for (int i = 0; i < size; ++i) {
		std::cout << "a[" << i+1 << "]: " << a[i] << std::endl; 
	}
	
	std::cout << "Sekwencyjnie (1)" << std::endl;
	
	double var;
	
	tBegin = omp_get_wtime();
	for (int i = 0; i < size; ++i) {
		var += a[i];
	}
	
	if (size != 0)
		var = var / size;
		
	tEnd = omp_get_wtime();
	std::cout << "Srednia (1) sekwencyjnie wynosi: " << var << std::endl;
	std::cout << "Czas (1): "  << tEnd - tBegin << std::endl;
	std::cout << "Rownolegle bez sekcji krytycznej (2): " << std::endl;

	tBegin = omp_get_wtime();
	var = 0;
	#pragma omp parallel
	{
		#pragma omp for
			for (int i = 0; i < size; ++i) {
				var += a[i];
			}
	}
	if (size != 0)
		var = var / size;
	tEnd = omp_get_wtime();
	
	std::cout << "Srednia  (2) wynosi: " << var << std::endl;
	std::cout << "Czas (2): " << tEnd - tBegin << std::endl;

	tBegin = omp_get_wtime();
	var = 0;
	#pragma omp parallel
	{
		#pragma omp for
			for (int i = 0; i < size; ++i) {
				#pragma omp critical
				var += a[i];
			}
	}
	if (size != 0)
		var = var / size;
	tEnd = omp_get_wtime();
	
	std::cout << "Srednia rownolegle z sekcja krytyczna blednie (3) wynosi: " << var << std::endl;
	std::cout << "Czas rownolegle z sekcja krytyczna blednie (3) wynosi: " << tEnd - tBegin << std::endl;
	
	tBegin = omp_get_wtime();
	var = 0;
	#pragma omp parallel
	{
		double lsum = 0.0;
		#pragma omp for
		for (int i = 0; i < size; ++i) {
			lsum += a[i];
		}
		#pragma omp critical
		var += lsum;
	}
	if (size != 0)
		var /= size;
	tEnd = omp_get_wtime();
	std::cout << "Srednia rownolegle z sekcja krytyczna prawidlowo (4) wynosi: " << var << std::endl;
	std::cout << "Czas rownolegle z sekcja krytyczna prawidlowo (4) wynosi: " << tEnd - tBegin << std::endl;
	
	tBegin = omp_get_wtime();
	var = 0;
	#pragma omp parallel
	#pragma omp for reduction(+: var)
	for (int i = 0; i < size; ++i) {
		var += a[i];
	}
	if (size != 0)
		var /= size;
	tEnd = omp_get_wtime();
	std::cout << "Srednia rownolegle z klauzula reduction (5) wynosi: " << var << std::endl;
	std::cout << "Czas rownolegle z klauzula reduction (5) wynosi: " << tEnd - tBegin << std::endl;
	
	
}
