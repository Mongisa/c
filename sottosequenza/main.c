#include <stdio.h>
#define SIZE 100

int main() {

    int curr, vet[SIZE], riemp, i, lungh=1, lungh_max=0;
    
    printf("Inserisci un numero (inserisci 0 per terminare): ");
    scanf("%d", &curr);
    
    riemp=0;
    
    while(curr != 0) {
        
        if(curr > 0) {
            vet[riemp] = curr;
            riemp++;
        } else {
            printf("Devi inserire un numero maggiore di 0!\n");
        }
        
        printf("Inserisci un numero (inserisci 0 per terminare): ");
        scanf("%d", &curr);
    }
    
    for(i=0;i<riemp - 1;i++) {
        if(vet[i] < vet[i+1]) {
            lungh++;
        } else {
            if(lungh_max < lungh) {
                lungh_max = lungh;
            }
            lungh=1;
        }
    }
    
    if(lungh_max < lungh) {
        lungh_max = lungh;
    }
    
    printf("Lungh max = %d", lungh_max);
    
    return 0;
}

