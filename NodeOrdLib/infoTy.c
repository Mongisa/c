#include <stdio.h>
#include <stdbool.h>
#include "infoTy.h"

void infoPrint(infoTy info) {
    printf("%d ",info);
}

bool infoEqual(infoTy a,infoTy b) {
    return a==b;
}

bool infoGreater(infoTy a,infoTy b) {
    return a>b;
}

bool infoLess(infoTy a,infoTy b) {
    return a<b;
}