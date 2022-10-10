#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DIM 1024

typedef struct gioco{
    int rank;
    char* name;
    char* platform;
    int year;
    char* genre;
    char* publisher;
    float NA_sales;
    float EU_sales;
    float JP_sales;
    float Other_sales;
    float Global_sales;

}gioco;

int sizeFP(FILE*fp){ //utilizza la funzione fseek per contare la dimensione del file (trovato su forum)
    int prev=ftell(fp);
    fseek(fp, 0L, SEEK_END);
    int sz=ftell(fp);
    fseek(fp,prev,SEEK_SET);
    return sz;
}

int main() {
    gioco*pi;
    int n;
    int k = 0;

    char riga[DIM];
    FILE*fp;
    fp = fopen("vgsales.csv","r");
    if(fp == NULL){
        printf("\nIl file non esiste");
        return 0;
    }else{
        printf("\nsono dentro");

        n = sizeFP(fp);
        pi = (gioco*)malloc(n * sizeof(gioco)); //malloc

        fgets(riga, DIM,fp);//tolgo la prima riga d' intestazione
        while(fgets(riga, DIM,fp) != EOF){
            (pi + k)->rank = atoi(strtok(riga, ","));
            (pi + k)->name = strtok(NULL, ",");
            (pi + k)->platform = strtok(NULL, ",");
            (pi + k)->year = atoi(strtok(NULL, ","));
            (pi + k)->genre = strtok(NULL, ",");
            (pi + k)->publisher = strtok(NULL, ",");
            (pi + k)->NA_sales = atof(strtok(NULL, ","));
            (pi + k)->EU_sales = atof(strtok(NULL, ","));
            (pi + k)->JP_sales = atof(strtok(NULL, ","));
            (pi + k)->Other_sales = atof(strtok(NULL, ","));
            (pi + k)->Global_sales = atof(strtok(NULL, ","));

            printf("\n %d, %s, %s, %d, %s, %s, %.2f, %.2f, %.2f, %.2f, %.2f", (pi + k)->rank, (pi + k)->name, (pi + k)->platform, (pi + k)->year, (pi + k)->genre, (pi + k)->publisher, (pi + k)->NA_sales, (pi + k)->EU_sales, (pi + k)->JP_sales, (pi + k)->Other_sales, (pi + k)->Global_sales);
            k++;
        }
        fclose(fp);
        free(pi);

    }
    return 0;
}
