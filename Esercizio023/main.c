#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(int argc, char** argv) {

    int x,y;
    
    printf("Inserisci x: ");
    scanf("%d",&x);
    
    printf("Inserisci y: ");
    scanf("%d",&y);
    
    printf("MCD: %d\n",mcd(x,y));
    printf("Prodotto: %d",prodotto(x,y));
    
    
    return (EXIT_SUCCESS);
}

