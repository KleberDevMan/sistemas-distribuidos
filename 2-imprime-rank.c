// Autor: Kleber

// Imprime o rank do processo na tela

#include <mpi.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int num_processos; // numero total de processos
    int rank;          // identificador de cada processo

    // Inicia bloco de código compartilhado
    MPI_Init(NULL, NULL);
    // diz quantos processos (nucleos CPU/ nós na rede) vao executar este codigo
    MPI_Comm_size(MPI_COMM_WORLD, &num_processos); //&endero_de_memoria da variavel em cada processo
    // inicializar o identificador de cada processo
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    printf("\nOlá. Meu rank é %d/%d\n", rank + 1, num_processos);

    MPI_Finalize();
    return 0;
}