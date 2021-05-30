// Autor: prof Jean

// Soma

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[])
{
    int total = 0;
    int thread_count = strtol(argv[1], NULL, 10);

    // realiza o calculo
    #pragma omp parallel for num_threads(thread_count)
    for (unsigned i = 0; i < 5; i++)
    {
        printf("Thread %d está processando a iteração %d/%d.\n", omp_get_thread_num(), i, 5);
        total += 1;
    }

    // espera!
    #pragma omp barrier

    // imprime resultado
    #pragma omp master
    printf("Resultado: %d\n", total);
}