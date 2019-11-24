#include "hash.h"

#define INITIAL_CHARACTERS 4

int main(void){
    char selector; /**< operador de inserção, de remoção ou de busca */
    int index; /**< posição da chave na tabela hash ou endereço invalido */
    char input[INITIAL_CHARACTERS]; /**< entrada considerando operador, ':' e espaços em branco */

    char* originalWord = word_alloc();
    char* translatedWord = word_alloc();

    char** originalTable = table_alloc();
    char** translatedTable = table_alloc();

    while(scanf("%s :", input) != EOF){
        selector = input[0];

        switch (selector){
            case 'A': case 'a': /**< operação de inserção */
                scanf("%s", originalWord);
                scanf("%s", translatedWord);
                hash_insert(originalTable, translatedTable, originalWord, translatedWord);
                break;
            case 'R': case 'r': /**< operação de remoção */
                scanf("%s", translatedWord);
                hash_remove(originalTable, translatedTable, translatedWord);
                break;
            case 'F': case 'f': /**< operação de busca */
                scanf("%s", translatedWord);
                
                index = find_ht(translatedTable, translatedWord);
                
                if(index == INVALID_HASH) 
                    printf("hein?\n");
                else 
                    printf("%s\n", originalTable[index]);
                
                break;
        }
    }

    return 0;
}
