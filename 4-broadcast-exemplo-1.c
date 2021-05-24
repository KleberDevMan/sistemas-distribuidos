// Autor: prof Jean

// Enviar msg para todos os processo do programa usando MPI_Send/MPI_Recv

#include <mpi.h>
#include <iostream>

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
        for (int i=0; i < 5; ++i)
            buffer[i] = i * i;

        // enviar buffer para todos os outros processos
        for (int id_dest=1; id_dest < size; ++id_dest)
            MPI_Send(buffer, 5, MPI_INT, id_dest, 0, MPI_COMM_WORLD);
    }
    else
    {
        // receber o buffer
        MPI_Recv(buffer, 5, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
    
    // imprimir o buffer
    std::cout << "Process #" << rank << "; Buffer = (";
    for (int i = 0; i < 5; i++)
    {
        std::cout << buffer[i] << std::endl;
    }

    MPI_Finalize();
}