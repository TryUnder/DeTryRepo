#include <iostream>
#include <mpi.h>
#include <time.h>
#include <unistd.h>

using namespace std;

int main(int argc, char* argv[]){
	MPI_Init(&argc, &argv);
	int rank;
	int size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	sleep(rank);
	srand(time(NULL));

	int rozmiar;
	int* A;
	int* B;
	int* C;
	if(rank == 0){
		cout << "Podaj rozmiar wektora: ";
		cin >> rozmiar;
		A = new int[rozmiar];
		B = new int[rozmiar];
		C = new int[rozmiar];
		for (int i=0; i<rozmiar; ++i){
			A[i] = 0;
			B[i] = rand() % 11;
			C[i] = rand() % 11;
		}

		for (int i=0; i<rozmiar; ++i){
			cout << "B[" << i+1 << "]: " << B[i] << "\t" << "C[" << i+1 << "]: " << C[i] <<  endl;
		}
	}

	MPI_Bcast(&rozmiar, 1, MPI_INT, 0, MPI_COMM_WORLD);
	int* a = new int[rozmiar/size];
	int* b = new int[rozmiar/size];
	int* c = new int[rozmiar/size];
	MPI_Scatter(B, rozmiar/size, MPI_INT, b, rozmiar/size, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Scatter(C, rozmiar/size, MPI_INT, c, rozmiar/size, MPI_INT, 0, MPI_COMM_WORLD);
        for (int i=0; i<rozmiar/size; ++i){
		a[i] = b[i] + c[i];
	}
	MPI_Gather(a, rozmiar/size, MPI_INT, A, rozmiar/size, MPI_INT, 0, MPI_COMM_WORLD);

	if (rank == 0){
		for(int i=0; i<rozmiar; ++i){
			cout << "A[" << i+1 << "]: " << A[i] << endl;
		}
	}

	MPI_Finalize();	
}
