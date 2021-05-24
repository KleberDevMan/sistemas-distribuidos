// Autor: Kleber

// Processo 0:
//      - Ler os dados de entrada (em um buffer de doubles) e enviar esses dados para os outros processos. Isso deve ser feito em duas etapas:
//          - Enviar o número de elementos do buffer. Assim, os processos 1 e 2 serão capazes de criar os buffers de recepção com o tamanho correto.
//          - Enviar o buffer com os elementos.
// Processo 1:
//      - Soma e imprime os elementos positivos.
// Processo 2:
//      - Soma e imprime os elementos negativos.

#include <mpi.h>
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    double buffer[5];

    if (rank == 0)
    {
        // inicializa dados
        buffer[0] = -2.2;
        buffer[1] = -1.1;
        buffer[2] = 0;
        buffer[3] = 1.1;
        buffer[4] = 2.2;
    }

    MPI_Bcast(buffer, 5, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    cout << "\n";
    cout << "Process #" << rank;
    string delim = "";
    double soma;
    double num;

    if (rank == 1) // trabalha os positivos
    {
        cout << "; Positivos [";
        for (int i = 0; i < 5; ++i)
        {
            num = buffer[i];

            if (num >= 0)
            {
                cout << delim << num;
                soma += num;
                delim = ", ";
            }
        }
        cout << "]; Soma: " << soma << endl;
    }

    if (rank == 2) // trabalha os negativos
    {
        cout << "; Negativos [";
        for (int i = 0; i < 5; ++i)
        {
            num = buffer[i];

            if (num < 0)
            {
                cout << delim << num;
                soma += num;
                delim = ", ";
            }
        }
        cout << "]; Soma: " << soma << endl;
    }

    MPI_Finalize();
}
