#include <stdio.h>

int main() {
    int curr, i, risultato, psub2, psub3;
    
    printf("Inserisci un valore: ");
    scanf("%d", &curr);
    
    i=0;
    risultato=0;
    psub2=1;
    psub3=1;
    
    while(risultato < curr) {
        if(i>=0 && i<=2) {
            risultato = 1;
        } else {
            risultato = psub2 + psub3;
            
            if(i % 2 == 0) {
                psub3 = risultato;
            } else {
                psub2 = risultato;
            }
        }
        
        printf("%d \n", risultato);
        
        i++;
    }
    
    return 0;
}