#include <stdio.h>
#include <stdbool.h>
#include "infoTy.h"

void infoPrint(infoTy info) {
    printf("%c ",info);
}

bool infoEqual(infoTy a,infoTy b) {
    return a==b;
}