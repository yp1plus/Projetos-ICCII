#ifndef HASH_H
#define HASH_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// retorna o indice correto da tabela que a chave deve ser inserida (a funcao de hash)
// parametros: a tabela e a chave
int hash_code(char **table, char *key);

// retora indice da chave na tabela se encontrar, ou posicao de hash invalida caso contrario (999999)
// parametros: a tabela e a chave
int find_ht(char **table, char *key);

// VAO COLOCANDO FUNCOES AQUI E IMPLEMENTANDO NO .C
// FUNCOES EM INGLES, COMENTARIOS EM PORTUGUES
// EH PEDIDO QUE PELO MENOS COMENTAMOS O QUE A FUNCAO FAZ E OS PARAMETROS, COMO ILUSTRADO ACIMA

#endif