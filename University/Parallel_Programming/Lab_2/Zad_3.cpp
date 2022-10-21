#include <iostream>
#include <mpi.h>
#include <fstream>
using namespace std;

int main(int argc, char** argv){
    MPI_Init(&argc, &argv);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    fstream odczyt("zad2.txt");
    double* tab = new double[10];

    unsigned rozmiar;
    while(!odczyt.eof()){
	odczyt >> rozmiar;
	for(int i=0; i<10; ++i){
	    odczyt >> tab[i];
	}
	break;
    }
    unsigned x;
    if(rank == 0){
	MPI_Send(&rozmiar, 1, MPI_UNSIGNED, 1, 102, MPI_COMM_WORLD);
	for(int i=0; i<rozmiar; ++i){
	    MPI_Send(&tab[i], 1, MPI_DOUBLE, 1, 102, MPI_COMM_WORLD);
	}
	double sum_r0;
	MPI_Recv(&sum_r0, 1, MPI_DOUBLE, 1, 102, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	cout << sum_r0 << endl;
    }

    if(rank == 1){
	unsigned rozm;
	double* tab_r1 = new double[rozm];
	MPI_Recv(&rozm, 1, MPI_UNSIGNED, 0, 102, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	for(auto i=0; i<rozm; ++i){
	    MPI_Recv(&tab_r1[i], 1, MPI_DOUBLE, 0, 102, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	}
	double sum;
	for(auto i=0; i<rozm; ++i){
	    sum+= tab_r1[i];
	}
	MPI_Send(&sum, 1, MPI_DOUBLE, 0, 102, MPI_COMM_WORLD);
    }

    MPI_Finalize();

    return 0;
}
