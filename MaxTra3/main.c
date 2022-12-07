#include <stdio.h>

int main() {
    int a,b, max;
    
    printf("Inserisci primo valore: ");
    scanf("%d", &a);
    
    printf("Inserisci secondo valore: ");
    scanf("%d", &b);
            
    if(a>b) {
        max = a;
    } else {
        max = b;
    }
    
    printf("Il massimo è: %d", max);
    
    return 0;
}