#ifndef HASH_H
#define HASH_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define HASH_INVALIDO 999999

#define ENTRADA_VAZIA "###"

#define ENTRADA_REMOVIDA "#####"

#define TAMANHO_DA_ENTRADA 10000

#define TAMANHO_DA_PALAVRA 512

//Aloca uma tabela de 10000 linhas por 513 colunas (10000 palavras de 512 caracteres)
char** table_alloc(void);

//Aloca uma palavra de 512 caracteres + \0
char* word_alloc(void);

// Retorna o indice correto da tabela que a chave deve ser inserida (a funcao de hash)
// parametros: a tabela e a chave
int hash_code(char** table, char* key);

// Retora indice da chave na tabela se encontrar, ou posicao de hash invalida caso contrario (999999)
// parametros: a tabela e a chave
int find_ht(char** table, char* key);

// Insere uma dado par de palavras nas tabelas de hash baseado na palavra traduzida
// parametros: a tabela de palavras originais, a tabela de palavras traduzidas, a palavra original e a palavra traduzida.
void hash_insert(char** originalTable, char** translatedTable, char* originalWord, char* translatedWord);

// Remove um dado par de palavra das trabelas de hash baseado na palavra traduzida
// parametros: a tabela de paloavras originais, a tabela de palavras traduzidas, a palavra traduzida chave
void hash_remove(char** originalTable,char** translatedTable,char* translatedWord);

#endif