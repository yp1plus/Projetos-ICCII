/* Somsom - 2019 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int data;
    struct _Node *next;
}Node;

typedef Node* List;

List makeList(){
    List L = NULL;
    return L;
}

void freeList(List L){
    if(L == NULL){return;}
    List aux1 = L;
    List aux2 = L -> next;
    while(aux2 != NULL){
        free(aux1);
        aux1 = aux2;
        aux2 = aux2 -> next;
    }
    free(aux1);
}

void pushList(List *L, int n){

    if((*L) == NULL){
        (*L) = (List)malloc(sizeof(Node));
        (*L) -> data = n;
        (*L) -> next = NULL;
        return;
    }

    List *insertion;
    insertion = (List*)malloc(sizeof(*insertion));
    (*insertion) = (List)malloc(sizeof(Node));

    if((*L) -> next == NULL){
        if(((*L) -> data) > n){
            (*insertion) -> data = (*L) -> data;
            (*insertion) -> next = NULL;
            (*L) -> data = n;
            (*L) -> next = (*insertion);
            return;
        }
        else{
            (*insertion) -> data = n;
            (*insertion) -> next = NULL;
            (*L) -> next = (*insertion);
            return;
        }
    }

    List aux = (*L);

    if(((*L) -> data) > n){
            (*insertion) -> data = (*L) -> data;
            (*insertion) -> next = (*L) -> next;
            (*L) -> data = n;
            (*L) -> next = (*insertion);
            return;
    }

    while((aux -> next != NULL) && (aux -> next -> data < n)){
        aux = aux -> next;
    }

    (*insertion) -> data = n;
    (*insertion) -> next = aux -> next;
    aux -> next = (*insertion);
}

void printList(List L){
    List aux = (List)malloc(sizeof(Node));
    aux = L;
    while(aux != NULL){
        printf("%d ", aux -> data);
        aux = aux -> next;
    }
}



int main(void){

    List L = makeList();

    int quantos;
    scanf("%d", &quantos);

    int i, insercao;
    for(i = 0; i < quantos; i++){
        scanf("%d", &insercao);
        pushList(&L, insercao);
    }

    printList(L);
    freeList(L);

    return 0;
}