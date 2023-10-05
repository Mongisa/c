#include <stdio.h>
#include <math.h>

int check_Primo(int num);
int check_Armstrong(int num);

int main() {
    int num, primo, armstrong;
    
    printf("Inserisci un numero: ");
    scanf("%d", &num);
        
    //primo = check_Primo(num);
    armstrong = check_Armstrong(num);
    
    /*if(primo == 1) {
        printf("%d è un numero primo \n", num);
    } else {
        printf("%d non è un numero primo \n", num);
    }*/
    
    if(armstrong == 1) {
        printf("%d è un numero di Armstrong", num);
    } else {
        printf("%d non è un numero di Armstrong", num);
    }
    
    return 0;
}

int check_Primo(int num) {

    int primo = 1;
    
    for(int i = num - 1; i > 1; i-- ) {
        if(num % i == 0) {
            primo = 0;
            return primo;
        }
    }
    
    return primo;
}

int check_Armstrong(int num) {
    
    int armstrong = 0;
    int size = 0;
    int somma = 0;
    int vett[100];
    
    int initial_num = num;
    
    while(num != 0 && size <= 100) {
        vett[size] = num % 10;
        num = num / 10;
        size++;
    }
    
    for(int i=0; i<size; i++) {
        somma = somma + pow(vett[i], size);
    }
    
    if(somma == initial_num) {
        armstrong = 1;
    }
    
    return armstrong;
}