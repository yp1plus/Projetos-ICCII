#include "hash.h"

int main(void){


    char selector = 'Z';
    char aux = 'Z';
    
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
        scanf("%s :",input);
        selector=input[0];

        switch (selector)
        {
        case 'A':
            scanf("%s",originalWord);
            scanf("%s",translatedWord);
            hash_insert(originalTable,translatedTable,originalWord,translatedWord);
            break;
        
        case 'R':
            scanf("%s",translatedWord);
            hash_remove(originalTable,translatedTable,translatedWord);
            break;

        case 'F':
            scanf("%s",translatedWord);
            index=find_ht(translatedTable,translatedWord);
            if(index==HASH_INVALIDO) printf("hein?\n");
            else printf("%s\n",originalTable[index]);
            break;
        
        case 'a':
            scanf("%s",originalWord);
            scanf("%s",translatedWord);
            hash_insert(originalTable,translatedTable,originalWord,translatedWord);
            break;
        
        case 'r':
            scanf("%s",translatedWord);
            hash_remove(originalTable,translatedTable,translatedWord);
            break;

        case 'f':
            scanf("%s",translatedWord);
            index=find_ht(translatedTable,translatedWord);
            if(index==HASH_INVALIDO) printf("hein?\n");
            else printf("%s\n",originalTable[index]);
            break;    

        default:
            break;
        }
    }



    return 0;
}