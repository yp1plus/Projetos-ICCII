#include <stdio.h>

/*
  Para resolver esse problema, percebemos que é mais fácil criar um vetor de 3
  elementos, os 3 maiores valores, que inicialmente são todos 0. Assim, quando
  o programa recebe uma entrada, ele verifica se essa entrada é maior do que algum
  dos 3 valores que já estão no vetor. Caso seja maior, o programa substitui o
  menor elemento do vetor pela nova entrada. Ao final da execução, o programa 
  ordena o vetor em ordem decrescente através da função "ordena".
*/

void ordena(int maisRicos[3]){
  int aux;
  if(maisRicos[0] < maisRicos[1]){
    aux = maisRicos[0];
    maisRicos[0] = maisRicos[1];
    maisRicos[1] = aux;
  }
  if(maisRicos[1] < maisRicos[2]){
    aux = maisRicos[1];
    maisRicos[1] = maisRicos[2];
    maisRicos[2] = aux;
  }
  if(maisRicos[0] < maisRicos[2]){
    aux = maisRicos[0];
    maisRicos[0] = maisRicos[2];
    maisRicos[2] = aux;
  }
  if(maisRicos[0] < maisRicos[1]){
    aux = maisRicos[0];
    maisRicos[0] = maisRicos[1];
    maisRicos[1] = aux;
  }
}

int main(){
  int maisRicos[3] = {0, 0, 0};
  int tamanho;
  int x;
  int indiceDoMenosRicoEntreOsMaisRicos;

  scanf("%d", &tamanho);
  for(int i = 0; i < tamanho; i++){
    scanf("%d", &x);

    for(int j = 0; j < 3; j++){ // percorre o vetor dos mais ricos para verificar se existe um valor menor do que a nova entrada
      if(x > maisRicos[j]){
        indiceDoMenosRicoEntreOsMaisRicos = 0; // inicialmente, começa a comparação pelo primeiro elemento
        for(int k = 1; k < 3; k++)
          if(maisRicos[indiceDoMenosRicoEntreOsMaisRicos] > maisRicos[k]) // verifica qual o menor elemento do vetor para substituí-lo
            indiceDoMenosRicoEntreOsMaisRicos = k;

        maisRicos[indiceDoMenosRicoEntreOsMaisRicos] = x;
        break;
      }
    }

    ordena(maisRicos);

    if(i < 2) printf("-1\n");
    else printf("%d %d %d\n", maisRicos[0], maisRicos[1], maisRicos[2]);
  }

  return 0;
}