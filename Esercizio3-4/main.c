#include <stdio.h>
#include <stdlib.h>
#include "TList.h"

TList listDupEvenRic(TList);
TList listDupEven(TList);
TList listDeleteInterval(TList,TInfo,TInfo);
TList listDeleteIntervalRic(TList,TInfo,TInfo);

int main(int argc, char** argv) {

    TList l1 = list_create();
    TList l2 = list_create();
    TList l3 = list_create();
    
    l1 = list_insert(l1,10);
    l1 = list_insert(l1,11);
    l1 = list_insert(l1,11);
    l1 = list_insert(l1,18);
    l1 = list_insert(l1,18);
    l1 = list_insert(l1,21);
    l1 = list_insert(l1,30);
    
    l2 = list_insert(l2,11);
    l2 = list_insert(l2,13);
    l2 = list_insert(l2,15);
    
    l3 = list_insert(l3,10);
    l3 = list_insert(l3,10);
    l3 = list_insert(l3,10);
    
    printf("Lista 1: ");
    list_print(l1);
    
    printf("Lista 2: ");
    list_print(l2);
    
    printf("Lista 3: ");
    list_print(l3);
    
    l1 = listDeleteIntervalRic(l1,1,10);
    
    printf("\n");
    
    printf("Lista 1: ");
    list_print(l1);
    
    printf("Lista 2: ");
    list_print(l2);
    
    printf("Lista 3: ");
    list_print(l3);
    
    return (EXIT_SUCCESS);
}

/*ESERCIZIO 3 RICORSIVO*/
TList listDupEvenRic(TList l) {
    
    /*CASO BASE*/
    if(!(l)) return NULL;
    
    if((l->info)%2==0) {
        TList node = node_create(l->info);
        /*DIVIDE ET IMPERA E COMBINA*/
        node->link = listDupEvenRic(l->link);
        l->link = node;
        return l;
    }
    
    /*DIVIDE ET IMPERA E COMBINA*/
    l->link = listDupEvenRic(l->link);
    
    return l;
    
}

/*ESERCIZIO 3 ITERATIVO*/
TList listDupEven(TList list){
    TList curr = list;
    while (curr != NULL){
        if ((curr->info)%2==0){
            TNode* new = node_create(curr->info);
            new->link = curr->link;
            curr->link = new;
            
            curr = new->link;
        }
        else
            curr = curr->link;
    }
    
    return list;
}

/*ESERCIZIO 4 ITERATIVO*/
TList listDeleteInterval(TList l,TInfo min,TInfo max) {
    TList tmp = list_create();
    
    while(l) {
        if(infoLess(l->info,min) || infoGreater(l->info,max)) {
            tmp = list_insert(tmp,l->info);
        }
        
        l=l->link;
    }
    
    list_destroy(l);
    
    return tmp;
}

/*ESERCIZIO 4 RICORSIVO*/
TList listDeleteIntervalRic(TList l,TInfo min,TInfo max) {
    /*CASO BASE*/
    if(!l) return NULL;
    
    if(!(infoLess(l->info,min) || infoGreater(l->info,max))) {
        /*DIVIDE*/
        TList next = l->link;
        node_destroy(l);
        /*IMPERA*/
        return listDeleteIntervalRic(next,min,max);
    }
    
    /*DIVIDE ET IMPERA E COMBINA*/
    l->link = listDeleteIntervalRic(l->link,min,max);
    
    return l;
}