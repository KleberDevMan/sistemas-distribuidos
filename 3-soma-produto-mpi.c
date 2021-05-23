// Autor: Kleber

// Processo 0:
//      - Envia seu número inteiro para o Processo 1
//      - Recebe o número inteiro do Processo 1
//      - Imprime a soma dos dois valores
// Processo 1:
//      - Recebe o número inteiro do Processo 0
//      - Envia seu número inteiro para o Processo 0
//      - Imprime o produto dos dois valores

#include <mpi.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int rank;          // identificador de cada processo
    int num_processos; // numero de processo
    int my_number;
    int received_number;

    // inicia bloco compartilhado
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_processos);

    if (rank == 0)
    {
        my_number = 3;

        MPI_Send(&my_number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Recv(&received_number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        int sum = my_number + received_number;
        printf("\n[Process %d/%d] Soma (%d + %d): %d", rank, num_processos, my_number, received_number, sum);
    }
    else
    {
        my_number = 4;

        MPI_Send(&my_number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        MPI_Recv(&received_number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        int prod = my_number * received_number;
        printf("\n[Process %d/%d] Produto (%d * %d): %d", rank, num_processos, my_number, received_number, prod);
    }
    printf("\n");

    MPI_Finalize(); // fim bloco compartilhado
    return 0;
}