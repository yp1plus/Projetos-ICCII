/*Make by Yure Pablo*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
    char pais[50];
    char mnsg[100];
} LISTA;

char *buscarPais(char *pais, int inicio, int fim, LISTA* traducoes){
    if (inicio > fim) return NULL;
    else{
        int meio = (inicio + fim)/2;
        if (strcmp(traducoes[meio].pais, pais) == 0) return traducoes[meio].mnsg;
        if (strcmp(traducoes[meio].pais, pais) < 0) 
            return buscarPais(pais, meio+1, fim, traducoes);
        else
            return buscarPais(pais, inicio, meio-1, traducoes);
    }
}

int main(void){
    LISTA *traducoes = NULL;
    int N = 0, M = 0;
    int i = 0;

    scanf("%d", &N);

    traducoes = (LISTA *) malloc(N*sizeof(LISTA));

    if (traducoes == NULL) exit(1);

    fflush(stdin);

    for (i = 0; i < N; i++){
        scanf("%[^\n\r]s", traducoes[i].pais); 
        fflush(stdin);
        
    }

    for (i = 0; i < N; i++){
        scanf("%[^\n\r]s", traducoes[i].mnsg);
        fflush(stdin);
    }

    scanf("%d", &M);

    fflush(stdin);
    
    char pais[50]; char *mnsg;
    for (i = 0; i < M; i++){
        scanf("%[^\n\r]s", pais);
        mnsg = buscarPais(pais, 0, N, traducoes);
        if (mnsg == NULL)
           printf("--- NOT FOUND ---\n");
        else
           printf("%s\n", mnsg);
        fflush(stdin);
    }

    return 0;
}