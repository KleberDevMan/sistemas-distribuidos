// Autor: Kleber Jr

// diferença entre sigle, master e critical

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    int a = 0, b = 0, c = 0;
    
    #pragma omp parallel num_threads(4)
    {
        // deve ser executada em um único thread
        #pragma omp single
        a++;

        // deve ser executado em um thread por vez
        #pragma omp critical
        b++;

        // deve ser executado apenas pela thread maste
        #pragma omp master
        c++;

        printf("a: %d; b: %d; c: %d\n", a, b, c);
    }
}