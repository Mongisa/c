#include <stdio.h>

int main() {
    int N;
    
    printf("Inserisci un numero positivo: ");
    scanf("%d", &N);
    
    while(N<0) {
        printf("DEVI INSERIRE UN NUMERO POSITIVO: ");
        scanf("%d", &N);
    }
    
    for(int i=0; i<N; i++) {
        if(i%2 == 0) {
            printf("%d\n", i);
        }
    }
   
    return 0;
}