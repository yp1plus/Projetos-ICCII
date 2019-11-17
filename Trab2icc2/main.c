#include "hash.h"

int main(void){

    /* COISAS IMPORTANTES: */

    // as tabelas de hash (duas matrizes de char) devem ser alocadas com capacidade de 
    // armazenar exatamente 10000 strings cada - cada string com 512 caracteres (tamanho 513 incluindo o '\0').
    // a alocacao e liberacao pode ser feita dentro da main mesmo ou, se preferir, como funcao implementada no hash.c

    // uma matriz armazena as palavras estrangeiras e, a outra, nos indices correspondentes, as traducoes.
    // PRECISAM ser inicializadas com TODOS OS VALORES INICIAIS DE STRING SENDO "###"

    // obs. quando for passar como parametro para as funcoes, passar a matriz que contem as PALAVRAS ESTRANGEIRAS

    char selector = 'Z';
    char aux= 'Z';
    
    int index;

    char input[4];
    char* originalWord=NULL;
    char* translatedWord=NULL;

    char** originalTable=NULL;
    char** translatedTable=NULL;

    originalTable=table_alloc();
    translatedTable=table_alloc();

    originalWord=word_alloc();
    translatedWord=word_alloc();

    while(selector!='Q'){
        printf("%c",selector);
        scanf("%s",input);
        selector=input[0];

        switch (selector)
        {
        case 'A':
            printf("Case A\n");
            scanf("%s",originalWord);
            scanf("%s",translatedWord);
            hash_insert(originalTable,translatedTable,originalWord,translatedWord);
            break;
        
        case 'R':
            printf("Case R\n");
            scanf("%s",translatedWord);
            hash_remove(originalTable,translatedTable,translatedWord);
            break;

        case 'F':
            printf("Case F\n");
            scanf("%s",translatedWord);
            index=find_ht(translatedTable,translatedWord);
            if(index==HASH_INVALIDO) printf("hein?\n");
            else printf("%s\n",originalTable[index]);
            break;
        
        case 'a':
            printf("Case a\n");
            scanf("%s",originalWord);
            scanf("%s",translatedWord);
            hash_insert(originalTable,translatedTable,originalWord,translatedWord);
            break;
        
        case 'r':
            printf("Case r\n");
            scanf("%s",translatedWord);
            hash_remove(originalTable,translatedTable,translatedWord);
            break;

        case 'f':
            printf("Case f\n");
            scanf("%s",translatedWord);
            index=find_ht(translatedTable,translatedWord);
            if(index==HASH_INVALIDO) printf("hein?\n");
            else printf("%s\n",originalTable[index]);
            break;    

        default:
            break;
        }
        printf("%c\n",selector);
        //selector='Z';
    }



    return 0;
}