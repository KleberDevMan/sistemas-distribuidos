// Autor: prof Jean

// Na maioria das vezes, as threads são interessantes quando trabalhamos com loops.
// Abaixo, divide um loop de execução em diferentes threads

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// constantes
#define THREADS 4
#define N 100
#define CHUNK 25

int main(){
    int i;
    #pragma omp parallel for schedule(dynamic, CHUNK) num_threads(THREADS)
    for (i = 0; i < N; i++){
        sleep(i);
        printf("Thread %d está processando a iteração %d.\n", omp_get_thread_num(), i);
    }

    printf("todos os threads terminaram !\n");
    return 0;
}