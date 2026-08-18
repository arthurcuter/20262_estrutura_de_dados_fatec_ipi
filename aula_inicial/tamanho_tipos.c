#include <stdio.h>

struct s {

    int numero;
    char letra;

};

typedef struct {
    
    float a;
    int b;

} minha_struct;

int main () {

    int v[10];
    struct s s1;

    printf("tamanho do int neste compilador: %d bytes\n", sizeof(int));
    printf("tamanho do float neste compilador: %d bytes\n", sizeof(float));
    printf("tamanho do char neste compilador: %d bytes\n", sizeof(char));
    printf("tamanho do vetor v neste compilador: %d bytes\n", sizeof(v));
    printf("tamanho da struct definida: %d bytes\n", sizeof(s1));

    return 0;
}