#include <stdlib.h>
#include <stdbool.h>
#include "nodeTy.h"

/*Crea un nuovo nodo allocando lo spazio e restituisce il puntatore
(restituisce NULL se l'allocazione fallisce)*/
nodeTy* nodeCreate(infoTy info) {
    nodeTy *new;
    
    new = (nodeTy*) malloc(sizeof(nodeTy));
    
    if(new == NULL) return NULL;
    
    new->info = info;
    new->link = NULL;
    
    return new;
}

//Distrugge il nodo passato in in input
void nodeDestroy(nodeTy* node) {
    free(node);
}

//Crea e restituisce una lista nuova
listTy listCreate() {
    return NULL;
}

//Distrugge la lista deallocando gli elementi
void listDestroy(listTy list) { //Ricorsiva
    if(list->link == NULL) return;
    
    listDestroy(list->link);
    nodeDestroy(list->link);
}

//Stampa il valore di ciascun nodo della lista
void listPrint(listTy list) {
    if(listIsEmpty(list)) return;
    infoPrint(list->info);
    listPrint(list->link);
}

//Cerca un valore info tra i nodi della list
nodeTy* listSearch(listTy list,infoTy info) {
    if(list == NULL || infoGreater(list->info,info)) return NULL;
    
    listSearch(list->link,info);
    
    if(infoEqual(list->info,info))
        return list;
}

//Inserisce un valore nella lista (ordine crescente)
void listInsert(listTy* list,infoTy info) {
    
    nodeTy* node = nodeCreate(info);

    listTy prec = NULL;
    listTy curr = *list;
    
    while(curr != NULL && infoGreater(info,curr->info)) {
        prec = curr;
        curr = curr->link;
    }
    
    if(prec == NULL) {
        *list = node;
    } else {
        prec->link = node;
    }
    
    node->link = curr;
    
}

//Elimina un nodo della list contenente il valore info
void listDelete(listTy *list,infoTy info){
    nodeTy* node = listSearch(*list,info);
    
    if(node == NULL) return;
    
    nodeTy* succ = node->link;
    
    if(succ != NULL) {
        node->info = succ->info;
        node->link = succ->link;
        free(succ);
    } else {
        free(node);
    }
    
}

bool listIsEmpty(listTy list) {
    return (list == NULL) ? true : false;
}