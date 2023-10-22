#include <stdlib.h>
#include <assert.h>
#include "arrayTy.h"
#include "infoTy.h"

#define GROWING_DELTA 10
#define SHRINKING_DELTA 20

//Creazione dell'array
arrayTy arrayCreate(int length) {
    arrayTy a;
    a.item = (infoTy*) malloc(length * sizeof(infoTy));
    assert(length == 0 || a.item != NULL);
    a.length = length;
    a.size = length;
    return a;
}

//Eliminazione dell'array
void arrayDestroy (arrayTy* a) {
    free(a->item);
    a->item = NULL;
    a->length = 0;
    a->size = 0;
}

//Cambiamento dimensione array
void arrayResize(arrayTy *a,int new_length) {
    if(new_length > a->size || new_length < a->size - SHRINKING_DELTA) {
        int new_size = new_length + GROWING_DELTA;
        a->item = realloc(a->item,new_size*sizeof(infoTy));
        assert(new_length == 0 || a->item != NULL);
        a->size = new_size;
    }
    a->length = new_length;
}

//Stampa vettore
void arrayPrint(arrayTy *a) {
    for(int i=0;i<a->length;i++) {
        infoPrint(a->item[i]);
    }
}

/* FUNZIONI NON ESSENZIALI */

//Aggiunta elemento in coda
void arrayAdd(arrayTy *a,infoTy x) {
    arrayResize(a,a->length+1);
    a->item[a->length-1] = x;
}

//Lettura di un elemento in posizione pos
infoTy arrayGet(arrayTy *a,int pos) {
    return (pos<a->length) ? a->item[pos] : 0;
}

//Inserisce un elemento in posizione pos
void arrayInsert(arrayTy *a,int pos,infoTy x) {
    if(pos>=a->length) exit(EXIT_FAILURE);
    arrayResize(a,a->length+1);
    
    for(int i=a->length-2;i>=pos;i--) {
        a->item[i+1] = a->item[i];
    }
    
    a->item[pos] = x;
}

//Sostituisce l'elemento in posizione pos
void arraySet(arrayTy *a,int pos,infoTy x) {
    if(pos>=a->length) exit(EXIT_FAILURE);
    a->item[pos]=x;
}