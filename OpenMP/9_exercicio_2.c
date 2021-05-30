// Autor: prof Jean

// produto escalar entre dois vetores

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// constantes
#define NX 100000 // 100.000

void print_array(double *array, int length)
{
    printf("[");
    for (int i = 0; i < length; i++)
    {
        printf("%.1f ", array[i]);
    }
    printf("]\n");
}

int main(int argc, char *argv[])
{
    double sum = 0;
    int i;
    int thread_count = strtol(argv[1], NULL, 10);
    double vecA[NX];
    double vecB[NX];

    // set vetores
    for (int i = 0; i < NX; i++)
    {
        vecA[i] = i;
        vecB[i] = i;
    }

    // realiza o calculo
    #pragma omp parallel for reduction(+:sum) num_threads(thread_count)
    for (i = 0; i < NX; i++)
    {
        // #pragma omp atomic
        // #pragma omp critical
        sum += vecA[i] * vecB[i];
    }

    printf("todos as %d threads terminaram !\n\n", thread_count);

    //imprime vetores
    // print_array(vecA, NX);
    // print_array(vecB, NX);

    //imprime resultado
    printf("\nResultado: %.1f\n", sum);
}