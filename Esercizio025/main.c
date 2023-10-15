#include <stdio.h>
#include <stdlib.h>
#define NOT_FOUND 0

int occorrenzeCarRic(char c, char *s);
int occorrenzeCarConta(char c, char *s);
void inverti(char sorgente[],char destinazione[]);

int main(int argc, char** argv) {

    char s[30];
    char c;
    int occ;
    char dest[30];
    
    printf("Inserisci una stringa: ");
    scanf("%s",s);
    
    printf("Inserisci carattere: \n");
    scanf(" %c",&c);
    
    if(occorrenzeCarRic(c,s)==1) {
        printf("\n%c occorre in %s",c,s);
    } else {
        printf("\n%c non occorre in %s",c,s);
    }
    
    occ = occorrenzeCarConta(c,s);
    
    if(occ==NOT_FOUND) {
        printf("\n%c non occorre in %s",c,s);
    } else {
        printf("\n%c occorre in %s %d volte",c,s,occ);
    }
    
    inverti(s,dest);
    
    printf("\nStringa inversa: %s",dest);
    
    return (EXIT_SUCCESS);
}

int occorrenzeCarRic(char c, char *s) {
    if(s[0] == '\0') {
        return 0;
    }
    
    if(c == s[0]) {
        return 1;
    }
    s++;
    return occorrenzeCarRic(c,s);
}

int occorrenzeCarConta(char c,char *s) {
    
    if(s[0] == '\0') {
        return 0;
    }

    if(s[0] == c) {
        s++;
        return 1+occorrenzeCarConta(c,s);
    } else {
        s++;
        return occorrenzeCarConta(c,s);
    }
}

void inverti(char sorgente[],char destinazione[]) {
    
    int i = -1;
    while(sorgente[i+1] != '\0') {
        i++;
    }
    
    if(i==-1) return;
    
    destinazione[0] = sorgente[i];
    
    sorgente[i]='\0';
    
    inverti(sorgente,destinazione+1);
    
}