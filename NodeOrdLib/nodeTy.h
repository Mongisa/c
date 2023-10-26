#ifndef NODETY_H
#define NODETY_H

#include "infoTy.h"

struct nodeSt {
    infoTy info;
    struct nodeSt *link;
};

typedef struct nodeSt nodeTy;
typedef nodeTy *listTy;

nodeTy* nodeCreate(infoTy);
void nodeDestroy(nodeTy*);
listTy listCreate();
void listDestroy(listTy);
void listPrint(listTy);
nodeTy* listSearch(listTy,infoTy);
void listInsert(listTy*,infoTy);
void listDelete(listTy*,infoTy);
bool listIsEmpty(listTy);

#endif /* NODETY_H */

