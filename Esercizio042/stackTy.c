#include "arrayTy.h"
#include "fReplyTy.h"
#include "infoTy.h"
#include "stackTy.h"
#include <stdbool.h>
#include <stdlib.h>

/* Crea lo stack (basandosi su un array dinamico)
 * Se capacity > 0 crea uno stack di capienza limitata
 * Se capacity <= 0 crea uno stack di capienza non limitata
 */
stackTy stackCreate(int capacity) {
    stackTy s;
    
    if(capacity > 0) {
        s.a = arrayCreate(capacity);
        s.capacity = capacity;
    } else {
        s.a = arrayCreate(10);
        s.capacity = -1;
    }
    
    s.n = 0;
    return s;
}

//Distrugge lo stack
void stackDestroy(stackTy* s) {
    arrayDestroy(&s->a);
    s->n=0;
    s->capacity=0;
}

//Restituisce true se lo stack è pieno
bool stackIsFull(stackTy* s) {
    return (s->capacity > 0 && s->n==s->capacity) ? true : false;
}

//Restituisce true se lo stack è vuoto
bool stackIsEmpty(stackTy* s) {
    return (s->n==0) ? true : false;
}

//Aggiunge un elemento allo stack
fReplyTy stackPush(stackTy* s,infoTy info) {
    fReplyTy r;
    
    if(stackIsFull(s)==true) {
        r.check = false;
        return r;
    }
    
    arrayResize(&s->a,s->n+1);
    arraySet(&s->a,s->n,info);
    s->n++;
    r.check = true;
    return r;
}

//Rimuove e restiuisce l'elemento in cima allo stack
fReplyTy stackPop(stackTy* s) {
    fReplyTy r;
    
    if(stackIsEmpty(s)==true) {
        r.check = false;
        return r;
    }
    
    r.check = true;
    r.res = arrayGet(&s->a,s->n-1);
    arrayResize(&s->a,s->n-1);
    s->n--;
    return r;
}

//Restituisce l'elemento in cima allo stack
fReplyTy stackTop(stackTy* s) {
    fReplyTy r;
    
    if(stackIsEmpty(s)==true) {
        r.check = false;
        return r;
    }
    
    r.check = true;
    r.res = arrayGet(&s->a,s->n-1);
    return r;
}