#include "hash.h"

/*! Aloca espaço na heap para uma palavra de, no máximo, 512 caracteres e retorna */
char* word_alloc(void){
    char* word = NULL;

    word = (char*) malloc(sizeof(char)*(WORD_SIZE + ZERO_BAR));
    
    if(word == NULL){
        printf("Insuficient space in memory.\n");
        exit(1);
    }
    
    return word;
}

/*! Aloca espaço na heap para uma tabela hash com, no máximo, 10 mil palavras e retorna */
char** table_alloc(void){
    char** table = NULL;
    int i = 0;

    table = (char**) malloc(sizeof(char*)*INPUT_SIZE);
    
    if(table == NULL){
        printf("Insuficient space in memory.\n");
        exit (1);
    }

    for(i = 0; i < INPUT_SIZE; i++){
        table[i] = word_alloc();

        strcpy(table[i], EMPTY_INPUT); /**< inicializa cada palavra com indicador de vazio */
    }
    
    return table;
}

/*! Retorna um inteiro, a soma dos caracteres em ASCII da string key */
int stringSum(char *key){
    int sum = 0;
    int i = 0;
    
    while(key[i] != '\0'){
        sum += key[i++];
    }
    
    return sum;
}

/*! Retorna um inteiro, o codigo hash da string key na tabela hash, com overflow progressivo */
int hash_code(char **table, char *key){
    int guess = stringSum(key) % INPUT_SIZE; /**< função hash */

    while(1){
        if(!strcmp(table[guess], EMPTY_INPUT) || !strcmp(table[guess], INPUT_REMOVED) || !strcmp(table[guess], key)){
            return guess;
        }

        guess = (guess + 1) % INPUT_SIZE;
    }
}

/*! Retorna um inteiro, a posição da string key na tabela hash, ou um endereço inválido, caso ela não exista */
int find_ht(char **table, char *key){
    int code = stringSum(key);
    int guess;
    int i = 0;

    /**
     * Percorre os indices da tabela até encontrar a chave ou um campo vazio.
     * No pior caso, percorre todo o tamanho da entrada.
     */
    for(i = 0; i < INPUT_SIZE; i++){
        guess = (code + i) % INPUT_SIZE;
    
        if(!strcmp(table[guess], key)){
            return guess;
        }
        
        else if(!strcmp(table[guess], EMPTY_INPUT)){
            return INVALID_HASH;
        }
    }
    
    return INVALID_HASH;
}

/*! Insere a palavra original e a traduzida nas suas respectivas tabelas */
void hash_insert(char **originalTable, char** translatedTable, char* originalWord, char* translatedWord){
    int index = hash_code(translatedTable, translatedWord); /**< o codigo é gerado a partir da palavra traduzida */

    strcpy(originalTable[index], originalWord);
    strcpy(translatedTable[index], translatedWord);

    return;
}

//!  Remove a palavra original e a traduzida das suas respectivas tabelas. 
/*!
  Note que, diferente da inserção, na remoção só é necessária a palavra traduzida, 
  uma vez que o dado já existe e o indice é o mesmo.
*/
void hash_remove(char** originalTable, char** translatedTable, char* translatedWord){
    int index = find_ht(translatedTable, translatedWord);
    
    if(index != INVALID_HASH){
        strcpy(translatedTable[index], INPUT_REMOVED);
        strcpy(originalTable[index], INPUT_REMOVED);
    }

    return;
}
