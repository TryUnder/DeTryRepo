#include <iostream>
#include <mpi.h>
#include <cmath>

using namespace std;

double function(double x){
    return (sqrt(1 - pow(x,2)));
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int rank, size;
    double tBegin, tEnd, time;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
	int n;
    double pole = 0;
    if (rank == 0) {
        cout << "Podaj liczbe przedzialow calkowania: ";
        cin >> n;
    }
    tBegin = MPI_Wtime();
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

    double xp = -1.0 + 2.0 / size * rank;
    double xk = -1.0 + 2.0 / size * (rank + 1);
    double dx = (xk - xp) / n;
    //cout << xp << " " << xk << endl;

    for (int i = 0; i < n/size; ++i) {
        pole = pole + function(xp+i*dx);
    }

    pole = (pole + function(xp) + function(xk) / 2) * dx;
    cout << pole << endl;

    double tab[size];
    double timeArray[size];
    // for(auto i=0; i<rozm; ++i){
	//     MPI_Recv(&tab_r1[i], 1, MPI_DOUBLE, 0, 102, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	// }
    //MPI_Gather(&pole, 1, MPI_DOUBLE, tab, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    tEnd = MPI_Wtime();
    if(rank == 0){
        double w = 0.0;
        double newTime = 0.0;
        	for (int i = 0; i < size; ++i){
            w += tab[i];
        }
        cout << "Wynik: " << w * 2 << endl;
        cout << "Czas: " << tEnd-tBegin << endl;
    }
    MPI_Finalize();
    return 0;
 }