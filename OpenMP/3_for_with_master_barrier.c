// Autor: prof Jean

// Diretivas for, master e barrier

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(){
    int a[5], i;

    #pragma omp parallel
    {
        // realiza calculo
        #pragma omp parallel for
        for (i = 0; i < 5; i++)
            a[i] = i * i;

        // somente a master vai imprimir
        #pragma omp master
        for (i = 0; i < 5; i++)
            printf("a[%d] = %d\n", i, a[i]);

        // espera!
        #pragma omp barrier

        // continua calculo
        #pragma omp parallel for
        for (i = 0; i < 5; i++)
            a[i] += i;
    }
}