#include <stdio.h>
#include <stdlib.h>

#define FRACASSO 0
#define SUCESSO 1
#define CAPACIDADE_MINIMA 10

typedef struct {
  int *v;
  int ocupacao;
  int capacidade;
} t_vetor;

void inicia_vetor(t_vetor *, int);
int esta_cheio(t_vetor *);
void insere(int, t_vetor *);
void exibe_vetor(t_vetor *, char *);
int esta_vazio(t_vetor *);
int remove_elemento(t_vetor *, int *);
// o retorno é SUCESSO ou FRACASSO, o elemento que sai, vem por parâmetro referencia
void limpa_vetor (t_vetor *);
int busca_elemento (t_vetor *, int);


int main() {

  t_vetor vetor;
  printf("digite a capacidade do vetor:  ");
  int capacidade;
  scanf("%d", &capacidade);
  printf("endereco da estrutura %p\n", vetor);
  inicia_vetor(&vetor, capacidade);

  // if (insere(10, &vetor)) {

  //   printf("\n10 inserido com sucesso");

  // } else {

  //   printf("\nnao foi possivel realizar a insercao\n");
  
  // }

  // insere(20, &vetor);
  // exibe_vetor(&vetor, "primeiro vetor");
  // t_vetor outro;
  // inicia_vetor(&outro, 5);
  // exibe_vetor(&outro, "outro vetor");

  for (int i = 1; i <= 100; i++) {
    insere (i, &vetor);
    exibe_vetor (&vetor, "");
  }

  int elemento_removido;

  if (remove_elemento(&vetor, &elemento_removido)) {
    printf ("%d foi removido\n", elemento_removido);
    exibe_vetor (&vetor, "");

  } else {
    printf("vetor vazio, nao ha o que remover\n");
  }
  /*
  while (!esta_vazio(&vetor)) {
    remove_elemento(&vetor, &elemento_removido);
    printf ("%d foi removido\n", elemento_removido);
    exibe_vetor (&vetor, "");
  }
  */
  int elemento;
  printf("\nque elemento quer achar no vetor?: ");
  scanf("%d", &elemento);
  if(busca_elemento(&vetor, elemento)) {
    printf("%d esta no vetor\n");
  } else {
    printf("%d nao esta no vetor\n");
  }

  limpa_vetor(&vetor);
  exibe_vetor(&vetor, "vetor depois do limpa_vetor");
  

  return 0;

}

void inicia_vetor(t_vetor *p_vetor, int capacidade) {

  p_vetor->v = (int *)malloc(capacidade * sizeof(int));
  printf("endereco do vetor dentro da estrutura:  %p\n", p_vetor->v);
  p_vetor->ocupacao = 0;
  p_vetor->capacidade = capacidade;

}

int esta_cheio(t_vetor *p_vetor) {
  /* if(p_vetor->capacidade == p_vetor->ocupacao)
     return 1;
  return 0;
 */
  return p_vetor->capacidade == p_vetor->ocupacao;

}

// int insere(int i, t_vetor *p_vetor) {
//   if (esta_cheio(p_vetor)) {

//     return FRACASSO; // fracasso

//   } else {

//     p_vetor->v[p_vetor->ocupacao] = i;
//     p_vetor->ocupacao++;
//     return SUCESSO; // sucesso
  
//   }

// }

// void dobra (t_vetor * p_vetor) {

//   int *temp = (int *) malloc (sizeof(int) * p_vetor->capacidade * 2);

//   for (int i = 0; i < p_vetor->ocupacao; i++) {
//     temp[i] = p_vetor->v[i];
//   }
//   free (p_vetor->v);
//   p_vetor->v = temp;
//   p_vetor->capacidade = p_vetor->capacidade * 2;

// }
// void reduz_a_metade (t_vetor *p_vetor) {

//   int *temp = (int *) malloc (sizeof(int) * p_vetor->capacidade / 2);
//   for (int i = 0; i < p_vetor->ocupacao; i++) {
//     temp[i] = p_vetor->v[i];
//   }
//   free (p_vetor->v);
//   p_vetor->v = temp;
//   p_vetor->capacidade = p_vetor->capacidade / 2;

// }

void redimensiona (t_vetor *p_vetor, int novaCapacidade) {
  int *temp = (int *) malloc (sizeof(int) * novaCapacidade);
  for (int i=0; i < p_vetor->ocupacao; i++) {
    temp[i] = p_vetor->v[i];
  }
  free(p_vetor->v);
  p_vetor->v = temp;
  p_vetor->capacidade = novaCapacidade;
}

void insere(int i, t_vetor *p_vetor) {

  if (esta_cheio(p_vetor)) {
    redimensiona (p_vetor, p_vetor->capacidade * 2);
  }
  p_vetor->v[p_vetor->ocupacao] = i;
  p_vetor->ocupacao++;

}

void exibe_vetor(t_vetor *p_vetor, char *msg) {

  printf("\n%s\n", msg);
  printf("ocupacao = %d\n", p_vetor->ocupacao);
  printf("capacidade = %d\n", p_vetor->capacidade);
  printf("o vetor: ");
  
  for (int i = 0; i < p_vetor->ocupacao; i++)
    printf("%d ", p_vetor->v[i]);

  // for (int i = p_vetor->ocupacao; i < p_vetor->capacidade; i++);

  // printf("___");
  printf("\n");

}

int esta_vazio(t_vetor *p_vetor) {

  /* if(p_vetor->ocupacao == 0)
  return 1;
return 0;
*/
  return p_vetor->ocupacao == 0;

}

int remove_elemento(t_vetor *p_vetor, int *p_quem_sai) {
  if (esta_vazio(p_vetor)) return FRACASSO;

  p_vetor->ocupacao--;

  *p_quem_sai = p_vetor->v[p_vetor->ocupacao];
  if(p_vetor->capacidade >= CAPACIDADE_MINIMA * 2 && p_vetor->ocupacao <= p_vetor->capacidade / 4)
    redimensiona (p_vetor, p_vetor->capacidade / 2);
  return SUCESSO;

}

// Criar uma função para cada uma dessas tarefas
// 1. Criar uma função para limpar o vetor
// 2. Verificar se um elemento está ou não no vetor

void limpa_vetor (t_vetor *p_vetor) {
  p_vetor->ocupacao = 0;
}

int busca_elemento (t_vetor *p_vetor, int elemento) {
  
  for(int i = 0; i < p_vetor->ocupacao; i++) {
    if(elemento == p_vetor->v[i]) {
      return SUCESSO;
    }
  }
  return FRACASSO;


}