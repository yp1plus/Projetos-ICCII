#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int value;
    struct cel next;
} celula;

celula *insert(celula *origin, int value){
    celula *aux = origin;

    if (origin == NULL)
    {
        origin->value = value;

        return origin;
    }

    while(origin != NULL && origin->value < value)
    {
        origin = origin->prox;
    }

    for (origin)
}

int main(void){
    celula *origin;
    origin = NULL;
    int value;

    scanf("%d", &value);

    insert(origin, value);
}