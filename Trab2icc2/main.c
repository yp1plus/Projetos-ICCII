#include "hash.h"

int main(void){

    /* COISAS IMPORTANTES: */

    // as tabelas de hash (duas matrizes de char) devem ser alocadas com capacidade de 
    // armazenar exatamente 10000 strings cada - cada string com 512 caracteres (tamanho 513 incluindo o '\0').
    // a alocacao e liberacao pode ser feita dentro da main mesmo ou, se preferir, como funcao implementada no hash.c

    // uma matriz armazena as palavras estrangeiras e, a outra, nos indices correspondentes, as traducoes.
    // PRECISAM ser inicializadas com TODOS OS VALORES INICIAIS DE STRING SENDO "###"

    // obs. quando for passar como parametro para as funcoes, passar a matriz que contem as PALAVRAS ESTRANGEIRAS

    return 0;
}