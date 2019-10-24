#include <stdio.h>
#include <stdlib.h>

// A função imprime_vetor recebe um vetor e seu respectivo tamanho e imprime para o usuário os elementos desse vetor e pula linha.
void imprime_vetor(int* A,int tam){
    int i;

    for(i=0;i<tam;i++){
        printf("%d ",A[i]);
    }

    printf("\n");
    return;
}

// Função de implementação do insertion_sort que ordena um dado vetor inserindo elementos no começo do vetor de forma ordenada
void insertion_sort(int *V, int n) {
    int i;
    int j;
    int temp;

// Percorre todo o vetor
  for (i = 0; i < n; i++) {
     j = i;
// Começando a partir da parte ordenada, faz a inserção do menor elemento na primeira posição atualmente não ordenada.
    while (j > 0 && V[j - 1] > V[j]) {
      temp = V[j];
      V[j] = V[j - 1];
      V[j - 1] = temp;
      j--;
    }
  }
}

// Função merge, que recebe dois vetores ordenados e seus respectivos tamanhos (t1 e t2) e une-os em um vetor ordenado de tamanho t1+t2.
void merge(int *A, int tam1, int *B, int tam2) {
  int* tmp=NULL;
  int i = 0;
  int j = 0;
  int k = 0;

// Aloca espaço para o vetor temporário
tmp=(int*)malloc(sizeof(int)*(tam1 + tam2));
if(tmp==NULL){printf("Deu erro na alocação meu filho");return;}

// Enquanto os dois vetores elementos possuem elementos, estes são comparados e inseridos no vetor temporário
  while (j < tam1 && k < tam2) {
    if (A[j] < B[k]) {
      tmp[i++] = A[j++];
    } else {
      tmp[i++] = B[k++];
    }
  }
// Assim que um deles acaba, os elementos restantes são inseridos no final do vetor;
  while (j < tam1) {
    tmp[i++] = A[j++];
  }

  while (k < tam2) {
    tmp[i++] = B[k++];
  }
// Devolve para o vetor original o vetor ordenado
  for (i = 0; i < tam1 + tam2; i++) {
    A[i] = tmp[i];
  }
}

// Função que recebe um vetor de inteiros desordenado, seu tamanho e a partir de qual momento deve ser chamado o insertion sort e o ordena através do metodo de insertion sort e merge sort.
void insertion_merge(int* A, int k, int tam){
    // Caso base: quando o tamanho do vetor é <= ao necessário para utilizar o insertion sort, este é chamado e o vetor é impresso
  if (tam <= k) {
    insertion_sort(A,tam);
    imprime_vetor(A,tam);
    return;
  }
// Cria os tamanhos para dividir o vetor em 2 metades e os divide chamando recursivamente a função insertion_merge
  int tam1 = tam / 2;
  int tam2 = tam - tam1;

  insertion_merge(A, k, tam1);
  insertion_merge(A + tam1, k, tam2);

// Com os vetores divididos (e já ordenados pelo insertion), resta apenas juntá-los através da função merge e imrpimir o resultado
  merge(A,tam1,A+tam1,tam2);

  imprime_vetor(A,tam);

  return;
}
// A Main, apenas recebe a entrade de tamanho, aloca um vetor deste tamanho, recebe seus elementos e o número k para o insertion sort.
int main (void){

    int* V=NULL;
    int tam;
    int i,k;

    scanf("%d",&tam);

    V=(int*)malloc(sizeof(int)*(tam));
    if(V==NULL){printf("Deu erro na alocação meu filho");return 0;}

    for(i=0;i<tam;i++){
        scanf("%d",&V[i]);
    }

    scanf("%d",&k);

    insertion_merge(V,k,tam);

    return 0;
}