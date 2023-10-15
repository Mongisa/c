#include <stdio.h>
#include <stdlib.h>

int pari (int);
int primo(int,int);

int main(int argc, char** argv) {

    int n;
    
    printf("Inserisci n: ");
    scanf("%d",&n);
    
    if(primo(n,n) == 1) {
        printf("%d è primo",n);
    } else {
        printf("%d non è primo",n);
    }
    
    return (EXIT_SUCCESS);
}

int pari(int n) {
    return n%2==0 ? 1 : 0;
}

int primo(int n,int div) {
    div--;
    
    if(div==1) {
        return 1;
    }
    
    if(pari(n)) {
        return 0;
    }
    
    if(n%div==0) {
        return 0;
    }
    
    return primo(n,div);
}