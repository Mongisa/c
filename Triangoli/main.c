#include <stdio.h>

int main() {
    int a,b,c;
    
    printf("Inserisci la lunghezza dei lati del triangolo \n");
    scanf("%d %d %d", &a, &b, &c);
    
    //Controlla se la terna inserita è corretta
    if(a >= b+c || b >= a+c || c >= a+b) {
        printf("La terna inserita non corrisponde ad un triangolo!");
    } else
    //Controlla il tipo di triangolo
    if(a == b && b == c) {
        printf("Il triangolo e' equilatero");
    } else if (a != b && a != c && b != c) {
        printf("Il triangolo e' scaleno");
    } else if(a==c || a==b || b==c) {
        printf("Il triangolo e' isoscele");
    };
    
    return 0;
}