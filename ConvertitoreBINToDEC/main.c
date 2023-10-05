#include <stdio.h>
#include <math.h>

int main() {
    int N,i,dec, cifra;
    
    printf("Inserisci N: ");
    scanf("%d", &N);
    
    i=0;
    dec=0;
    
    do {
        printf("Inserisci cifra %d: ", i);
        scanf("%d", &cifra);
        dec = dec + cifra*pow(2,i);
        i++;
    } while(i<N);
    
    printf("Numero decimale: %d", dec);
    
    return 0;
}