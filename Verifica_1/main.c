#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LUNG 40
#define TOTALE 2200

typedef struct{//struttura per inserire i dati degli alunni
    char* cognome;
    int quota;
}Persona;

int contarighe(){//funzione per contare le righe del file
    FILE *fp;

    char riga[LUNG];
    int cont=0;//contatore per contare il numero delle righe

    fp=fopen("4AROB_GITA.csv", "r");//apertura file

    while(fgets(riga, LUNG, fp)){//leggo ogni riga
        cont++;//ogniriga letta aumento il contatore
    }

    return cont;//restituisco il numero di righe
}

int contaIncassi(){
    FILE *fp;

    char riga[LUNG];

    char tmp1[LUNG];
    char tmp2[LUNG];//variabili temporanee per data e cognome

    int tot=0;//incasso totale

    fp=fopen("4AROB_GITA.csv", "r");//apertura file

    while(fgets(riga, LUNG, fp)){//leggo ogni riga

        strdup(strtok(riga, ";"));//assegno ad una temporanea la data
        strdup(strtok(NULL, ";"));//assegno ad una temporanea il cognome
        tot=tot+atoi(strtok(NULL,";"));//sommo l'incasso della riga al totale
    }

    return tot;//restituisco il numero di righe
}

void verificaQuota(Persona *io){
    io->cognome="serra";
    io->quota=0;

    FILE *fp;

    char riga[LUNG];
    char cognome[LUNG];

    int tmp=0;

    fp=fopen("4AROB_GITA.csv", "r");//apertura file

    while(fgets(riga, LUNG, fp)){//leggo ogni riga
        tmp=0; //inizializzo tmp a 0

        char* x = strdup(strtok(riga, ";"));//assegno ad una temporanea la data

        io->cognome=strdup(strtok(NULL, ";"));//assegno alla struttura il cognome
        tmp=atoi(strtok(NULL,";"));

        if(strcmp(io->cognome,"Serra")==0){
            io->quota=io->quota+tmp;//sommo l'incasso della riga al totale
        }
    }

    io->cognome="Serra";

    if(io->quota<100){

        printf("Non ho pagato l'intera quota %d\n", io->quota);
    }else{
        printf("Ho pagato interamente la quota\n");
    }
}



int main(){
    int n;
    n=contarighe();
    int incasso=contaIncassi();
    Persona *pi;
    pi=(Persona*)malloc(n*sizeof(Persona));

    printf("%d", incasso);

    if(incasso<TOTALE){//controllo se l'incasso totale e' minore dell'incasso desiderato
        printf("mancano %d euro\n", (TOTALE-incasso));//stampo la differenza
    }else{
        printf("E' stata raggiunta la quota di 2200 euro\n");//stampo la conferma per il raggiungimento del totale
    }

    Persona *io;//inizializzo la struttura per me stesso
    io=(Persona*)malloc(1*sizeof(Persona));//alloco dinamicamente la mia struttura

    verificaQuota(io);//verifico la quota


    free(io);
}
