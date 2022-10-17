/*Creare un file .csv con Cognome, Nome, Nascita (annomesegiorno attaccato INT)
 scorro file Fgets e Strtok
 Stampare in ordine decrescente con puntatori e malloc*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 1024

typedef struct Dati{
    char* Cognome;
    char* Nome;
    int Nascita;
}Dati;

int sizeFP(FILE*fp){ //utilizza la funzione fseek per contare la dimensione del file (trovato su forum)
    int prev=ftell(fp);
    fseek(fp, 0L, SEEK_END);
    int sz=ftell(fp);
    fseek(fp,prev,SEEK_SET);
    return sz;
}

void bubbleSORT(Dati *pi, int n) {
    int i, k;
    int temp;
    for(i = 0; i<n; i++) {
        for(k = 0; k<i; k++) {
            if((pi + k)->Nascita > (pi + i)->Nascita) {
                temp = (pi + k)->Nascita;
                (pi + k)->Nascita = (pi + i)->Nascita;
                (pi + i)->Nascita = temp;
            }
        }
    }
}

void stampaVET(Dati *pi, int n){

    int i;
    for(i = 0; i<n; i++) {
        printf("\n%d ", (pi + i)->Nascita);
    }
}

int main() {
    Dati *pi;
    int n;
    int k = 0;

    char riga[LUNG];
    FILE *fp;
    fp = fopen("dati.csv", "r");
    if (fp == NULL) {
        printf("\nIl file non esiste");
        return 1;
    } else {
        printf("\nsono dentro");

        n = sizeFP(fp);
        pi = (Dati *) malloc(n * sizeof(Dati));

        while (fgets(riga, LUNG, fp)) {
            (pi + k)->Cognome = strtok(riga, ",");
            (pi + k)->Nome = strtok(NULL, ",");
            (pi + k)->Nascita = atoi(strtok(NULL, ","));
            printf("\n%d %s %s", (pi + k)->Nascita, (pi + k)->Nome, (pi + k)->Cognome);

            k++;
        }

        bubbleSORT(pi, k);
        printf("\nClassifica :");
        stampaVET(pi, k);

        fclose(fp);
        free(pi);

    }
    return 0;
}
