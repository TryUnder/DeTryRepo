#include <iostream>
#include <mpi.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv){
    MPI_Init(&argc, &argv);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    sleep(rank);
    srand(time(NULL));
    
    int rozmiar;
    if(rank == 0){
	cout << "Podaj rozmiar tablicy: ";
	cin >> rozmiar;
    }
    MPI_Bcast(&rozmiar, 1, MPI_INT, 0, MPI_COMM_WORLD);
    cout << rank << ": " << rozmiar << endl;
    
    int* array = new int[rozmiar];
    for(auto i=0; i<rozmiar; ++i){
	array[i] = rand() % 11;
    }

    for(auto i=0; i<rozmiar; ++i){
	cout << "Proces nr: " << rank << " t[" << i+1 << "]: " << array[i] << endl;
    }

    int max = array[0];
    
    for(auto i=0; i<rozmiar; ++i){
	if(array[i] > max){
	    max = array[i];
	}
    }

    cout << "Lokalny maks dla procesu nr: " << rank << " wynosi: " << max << endl;

    int max_glob;
    MPI_Reduce(&max, &max_glob, 1, MPI_INT, MPI_MAX, 1, MPI_COMM_WORLD);
    if(rank == 1){
	cout << "Globalny max wynosi: " << max_glob << endl;
    }

    MPI_Finalize();
    return 0;
}
