#include <iostream>
#include <mpi.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

using namespace std;

int main(int argc, char* argv[]){
	MPI_Init(&argc, &argv);
	int rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	sleep(rank);
	srand(time(NULL));

	int rand1 = rand() % 11;
	cout << rand1 << endl;
	int max;
	MPI_Reduce(&rand1, &max, 1, MPI_INT, MPI_MAX, 1, MPI_COMM_WORLD );
	if (rank == 1)
		cout << "Wylosowana maksymalna liczba wynosi: " << max << endl;
	MPI_Finalize();
	return 0;
}
