#include <stdio.h>
#include <stdlib.h>
#include "TArray.h"
#include "TList.h"
#include "TInfo.h"

/* TRACCIA:
* Dato un array dinamico arr, gia' popolato, i cui elementi sono di tipo INT, 
* e messe a disposizione le funzioni per la gestione di List e ArrayList,
* si chiede di progettare e implementare le seguenti due funzioni:
* 
* TList popolaListaDaArray(TArray) ITERATIVA
*  
* La funzione prende in input l’array dinamico e restituisce una lista ordinata contenente gli elementi di arr.
* Di tale funzione, si chiede una implementazione iterativa. 
* 
* TInfo sommaDispari(TList) RICORSIVA
* 
* La funzione prende in input la lista e restituisce la somma dei soli
* elementi della lista che hanno valori dispari.
* Di tale funzione, si chiede una implementazione ricorsiva. 
* 
* Nota: si precisa che eventuali versioni iterative della funzione sommaDispari 
* o ricorsive della funzione popolaListaDaArray non saranno valutate.
*/

TList popolaListaDaArray(TArray);
TInfo sommaDispariRic(TList);
int trovaMinimoArray(TArray);

int main(int argc, char** argv) {

    TArray a = array_create(0);
    
    array_insert(&a,7);
    array_insert(&a,4);
    array_insert(&a,11);
    array_insert(&a,19);
    array_insert(&a,15);
    
    printf("Array: ");
    array_print(&a);
    
    TList l = popolaListaDaArray(a);
    
    printf("Lista ordinata: ");
    list_print(l);
        
    printf("\nSomma dispari: %d",sommaDispariRic(l));
    
    return (EXIT_SUCCESS);
}

TList popolaListaDaArray(TArray a) {
    TList l = list_create();
        
    while(array_length(&a) != 0) {
        int pos = trovaMinimoArray(a);
        int curr = array_get(&a,pos);
        l = list_insert_end(l,curr);
        
        array_set(&a,pos,array_get(&a,array_length(&a)-1));
        array_set(&a,array_length(&a)-1,curr);
        array_resize(&a,array_length(&a)-1);
    }
    
    return l;
}

TInfo sommaDispariRic(TList l) {
    
    /*CASO BASE*/
    if(!l) return 0;
    
    /*DIVIDE ET IMPERA*/
    TInfo res = sommaDispariRic(l->link);
    
    /*COMBINA*/
    if(l->info%2==1) {
        return l->info+res;
    } else {
        return res;
    }
    
    /* MODO PIU' RAPIDO 
     * //CASO BASE
     * if(!l) return 0;
     *
     * //DIVIDE ET IMPERA
     * return (l->info%2==1) ? l->info+sommaDispari(l->link) : sommaDispari(l->link);
     */
}

/*FUNZIONI DI APPOGGIO*/
int trovaMinimoArray(TArray a) {
    int pos = 0;
    
    for(int i=0;i<array_length(&a);i++) {
        int curr = array_get(&a,i);
        int min = array_get(&a,pos);
        if(curr < min) {
            pos = i;
        }
    }
    
    return pos;
}