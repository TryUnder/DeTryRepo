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
	if(rank == 0){
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
	}

	MPI_Bcast(&rozmiar, 1, MPI_INT, 0, MPI_COMM_WORLD);
	float* a = new float[rozmiar/size];
	float* b = new float[rozmiar/size];
	float* c = new float[rozmiar/size];
	MPI_Scatter(A, rozmiar/size, MPI_FLOAT, a, rozmiar/size, MPI_FLOAT, 0, MPI_COMM_WORLD);
	MPI_Scatter(B, rozmiar/size, MPI_FLOAT, b, rozmiar/size, MPI_FLOAT, 0, MPI_COMM_WORLD);
        for (int i=0; i<rozmiar/size; ++i){
			c[i] = a[i] + b[i];
	}
	MPI_Gather(c, rozmiar/size, MPI_FLOAT, C, rozmiar/size, MPI_FLOAT, 0, MPI_COMM_WORLD);

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
