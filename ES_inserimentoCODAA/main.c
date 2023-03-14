#include <stdlib.h>
#include <stdio.h>
#include <string.h>

 typedef struct  node{
    int  valore;            //tutti i dati da salvare in ogni nodo della lista
    char nome[20];
    struct  node* next;                                     //indirizzo del nodo successivo
}Node;

 void stampa(Node *l){  //si passa la lista come parametro

    int k=0;
    //printf("STAMPA CON PROC: \n");
    while (l!=NULL && k<5)                                  //puntatore alla lista diversa da NULL e dimensione minore di 5
    {
        printf("\n%s - %d \n",l->nome, l->valore);          //stampa i dati
        l=l->next;                                          //assegna ad l il campo successivo, all'ultima iterazione assegna il campo NULL ed esce dal ciclo
        k++;
    }
}

 void inserimento(Node **head, Node *element){
    Node *curr=*head;
    Node *prev = NULL;

    while (curr != NULL){
        if (element->valore >= curr->valore)
            break;
        prev = curr;
        curr = curr->next;
    }

    if (prev == NULL){
        *head = element;
    }else {
        prev->next = element;
    }

    element->next=curr;
}

 void cancellaNodo(int k, Node *element){ //passo il contatore dal do while del main e il nodo da cancellare
    Node *tmp;
    tmp = (Node*)malloc(sizeof(Node)); //nodo temporaneo
    if(k > 5){ //se la dimensione sfora il limite (5)
        while(element->next->next == NULL){  //se il puntatore al nodo successivo dell'elemento è null
            tmp->next = element->next->next; //il valore viene salvato nel nodo tmp
            element->next = tmp->next; //in element di next
            free(element); //disalloca l'ultimo elemento
        }
    }
}

  int  main(){
    int n;
    char nom[20];
    Node *lista;                                            //tipo a puntatore a node
    lista = NULL;
    int k = 0;

    do {
        printf("Inserisci il valore del viodeogioco o -1 per  terminare : \n");
        scanf("%d", &n);

        if (n != -1) {
            printf("Inserisci il nome : \n");
            fflush(stdin);
            gets(nom);

            Node *elem;
            elem = (Node *) malloc(sizeof(Node));

            elem->valore = n;
            strcpy(elem->nome, nom);
            elem->next = NULL;

            inserimento(&lista, elem);
            cancellaNodo(k, elem);
            k++;
        }
    }while (n >= 0);
        stampa(lista);

        return 0;
    }
