#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int re[2], regina[2], x,y;
    
    printf("Inserisci coordinate Re (tra 1 e 8): ");
    scanf("%d %d", &re[0], &re[1]);
    
    printf("Inserisci coordinate Regina (tra 1 e 8): ");
    scanf("%d %d", &regina[0], &regina[1]);
    
    if(re[0] < 1 || re[0] > 8 || re[1] < 1 || re[1] > 8) {
        printf("Le coordinate del Re sono sbagliate!");
        return 0;
    }
    
    if(regina[0] < 1 || regina[0] > 8 || regina[1] < 1 || regina[1] > 8) {
        printf("Le coordinate della Regina sono sbagliate!");
        return 0;
    }
    
    if(re[0] == regina[0] && re[1] == regina[1]) {
        printf("Re e Regina si trovano sulla stessa casella!");
        return 0;
    }
    
    //Controllo scacco
    
    if(regina[0] == re[0] || regina[1] == re[1]) {
        printf("Il Re è sotto scacco!");
    } else if(abs(re[0] - regina[0]) == abs(re[1] - regina[1])) {
        printf("Il Re è sotto scacco!");
    } else {
        printf("Il Re non è sotto scacco");
    }
   
    return 0;
}