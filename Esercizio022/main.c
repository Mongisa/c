#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define DIM 7

typedef int infoTy;

int sommaDispari(infoTy vet[],int n);
int minimo(infoTy vet[], int n);
bool tuttiMaggioriDi(infoTy vet[], int n, int k);

bool less(infoTy a, infoTy b) {
    return (a<=b) ? true : false;
}

bool greater(infoTy a, infoTy b) {
    return (a>b) ? true : false;
}

int main(int argc, char** argv) {

    infoTy a[DIM] = {32,34,65,76,54,34,2};
    infoTy min_I,k;
    
    printf("La somma degli elementi in posizione dispari è %d\n", sommaDispari(a,DIM));

    min_I = minimo(a,DIM);

    printf("Il valore minimo è in posizione %d e vale %d\n",min_I,a[min_I]);

    printf("Inserisci numero da confrontare: ");
    scanf("%d",&k);

    if(tuttiMaggioriDi(a,DIM,k)) {
        printf("%d è maggiore di tutti gli elementi del vettore\n",k);
    } else {
        printf("%d non è maggiore di tutti gli elementi del vettore\n",k);
    }
    
    return (EXIT_SUCCESS);
}

int sommaDispari(infoTy vet[],int n) {
    if(n==0) return 0;
    if((n-1)%2 != 0) {
        return sommaDispari(vet,n-1)+vet[n-1];
    } else {
        return sommaDispari(vet,n-1);
    }
}

int minimo(infoTy vet[], int n) {
    if(n==1) return 0;

    int min_I = minimo(vet,n-1);

    return (less(vet[min_I],vet[n-1])) ? min_I : n-1;
}

bool tuttiMaggioriDi(infoTy vet[], int n, int k) {

    if(n==0) return true;
    
    if(greater(vet[n-1],k)) {
        return false;
    }
    
    return tuttiMaggioriDi(vet,n-1,k);
    
}