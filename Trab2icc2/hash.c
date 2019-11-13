#include "hash.h"
// TODAS FUNCOES USANDO "###" COMO STRING AINDA INEXISTENTE E "#####" COMO STRING SUBSTITUTA (REMOVIDA)
// EX: tablelas todas inicializadas com "###"
// EX: na remocao, substituir palavra removida (e sua traducao) por "#####"


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
    int guess = stringSum(key) % 10000;
    if(!strcmp(table[guess], "###") || !strcmp(table[guess], "#####")){
        return guess;
    }
    // caso nao acertou a primeira, realiza o procedimento de progressive overflow, olhando a proxima posicao
    while(1){
        guess = (guess+1)%10000;
        if(!strcmp(table[guess], "###") || !strcmp(table[guess], "#####")){
            return guess;
        }
    }
}

int find_ht(char **table, char *key)
{
    // conferindo se achou de primeira
    int guess = stringSum(key) % 10000;
    if(!strcmp(table[guess], key)){
        return guess;
    }
    // caso nao acertou a primeira, vai conferindo proximas ate percorrer todas 10000 possiveis entradas ou
    // ate encontrar uma entrada virgem ("###")
    int i = 0;
    for(i = 0; i < 10000; i++){
        guess = (guess+1)%10000;
        // caso encontrar
        if(!strcmp(table[guess], key)){
            return guess;
        }
        // caso nao encontrar
        else if(!strcmp(table[guess], "###")){
            return 999999;
        }
        else{
            continue;
        }
    }
    return 999999;
}