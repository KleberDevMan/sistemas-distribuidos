// Autor: prof Jean

// Enviar msg para todos os processo do programa usando MPI_Bcast

#include <mpi.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // inicializa dado
    int buffer[5];

    if (rank == 0)
    {
        // enche o buffer com alguns valores
        for (int i = 0; i < 5; ++i)
            buffer[i] = i * i;
    }

    MPI_Bcast(buffer, 5, MPI_INT, 0, MPI_COMM_WORLD);

    // imprimir o buffer
    cout << "\n";
    cout << "Process #" << rank << "; Buffer = (";
    for (int i = 0; i < 5; ++i)
    {
        cout << buffer[i] << ",";
    }
    cout << ")" << endl;

    MPI_Finalize();
}