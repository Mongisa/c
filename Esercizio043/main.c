#include <stdio.h>
#include <stdlib.h>
#include "TStack.h"
#include "TInfo.h"
#include <stdbool.h>
#include <string.h>

bool checkPalindroma(char* str);

int main(int argc, char** argv) {

    char string[100];
    
    printf("Inserisci stringa: ");
    scanf("%s",string);
    
    if(checkPalindroma(string)) {
        printf("\n%s è palindroma!",string);
    } else {
        printf("\n%s non è palindroma!",string);
    }
    
    return (EXIT_SUCCESS);
}

bool checkPalindroma(char* str) {
    TStack s1 = stack_create();
    TStack s2 = stack_create();
    
    int str_length = strlen(str);
    
    /*SALVATAGGIO PRIMA META' DELLA PAROLA IN S1*/
    for(int i=0;i<str_length/2;i++) {
        stack_push(&s1,str[i]);
    }
    
    /*SALVATAGGIO SECONDA META' DELLA PAROLA IN S2*/
    for(int i=str_length-1;i>str_length/2+(str_length-1)%2;i--) {
        stack_push(&s2,str[i]);
    }
    
    /*CONTROLLO SE IL CONTENUTO DEI DUE STACK E' UGUALE*/
    while(!stack_is_empty(&s1)) {
        if(!infoEqual(stack_pop(&s1),stack_pop(&s2))) {
            return false;
        }
    }

    return true;
}