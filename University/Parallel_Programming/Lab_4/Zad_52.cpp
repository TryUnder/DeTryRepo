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
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

	int n;
    double tBegin, tEnd, time;
    double pole = 0;
    if (rank == 0) {
        cout << "Podaj liczbe przedzialow calkowania: ";
        cin >> n;
    }

    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

    double xp = -1.0 + 2.0 / size * rank;
    double xk = -1.0 + 2.0 / size * (rank + 1);
    double dx = (xk - xp) / n;
    //cout << xp << " " << xk << endl;
    tBegin = MPI_Wtime();
    for (int i = 0; i < n; ++i) {
        pole = pole + function(xp+i*dx);
    }

    pole = (pole + function(xp) + function(xk) / 2) * dx;
    cout << pole << endl;
    tEnd = MPI_Wtime();

    time = tEnd - tBegin;

    double tab[size];
    double timeArray[size];
    MPI_Gather(&pole, 1, MPI_DOUBLE, tab, 1, MPI_DOUBLE, 3, MPI_COMM_WORLD);
    MPI_Gather(&time, 1, MPI_DOUBLE, timeArray, 1, MPI_DOUBLE, 3, MPI_COMM_WORLD);

    if(rank == 3){
        double w = 0.0;
        double newTime = 0.0;
        	for (int i = 0; i < size; ++i){
            w += tab[i];
            newTime += timeArray[i];
        }
        cout << "Wynik: " << w * 2 << endl;
        cout << "Czas: " << newTime << endl;
    }
    MPI_Finalize();
    return 0;
 }