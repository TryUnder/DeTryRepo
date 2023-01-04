#include <iostream>
#include <mpi.h>
#include <time.h>
#include <unistd.h>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]){
	MPI_Init(&argc, &argv);
	int rank;
	int size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	sleep(rank);
	srand(time(NULL));
	double tBegin, tEnd;
	tBegin = MPI_Wtime();
	int rozmiar;
	float* A;
	float* B;
	float* C;
		cout << "Podaj rozmiar wektora: ";
		cin >> rozmiar;
		A = new float[rozmiar];
		B = new float[rozmiar];
		C = new float[rozmiar];
		for (int i=0; i<rozmiar; ++i){
			A[i] = (((float)rand() / RAND_MAX) + rand() % 10) + 10;
			B[i] = (((float)rand() / RAND_MAX) + rand() % 100) + 100;
			C[i] = 0;
		}

		for (int i=0; i<rozmiar; ++i){
			cout << "A[" << i+1 << "]: " << A[i] << " B[" << i+1 << "]: " << B[i] << " C[" << i+1 << "]: " << C[i] <<  endl;
		}

	float* a = new float[rozmiar];
	float* b = new float[rozmiar];
	float* c = new float[rozmiar];
        for (int i=0; i<rozmiar; ++i) {
            a[i] = A[i];
            b[i] = B[i];
			c[i] = a[i] + b[i];
	    }

        for (int i=0; i<rozmiar; ++i) {
            C[i] = c[i];
        }

	if (rank == 0){
		cout << "Po obliczeniach: \n";
		for(int i=0; i<rozmiar; ++i){
			cout << "C[" << i+1 << "]: " << C[i] << endl;
		}
	}
	tEnd = MPI_Wtime();

	cout << "Calosc zajela: " << tEnd - tBegin << " czasu " << endl;

	MPI_Finalize();	
}
