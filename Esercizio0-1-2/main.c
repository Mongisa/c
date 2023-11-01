#include <stdio.h>
#include <stdlib.h>
#include "TList.h"

TInfo listSomma(TList l);
TInfo listMinimo(TList l);
TList listInsertAt (TList,TInfo,int);

int main(int argc, char** argv) {
    
    TList l = list_create();
    
    l = list_insert(l,3);
    l = list_insert(l,7);
    l = list_insert(l,20);
    l = list_insert(l,25);
    
    printf("La somma è %d\n",listSomma(l));
    
    TList l2 = list_create();
    
    l2 = list_insert_end(l2,4);
    l2 = list_insert_end(l2,-30);
    l2 = list_insert_end(l2,20);
    l2 = list_insert_end(l2,10);
    
    printf("Lista 2: ");
    list_print(l2);
    
    printf("Il minimo è %d\n",listMinimo(l2));
    
    TInfo info;
    int pos;
    
    printf("Valore da inserire: ");
    scanf("%d",&info);
    
    printf("Posizione: ");
    scanf("%d",&pos);
    
    l2 = listInsertAt(l2,info,pos);
    
    printf("Lista 2 modificata: ");
    list_print(l2);
    
    return (EXIT_SUCCESS);
}

TInfo listSomma(TList l) {
    /*CASO BASE*/
    if(!l) return 0;
    
    /*DIVIDE ET IMPERA*/
    TInfo sum = listSomma(l->link);
    
    /*COMBINA*/
    return sum+l->info;
}

//PRE: la lista non è vuota
TInfo listMinimo(TList l) {
    /*CASO BASE*/
    if(!(l->link)) return l->info;
    
    /*DIVIDE ET IMPERA*/
    TInfo temp_min = listMinimo(l->link);
    
    /*COMBINA*/
    return (temp_min<l->info) ? temp_min : l->info;
}

//PRE: l'indice immesso sia all'interno della lista
TList listInsertAt (TList l,TInfo info,int pos) {
    /*CASO BASE*/
    if(pos==0) { 
       TList node = node_create(info);
       node->link = l;
       return node;
    };
    
    /*DIVIDE ET IMPERA*/
    TList tmp = listInsertAt(l->link,info,pos-1);
    
    /*COMBINA*/
    l->link = tmp;
    return l;
}