//Escreva uma função que recebe um vetor com N (0 < N < 17000) letras As e Bs e, por meio de trocas, move todos os As para o início do vetor. 
//Sua função deve consumir tempo linear (proporcional ao tamanho do vetor,ou seja, a N).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordenaA_B(char* V);

void ordenaA_B(char* V){
    int i;
    int tam=strlen(V);
    int contA=0, existeB=0;
    

    for(i=0;i<tam;i++){
        if(V[i]=='A'){
        if (existeB==1){
            V[contA]='A';
            V[i]='B';
        }
        contA++;
        } 
        else existeB=1;
    }
}

int main(void){

char V[17001];

scanf("%s",V);

    ordenaA_B(V);

printf("%s\n",V);

    return 0;
}