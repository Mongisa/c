#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stackTy.h"

int calculateSpace(int num);
void calculate(stackTy* s);
void consume(stackTy* s,char* result);
char* convertToBinary(int num,stackTy* binaryStack);

int main(int argc, char** argv) {

    int n;
    stackTy s;
    
    printf("Inserici numero da convertire: ");
    scanf("%d",&n);
    
    s = stackCreate(-1);
    
    printf("%s",convertToBinary(n,&s));
    
    stackDestroy(&s);
    
    return (EXIT_SUCCESS);
}

char* convertToBinary(int num,stackTy* binaryStack) {
    int space;
    
    space = calculateSpace(num);
    
    char* result = calloc(space+1,sizeof(char));
    
    result[space+1] = '\0';

    stackPush(binaryStack,num); //Inserisco il numero nello stack
    
    calculate(binaryStack);
    
    consume(binaryStack,result);
    
    return result;
}

//Calcola lo spazio necessario per memorizzare il risultato,a partire dal numero decimale
int calculateSpace(int num) {
    return (int)ceilf(log2f(num));
}

//Effettua la conversione ricorsivamente, mettendo il risultato nello stack
void calculate(stackTy *s) {
    int num = stackPop(s).res;
    
    if(num == 0) {
        return;
    };
    
    stackPush(s,num%2);
    stackPush(s,num/2);
    calculate(s);
}

//Prende dati dallo stack e produce il risultato sotto forma di stringa
void consume(stackTy* s,char* result) {
    int i=0;
    
    while(stackIsEmpty(s) == false) {
        char c = stackPop(s).res + '0';
        result[i] = c;
        i++;
    }
}