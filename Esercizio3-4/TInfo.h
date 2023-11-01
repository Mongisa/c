/*
 * TInfo: tipo elementare
 */

#ifndef TINFO_H
#define TINFO_H

typedef int TInfo;

int infoEqual(TInfo, TInfo);
int infoGreater(TInfo, TInfo);
int infoLess(TInfo, TInfo);
int infoGreaterOrEqual(TInfo,TInfo);
int infoLessOrEqual(TInfo,TInfo);
void infoPrint(TInfo);

#endif

