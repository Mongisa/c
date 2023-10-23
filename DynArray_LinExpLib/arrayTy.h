#ifndef ARRAYTY_H
#define ARRAYTY_H
#include "infoTy.h"

struct arraySt {
    infoTy* item; //Elementi dell'array
    int length; //Blocchi occupati dal vettore
    int size; //Dimensione allocata
};

typedef struct arraySt arrayTy;

arrayTy arrayCreate(int);
void arrayDestroy(arrayTy*);
void arrayResize(arrayTy*,int);
void arrayPrint(arrayTy*);

void arrayAdd(arrayTy*,infoTy);
infoTy arrayGet(arrayTy*,int);
void arrayInsert(arrayTy*,int,infoTy);
void arraySet(arrayTy*,int,infoTy);

#endif /* ARRAYTY_H */

