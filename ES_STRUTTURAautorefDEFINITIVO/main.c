/*crea  una  lista e la  stampa*/
/*di una lista so solo che ha una testa (head) e una coda (tail)*/
#include  <stdio.h>
#include  <stdlib.h>
typedef struct  node{
    int  valore;
    struct  node* next;
}Node;

void insertHead(Node **head, int new_valore){
    Node* new_testa = (Node*)malloc(sizeof (Node));

    new_testa->valore = new_valore; //carico il nuovo valore nel Node nuovo
    new_testa->next = (*head); // il next punta alla testa attuale

    (*head) = new_testa; //imposto la testa nuova
}

void stampa(Node *l){
    printf("numeri  inseriti: ");
    while (l!=NULL)
    {
        printf("\n%d - %p",l->valore, l->next);
        l=l->next;
    }
}

int tot(Node *l){
    if(l!=NULL)
    {
        return tot(l ->next)+1;
    }
    return 0;
}

int  main()
{
    int n;
    Node* lista;
    Node* l;
    lista=NULL;

    do
    {
        printf("Inserisci  un  naturale o  -1 per  terminare : \n");
        scanf("%d",&n);
        if (n>=0)
        {
            if (lista==NULL) /*  prima  iterazione  */
            {
                lista = (Node*)malloc(sizeof(Node));
                l = lista;
            }
            else
            {
                l->next = (Node*)malloc(sizeof(Node));
                l = l->next; // modo per ciclare sulle liste = assegno l'indirizzo della successiva
            }
            l->valore = n;
            l->next = NULL;
        }
    } while (n>=0);

    l=lista;
    stampa(l);
    Node* head = (Node*)malloc(sizeof(Node));
    head = NULL;
    insertHead(&head, 12);
    stampa(l);
    printf("\n");
    int j = tot(l);

    printf("\nIl numero degli elementi e' : %d", j);

    return  0;
    }
