/*
 Scrivere un programma che legge un intero positivo n da stdin e verifica se
n può essere scomposto nella somma di due quadrati (verifica cioè se  a,
b  N | a2+b2=n ). Se sì, stampare a video la scomposizione. Esempi:
2 ==> 2 = 1 + 1 = 1^2 + 1^2
28 ==> NON SCOMPONIBILE
145 ==> 146 = 25 + 121 = 5^2 + 11^2

Varianti e aggiunte (per la meditazione domestica)
a. Mostrare, quando ve ne è più di una, tutte le diverse scomposizioni
dello stesso numero (ad esempio 50 ha due scomposizioni, 1+49 e
25+25, mentre 8125 è il primo numero ad avere ben cinque diverse
scomposizioni).
b. Generare le sequenza di tutti i numeri scomponibili come somma di
due quadrati in due modi, in tre modi, in quattro modi... (sempre
considerando numeri fino ad un valore massimo N)
c. Verificare anche la scomponibilità in somma di tre quadrati.*/

#include <stdio.h>
#include <math.h>

int main() {
    int curr,i,k;
    
    do {
        printf("Inserisci un numero: ");
        scanf("%d", &curr);
    } while(curr <= 0);
    
    for(i=1;i<=curr;i++) {
        for(k=i+1;k<=curr;k++) {
            if(curr == i*i + k*k) {
                printf("%d è scomponibile in %d^2 + %d^2 \n", curr, i, k);
            }
        }
    }
    
    return 1;
}