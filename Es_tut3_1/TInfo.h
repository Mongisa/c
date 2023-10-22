/*
 * TInfo: tipo elementare
 */

#ifndef TINFO_H
#define TINFO_H

//#include "TArray.h"
//#include "TStack.h" Nessuna di tutte e due ci serve quindi meglio non includerle

typedef char TInfo; //typedef int TInfo; Deve essere un array di caratteri, non di interi

int infoEqual(TInfo, TInfo);
int infoGreater(TInfo, TInfo);
int infoLess(TInfo, TInfo);
void infoPrint(TInfo);

#endif