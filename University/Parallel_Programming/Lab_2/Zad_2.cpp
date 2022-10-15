#include <iostream>
#include <mpi.h>
using namespace std;
int main (int argc, char *argv[])
{ 
	MPI_Init(&argc, &argv);
	int rank,size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if (rank == 0)
	{
		int a;
		cin >> a;
		MPI_Send(&a, 1, MPI_INT, 1, 102, MPI_COMM_WORLD);
		MPI_Recv(&a, 1, MPI_INT, size - 1, 102, MPI_COMM_WORLD,
		MPI_STATUS_IGNORE);
		cout << "Proces 0 odebral liczbe: " << a << endl;
	}
	if ((rank != 0) && (rank != size -1))
	{
		int b;
		MPI_Recv(&b, 1, MPI_INT, rank - 1, 102, MPI_COMM_WORLD,
		MPI_STATUS_IGNORE);
		b++;
		cout << "Proces 1 odebral liczbe: " << b << endl;
		MPI_Send(&b, 1, MPI_INT, rank + 1, 102, MPI_COMM_WORLD);
	}
	if (rank == size - 1)
	{
		int c;
		MPI_Recv(&c, 1, MPI_INT, rank-1, 102, MPI_COMM_WORLD,
		MPI_STATUS_IGNORE);
		c++;
		cout << "Proces 2 odebral liczbe: " << c << endl;
		MPI_Send(&c, 1, MPI_INT, 0, 102, MPI_COMM_WORLD);
	}
	MPI_Finalize();
	return 0;
}
