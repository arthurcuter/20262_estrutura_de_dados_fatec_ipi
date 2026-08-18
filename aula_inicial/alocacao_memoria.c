#include <stdio.h>
#include <stdlib.h>

int main () {

    // int v[]; --> tamanho do vetor indefinido (nao pode) 
    int *v, t;
    float *x;
    // int p[1000000]; estoura a região de variaveis estaticas

    printf("digite o tamanho do vetor: ");
    scanf("%d", &t);

    v = (int *) malloc(t * sizeof(int));
    x = (float *) malloc(t * sizeof(float));

    printf("tamanho de v: %d bytes\n", sizeof(v));
    printf("tamanho de x: %d bytes\n", sizeof(x));

    return 0;
}