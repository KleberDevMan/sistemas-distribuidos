// Autor: prof Jean

// Enviar uma mensagem de todos os processos para o processo mestre

#include <mpi.h>
#include <stdio.h>
#include <string.h>

// tamanho maximo da mensagem
const int MAX_STRING = 100;

int main(void)
{
    char bem_vindos[MAX_STRING]; // string de texto compartilhada
    int num_processos;           // numero de processo
    int rank;                    // identificador de cada processo

    // Inicia bloco de código compartilhado
    MPI_Init(NULL, NULL);
    // diz quantos processos (nucleos CPU/ nós na rede) vao executar este codigo
    MPI_Comm_size(MPI_COMM_WORLD, &num_processos); //&endero_de_memoria da variavel em cada processo
    // inicializar o identificador de cada processo
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // processo com rank = 0 será o mestre
    //      se rank igual 0, recebo msg
    //      senao, envio msg

    if (rank != 0)
    {
        // escrever msg
        sprintf(bem_vindos, "Sou escravo. Mensagem do processo %d de %d", rank, num_processos);
        // envia msg para processo 0 (4º parametro)
        MPI_Send(bem_vindos, strlen(bem_vindos) + 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
    }
    else
    {
        printf("Sou mestre. Mensagem do processo %d de %d\n", rank, num_processos);

        // receber msg de todos os outros processos
        for (int q = 1; q < num_processos; q++)
        {
            MPI_Recv(bem_vindos, MAX_STRING, MPI_CHAR, q, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("%s\n", bem_vindos);
        }
    }

    MPI_Finalize();
    return 0;
}