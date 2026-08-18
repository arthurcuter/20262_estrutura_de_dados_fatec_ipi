#include <stdio.h>

void f1 (int a) {
    
    a = a * 10;
    printf("a dentro de f1: %d\n", a);

}

void f2 (int *a) {

    *a = *a * 10;
    printf("a dentro de f2: %d\n", *a);

}

void le_vetor (int v[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &v[i]);
    }
}

int main () {

    int a = 5;
    int v1[5], v2[10];

    f1(a);
    printf("a depois de f1: %d\n", a);

    f2(&a);
    printf("a depois de f2: %d\n", a);

    le_vetor (v1, 5);
    le_vetor (v2, 10);

    return 0;
}