#include <stdio.h>
#define SIZE 150

int main() {
    int v1[SIZE],v2[SIZE],v3[SIZE*2];
    int d,val;
    
    printf("Inserisci la dimensione");
    scanf("%d", &d);
    
    //Valori primo vettore V1
    for(int i=0; i<d; i++) {
        printf("Inserisci v1[%d]: ", i);
        scanf("%d", &val);
        v1[i] = val;
    }
    
    //Valori secondo vettore V2
    for(int i=0; i<d; i++) {
        printf("Inserisci v2[%d]: ", i);
        scanf("%d", &val);
        v2[i] = val;
    }
        
    for(int i=0; i<d*2; i++) {
        if(i%2 == 0) {
            v3[i] = v1[i/2];
        } else {
            v3[i] = v2[i/2];
        }
    }
    
    for(int i=0; i<d*2; i++) {
        printf("%d", v3[i]);
    }
    
    return 0;
}