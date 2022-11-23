#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char* name;
    struct node* next;
}node;

int main() {
    node* lista = (node*)malloc(sizeof(node));
    node* temp = (node*)malloc(sizeof(node));
    node* temp1 = (node*)malloc(sizeof(node));

    printf("\nInserisci un nome :");
    fflush(stdin);
    scanf("%s", lista->name);
    printf("\n%s", lista->name);
    lista-> next = NULL;

    printf("\nInserisci un nome :");
    fflush(stdin);
    scanf("%s", temp->name);
    printf("\n%s", temp->name);
    temp->next = NULL;

    lista->next = temp;
    printf("\n%s", lista->next->name);

    printf("\nInserisci un nome :");
    fflush(stdin);
    scanf("%s", temp1->name);
    printf("\n%s", temp1->name);
    temp1->next = NULL;

    lista->next->next = temp1;
    printf("\n%s", lista->next->next->name);


    free(lista);
    free(temp);
    free(temp1);
    return 0;
}
