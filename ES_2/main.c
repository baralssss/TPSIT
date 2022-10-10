#include <stdio.h>
#define DIM 10

void bubbleSORT(int v[], int n) {
    int *pk = v;
    int i, k;
    int temp;
    for(i = 0; i<n; i++) {
        for(k = 0; k<i; k++) {
            if(*(pk + k) > *(pk + i)) {
                temp = *(pk + k);
                *(pk + k) = *(pk + i);
                *(pk + i) = temp;
            }
        }
    }
}

void stampaVET(int v[], int n){
    int *pk = v;
    int i;
    for(i = 0; i<n; i++) {
        printf("%d ", *(pk + i));
    }
}


int main() {
    int vet[DIM] = {4, 65, 87, 34, 10, 24, 59, 21, 12, 84};
    bubbleSORT(vet, DIM);
    stampaVET(vet, DIM);
    return 0;
}
