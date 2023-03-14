#include <stdio.h>
#include  <stdlib.h>

typedef struct  node{
    char car;
    struct  node* next;                                     //indirizzo del nodo successivo
}Node;

int is_empty(Node *head){
    if(head == NULL) {
        return 1;
    }else {
        return 0;
    }
}

void push(Node **head, Node *elemento){
    if(is_empty(*head)){
        *head = elemento;
        elemento->next = NULL;
    }else{
        elemento->next = *head;
        *head = elemento;
    }
}

Node *pop(Node **head){
    Node *ret = *head;
    if(is_empty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }
    return ret;
}

void stampa(Node *l){
    int k=0;
    while (l!=NULL && k<10)
    {
        printf("\n%c",l->car);
        l=l->next;
        k++;
    }
}

int main() {
    char string [10];
    printf("\nInserisci una stringa :");
    scanf("%s", string);

    Node *pila;                                            //tipo a puntatore a node
    pila = NULL;

    for(int k = 0; k < 10; k++){
        if(string[k] == '(' || string[k] == '[' || string[k] == '{') {
            Node *carattere;
            carattere = (Node *) malloc(sizeof(Node));

            carattere->car = string[k];
            carattere->next = NULL;

            push(&pila, carattere);

        }else if(string[k] == ')' || string[k] == ']' || string[k] == '}'){
            Node *ret = pop(&pila);

            free(ret);
        }
    }
    if(pila == NULL){
        printf("\nParentesi chiuse correttamente.");
    }else{
        printf("Parentesi non chiuse : ");
        stampa(pila);
    }



    return 0;
}
