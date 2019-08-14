#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Elemento_{
    int numero;
    struct Elemento_ * proximo;
    struct Elemento_ * anterior;
}Elemento;

typedef struct Lista_{
    int tamanho;
    Elemento * cabeca;
    Elemento * cauda;
}Lista;

void inicia_lista(Lista * lista){
    lista -> tamanho = 0;
    lista -> cabeca = NULL;
    lista -> cauda = NULL;
    
    return;
}

void inserir_elemento(Lista *lista, int numero){
    
    Elemento * novo_elemento;
    if((novo_elemento = (Elemento*) malloc(sizeof(Elemento))) == NULL){
        printf("Sem espaço para alocar elemento!\n");
        return;
    }

    novo_elemento -> numero = numero;

    if(lista -> tamanho == 0){ // se a lista estiver vazia, o novo elemento é head e tail da lista
        lista -> cabeca = novo_elemento;
        lista -> cauda = novo_elemento;
        novo_elemento -> proximo = NULL;
        novo_elemento -> anterior = NULL;
    }
    else{
        Elemento * aux = lista -> cabeca;
        while(aux != NULL){ // enquanto o auxiliar não aponta para nulo
            if(numero  <= aux -> numero){ // se for menor do que o atual número da lista...
                novo_elemento -> proximo = aux;
                novo_elemento -> anterior = aux -> anterior;
                if(aux != lista -> cabeca)
                    aux -> anterior -> proximo = novo_elemento;
                else
                    lista -> cabeca = novo_elemento;     
                aux -> anterior = novo_elemento;
                break;
            }
            else if(aux -> proximo != NULL){ // se o próximo não for o fim...
                aux = aux -> proximo;
            }
            else{ // se o próximo for a cauda
                novo_elemento -> anterior = lista -> cauda;
                novo_elemento -> proximo = NULL;
                lista -> cauda -> proximo = novo_elemento;
                lista -> cauda = novo_elemento;
                break;
            }       
        }
    }    
    lista -> tamanho ++;
    return;
}

void desaloca_lista(Lista *lista){
    Elemento ** aux = &(lista -> cauda);
    while(lista -> tamanho != 0){
        free(*aux);
        aux = &((*aux) -> anterior);
        lista -> tamanho --;
    }
    return;
}

void imprimir_lista(Lista * lista){
    Elemento *aux = lista -> cabeca;
    while(aux != NULL){
        printf("%d ", aux -> numero);
        aux = aux -> proximo;
    }
    printf("\n");
    return;
}

int inteiros_em_string(char * string){
    int i = 0, contador = 0;
    while(i <= strlen(string)){
        if(string[i] == ' ')
            contador ++;
        i++;
    }
    return contador + 1;
}

int * tratamento_de_dados(char *string, int contador){
    int * vetor;
    switch(contador){
        case 5:
            if((vetor = (int*) malloc(6 * sizeof(int))) == NULL){
                printf("Não foi possível alocar.\n");
                return NULL;
            }
            vetor[0] = 5; // o primeiro elemento armazena o tamanho do vetor
            sscanf(string, "%d %d %d %d %d", &vetor[1],  &vetor[2],  &vetor[3], &vetor[4], &vetor[5]);
            break;
        case 6:
            if((vetor = (int*) malloc(7 * sizeof(int))) == NULL){
                    printf("Não foi possível alocar.\n");
                    return NULL;
            }
            vetor[0] = 6; // o primeiro elemento armazena o tamanho do vetor
            sscanf(string, "%d %d %d %d %d %d", &vetor[1],  &vetor[2],  &vetor[3], &vetor[4], &vetor[5], &vetor[6]);
            break;
        case 7:
            if((vetor = (int*) malloc(8 * sizeof(int))) == NULL){
                    printf("Não foi possível alocar.\n");
                    return NULL;
            }
            vetor[0] = 7; // o primeiro elemento armazena o tamanho do vetor
            sscanf(string, "%d %d %d %d %d %d %d", &vetor[1],  &vetor[2],  &vetor[3], &vetor[4], &vetor[5], &vetor[6], &vetor[7]);
            break;
    }
    return vetor;
}
int main(){
    Lista lista;
    char string[20];
    int contador;
    int i;
    int * vetor;

    inicia_lista(&lista);
    fgets(string, 20, stdin);
    contador = inteiros_em_string(string);
    vetor = tratamento_de_dados(string, contador);
    for(i = 1; i <= vetor[0]; i++)
        inserir_elemento(&lista, vetor[i]);
    imprimir_lista(&lista);
    desaloca_lista(&lista);
    free(vetor);
    return 0;
}