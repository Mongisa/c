#ifndef STACKTY_H
#define STACKTY_H

#include "arrayTy.h"
#include "fReplyTy.h"
#include "infoTy.h"
#include <stdbool.h>

struct stackSt {
    int n;
    int capacity;
    arrayTy a;
};

typedef struct stackSt stackTy;

stackTy stackCreate(int);
void stackDestroy(stackTy*);
fReplyTy stackPush(stackTy*,infoTy);
fReplyTy stackPop(stackTy*);
fReplyTy stackTop(stackTy*);
bool stackIsEmpty(stackTy*);
bool stackIsFull(stackTy*);

#endif /* STACKTY_H */

