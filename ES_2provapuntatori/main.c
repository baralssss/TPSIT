#include <stdio.h>

int main() {
    int vet[5];
    int *pi = vet;

    *(pi + 3) = 10;
    *(pi + 1) = 4;
    *(pi) = 6;
    *(pi + 2) = 15;
    *(pi + 4) = 12;

    for(int k = 0; k < 5; k++){
        printf("%d ", *(pi + k));
    }
    printf("\n");
    int k = 0;
    while(k < 5){
        printf("%d ", *(pi++));
        k++;
    }

    return 0;
}
