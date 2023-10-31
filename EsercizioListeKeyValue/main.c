#include <stdio.h>
#include <stdlib.h>
#include "TInfoList.h"
#include "TList.h"

int sizeList(TList);
TList deleteLastlist(TList);

/* scrivere una funzione ricorsiva
 int sizeList(TList l)
 * 
 * e restituisce il numero di elementi presenti in una lista ordinata
 * 
 * es.  da una lista con gli elementi
 * (5,6) (8,8) (18,33) (25,44) (37,22) (55,66)
 * sizeList dovrebbe restituire 6
 */

/* scrivere una funzione ricorsiva
 * TList deleteLastlist(TList l)
 * 
 * che restituisce la lista di partenza con l'ultimo nodo eliminato se esiste
 * 
 * es. da una lista con gli elementi
 * (5,6) (8,8) (18,33) (25,44) (37,22) (55,66)
 * si passerebbe ad una lista con elementi
 * (5,6) (8,8) (18,33) (25,44) (37,22) 
 */

int main(int argc, char** argv) {
    TList t=listCreate();
    TInfoList i;
    for (int j=0;j<6;j++){ 
        i.key=5+j; i.value=55+j;
        t=listInsert(t, i);
    }
    listPrint(t);
    printf("\nIl numero di elementi presenti e' = %d\n",sizeList(t));
    listPrint(deleteLastlist(t));
    return (EXIT_SUCCESS);

}

int sizeList(TList l) {
    if(!l) return 0; //CASO BASE
    return 1+sizeList(l->link); //DIVIDE ET IMPERA E COMBINA
}

TList deleteLastlist(TList l) {

    /*CASO BASE*/
    if(!l) return l;
    if(!(l->link)) {
        nodeDestroy(l);
        return NULL;
    }
    
    /*DIVIDE ET IMPERA E COMBINA*/
    l->link = deleteLastlist(l->link);
    
    return l;
}






/*TList deleteLastlist(TList l) {
    if (l==NULL) //INIZIO CASO BASE
        return l;
    if (l->link==NULL) {
        nodeDestroy(l);
        return NULL;
    } //FINE CASO BASE
    TList t=deleteLastlist(l->link); //DIVIDE ET IMPERA
    l->link=t; // COMBINA
    return l;
}

int sizeList(TList l) {
    if (l==NULL)  //CASO BASE
            return 0;
    int sizesublist=sizeList(l->link); // DIVIDE ET IMPERA 
    return 1+sizesublist; // COMBINA
}*/