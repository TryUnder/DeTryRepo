#include <time.h>
#include <mpi.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>

using namespace std;

int main(int argc, char **argv){
	MPI_Init(&argc, &argv);

	int rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	sleep(rank);
	srand(time(NULL));
	int rozmiar;
	if(rank == 0){
		cout << "Podaj rozmiar rablicy" << endl;
		cin >> rozmiar;
		for(int i=0; i<rozmiar; ++i){
			MPI_Send(&rozmiar,1 , MPI_INT, i, 102, MPI_COMM_WORLD);
		} 
	}

		MPI_Recv(&rozmiar, 1, MPI_INT, 0, 102, MPI_COMM_WORLD, MPI_STATUS_IGNORE); 
		int * t = new int[rozmiar];
		for(int i=0; i<rozmiar; ++i){
			t[i] = rand() % 11;
		}

		for(auto i=0; i<rozmiar; ++i){
		    cout << "Proces nr: " << rank << " t[" << i+1 << "]: " << t[i] << endl; 
		}

		int max = t[0];
		for(int i=0; i<rozmiar; ++i){
			if(t[i] > max){
			    max = t[i];
			}
		}

		cout << "Lokalny maks dla procesu nr: " << rank << " wynosi: " << max << endl;

		int max_max;
		MPI_Reduce(&max, &max_max, 1, MPI_INT, MPI_MAX, 1, MPI_COMM_WORLD);
		if(rank == 1)
			cout << "Globalny max wynosi: " << max_max << endl;
	MPI_Finalize();
}
