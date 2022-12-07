#include <stdio.h>

int main() {
    float a;
    
    printf("Inserisci il valore del numero: ");
    scanf("%f", &a);
    
    if(a>0) {
        printf("%f", a);
    } else {
        printf("%f", -a);
    };
    
    return 0;
}