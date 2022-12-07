#include <stdio.h>

float prezzo_scont(int prezzo, int sconto);

void main() {
    int prezzo, sconto;
    float prezzo_finale;
    
    printf("Inserisci il prezzo del prodotto: ");
    scanf("%d", &prezzo);
    
    printf("Inserisci lo sconto: ");
    scanf("%d", &sconto);
    
    prezzo_finale = prezzo_scont(prezzo, sconto);
    
    printf("%.2f €", prezzo_finale);
}

float prezzo_scont(int prezzo, int sconto) {
    float prezzo_finale;
    
    prezzo_finale = prezzo - sconto*prezzo/100;
    
    return prezzo_finale;
}