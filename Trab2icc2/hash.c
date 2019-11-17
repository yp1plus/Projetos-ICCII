#include "hash.h"
// TODAS FUNCOES USANDO "###" COMO STRING AINDA INEXISTENTE E "####" COMO STRING SUBSTITUTA (REMOVIDA)
// EX: tablelas todas inicializadas com "###"
// EX: na remocao, substituir palavra removida (e sua traducao) por "####"

char* word_alloc(void){
    char* word=NULL;

    word=(char*)malloc(sizeof(char)*TAMANHO_DA_PALAVRA+1);
    if(word==NULL){printf("Insuficient space in memory.\n");exit (1);}
    return word;
}

char** table_alloc(void){
    int i;
    char** table=NULL;

    table=(char**)malloc(sizeof(char*)*TAMANHO_DA_ENTRADA);
    if(table==NULL){printf("Insuficient space in memory.\n");exit (1);}

    for(i=0;i<TAMANHO_DA_ENTRADA;i++){
        table[i]=(char*)malloc(sizeof(char)*(TAMANHO_DA_PALAVRA+1)); //+1 para incluir o \0
        if(table[i]==NULL){printf("Insuficient space in memory.\n");exit (1);}
        strcpy(table[i],ENTRADA_VAZIA);
    }
return table;
}

int stringSum(char *key)
{
    // retorna um inteiro, soma dos caracteres da string
    int sum = 0;
    int i = 0;
    while(key[i] != '\0'){
        sum += key[i];
        i++;
    }
    return sum;
}

int hash_code(char **table, char *key)
{
    // conferindo se ja acertou um espaco vazio de primeira
    int guess = stringSum(key) % TAMANHO_DA_ENTRADA;
    if(!strcmp(table[guess], ENTRADA_VAZIA) || !strcmp(table[guess], ENTRADA_REMOVIDA)){
        return guess;
    }
    // caso nao acertou a primeira, realiza o procedimento de progressive overflow, olhando a proxima posicao
    while(1){
        guess = (guess+1)%TAMANHO_DA_ENTRADA;
        if(!strcmp(table[guess], ENTRADA_VAZIA) || !strcmp(table[guess], ENTRADA_REMOVIDA)){
            return guess;
        }
    }
}

int find_ht(char **table, char *key)
{
    // conferindo se achou de primeira
    int guess = stringSum(key) % TAMANHO_DA_ENTRADA;
    if(!strcmp(table[guess], key)){
        return guess;
    }
    // caso nao acertou a primeira, vai conferindo proximas ate percorrer todas 10000 possiveis entradas ou
    // ate encontrar uma entrada virgem (ENTRADA_VAZIA)
    int i = 0;
    for(i = 0; i < TAMANHO_DA_ENTRADA; i++){
        guess = (guess+1)%TAMANHO_DA_ENTRADA;
        // caso encontrar
        if(!strcmp(table[guess], key)){
            return guess;
        }
        // caso nao encontrar
        else if(!strcmp(table[guess], ENTRADA_VAZIA)){
            return HASH_INVALIDO;
        }
        else{
            continue;
        }
    }
    return HASH_INVALIDO;
}

void hash_insert(char **originalTable, char** translatedTable, char* originalWord, char* translatedWord){
    int index;

    //o endereço é dado a partir da palavra no idioma estrangeiro
    index=hash_code(translatedTable,translatedWord);

    strcpy(originalTable[index],originalWord);
    strcpy(translatedTable[index],translatedWord);

    return;
}

void hash_remove(char** originalTable,char** translatedTable,char* translatedWord){
    int guess,i;

    guess=stringSum(translatedWord) % TAMANHO_DA_ENTRADA;

    if(!strcmp(translatedTable[guess],translatedWord)){
        strcpy(translatedTable[guess],ENTRADA_REMOVIDA);
        strcpy(originalTable[guess],ENTRADA_REMOVIDA);
        return;
    }

    for(i=0;i<TAMANHO_DA_ENTRADA;i++){
        guess = (guess+1)%TAMANHO_DA_ENTRADA;

        if(!strcmp(translatedTable[guess],translatedWord)){
            strcpy(translatedTable[guess],ENTRADA_REMOVIDA);
            strcpy(originalTable[guess],ENTRADA_REMOVIDA);
            return;
        }
    }
    return;
}