#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stackTy.h"
#include "fReplyTy.h"

bool checkPar(char str[]);
void pushString(stackTy* sp,char str[]);
int countPar(stackTy* sp);

int main(int argc, char** argv) {
    
    stackTy s;
    char str[30];
    
    s = s_create();
    
    printf("Inserisci espressione: ");
    scanf("%s",str);
    
    pushString(&s,str);
    
    int count = countPar(&s);
    
    if(!checkPar(str)) {
        printf("Non ci sono parentesi!");
        return 0;
    };
    
    if(count != 0) {
        printf("La sintassi non è corretta");
    } else {
        printf("La sintassi è corretta");
    }
    
    return (EXIT_SUCCESS);
}

bool checkPar(char str[]) {
    char pa = '(';
    char pc = ')';
    return (strchr(str,pa) == NULL && strchr(str,pc) == NULL) ? false : true;
}

void pushString(stackTy* sp,char str[]) {
    int str_length = strlen(str);
    
    for(int i=0;i<str_length;i++) {
        s_push(sp,str[i]);
    }
}

int countPar(stackTy* sp) {
    int c=0;
    for(int i=0;i<sp->n;i++) {
        char carattere = sp->a[i];
        
        if(infoEqual(carattere,'(')) {
            c++;
        } else if(infoEqual(carattere,')')) {
            c--;
        }
    }
    
    return c;
}