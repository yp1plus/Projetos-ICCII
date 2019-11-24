#ifndef HASH_H
    #define HASH_H

    /*****************************************************************************//**
    * Dicionario de Sinonimos com Tabela Hash
    *
    * É possivel inserir palavras com até 512 caracteres e suas respectivas traduções.
    * As palavras podem ter digitos numericos e caracteres especiais, desde que os
    * ultimos nao iniciem a palavra. A entrada máxima é de 10 mil palavras. 
    * Ainda é possível remover palavras e buscar a tradução das palavras inseridas.
    *
    * Para inserir, use o operador a ou A seguido de : e, sequencialmente, separadas 
    * por espaço, a palavra no idioma original e a palavra no idioma estrangeiro. 
    * A entrada é do tipo a : dog ogday
    *
    * Para buscar, use o operador f ou F seguido de : e digite a palavra no idioma 
    * estrangeiro. A entrada é do tipo f : ogday
    *
    * Para remover, use o operador r ou R seguido de : e digite a palavra no idioma
    * estrangeiro. A entrada é do tipo r : ogday
    ********************************************************************************/

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define INVALID_HASH 999999 /**< valor arbitrário maior do que dez mil que determina hash inválido */

    #define EMPTY_INPUT "###" /**< simbolo diferente dos tipos de entradas para indicar string vazia */

    #define INPUT_REMOVED "#####" /**< simbolo diferente dos tipos de entradas para indicar string vazia apos remoção */

    #define INPUT_SIZE 10000 /**< maximo numero de pares de palavras determinado */

    #define WORD_SIZE 512 /**< maximo numero de caracteres por palavra determinado */

    #define ZERO_BAR 1 /**< unidade que representa o caractere '\0' */

    /*! Aloca espaço na heap para uma tabela hash com, no máximo, 10 mil palavras e retorna */
    char** table_alloc(void);

    /*! Aloca espaço na heap para uma palavra de, no máximo, 512 caracteres e retorna */
    char* word_alloc(void);

    /*! Retorna um inteiro, o codigo hash da string key na tabela hash, com overflow progressivo */
    int hash_code(char** table, char* key);

   /*! Retorna um inteiro, a posição da string key na tabela hash, ou um endereço inválido, caso ela não exista */
    int find_ht(char** table, char* key);

    //*! Insere a palavra original e a traduzida nas suas respectivas tabelas */
    void hash_insert(char** originalTable, char** translatedTable, char* originalWord, char* translatedWord);

    //!  Remove a palavra original e a traduzida das suas respectivas tabelas. 
    /*!
      Note que, diferente da inserção, na remoção só é necessária a palavra traduzida, 
      uma vez que o dado já existe e o indice é o mesmo.
    */
    void hash_remove(char** originalTable, char** translatedTable, char* translatedWord);
#endif
