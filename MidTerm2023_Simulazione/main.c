/* 
 * File:   main.c
 * Author: Fabrizio Torre
 *
 * Created on 19 ottobre 2023, 23.10
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include"TStack.h"
#include"TQueue.h"
#include"TList.h"
#include"TArray.h"


/*
 * ESERCIZIO 1:
 * Implementare la funzione ricorsiva TList list_delete_at_position(TList list, int pos)
 * che cancelli l’elemento alla posizione ‘pos’ della lista,
 * dove ‘pos’ è 0 per il primo elemento della lista, 1 per il secondo elemento,
 * 2 per il terzo e così via. Se la lista non contiene abbastanza elementi
 * per avere una posizione ‘pos’, la funzione lascia la lista inalterata.
 * 
 * Esempi:
 * lista1: 1 1 2 3   - pos: 2   lista1: 1 1 3
 * lista2: 2 3 4 5 6 - pos: 4   lista2: 2 3 4 5
 * lista3: 2 3 4 5 6 - pos: 7   lista3: 2 3 4 5 6 
 */
TList list_delete_at_position(TList list, int pos);

/*
 * ESERCIZIO 2:
 * Implementare la funzione iterativa void queue_delete_kth_element(TQueue *q, int k)
 * che, ricevuti una coda ed un valore k, cancelli l'elemento in posizione k
 * lasciando inalterata il resto della coda.
 * 
 * Nota: in caso di k maggiore del numero di elementi, la funzione non avrà alcun effetto
 * 
 * Suggerimento: sfruttare il principio di funzionamento della coda per 
 * prelevare e poi inserire tutti gli elementi tranne quello da cancellare.
 * 
 * PRECONDIZIONE: 
 *  - coda non vuota
 *  - k>=0
 * 
 * Esempi: 
 * queue1: 12 8 5 33 1 9 - k:  3    queue1: 12 8 5 1 9
 * queue1: 12 8 5 1 9    - k: 10    queue1: 12 8 5 1 9
 * queue1: 12 8 5 1 9    - k:  2    queue1: 12 8 1 9 
 */
void queue_delete_kth_element(TQueue*, TInfo);


/*
 * ESERCIZIO 3:
 * Implementare la funzione iterativa void array_print_unique(TArray *array)
 * che ricevuta un array di interi ne stampi gli elementi univoci.
 * Se l’array è vuoto, la funzione non effettua alcuna stampa.
 * 
 * Esempi:
 * arraynum1: 1 2 3 4 3 6 8 8 9 
 * elementi univoci di arraynum1: 1 2 4 6 9 
 * 
 * arraynum2: 23 2 4 8 4 18 8 21 33 2 
 * elementi univoci di arraynum2: 23 18 21 33 
 */
void array_print_unique(TArray *);

/*
 * 
 */
int main(int argc, char** argv) {
    TList lista1 = list_create();
    TList lista2 = list_create();
    TList lista3 = list_create();

    lista1 = list_insert(lista1, 1);
    lista1 = list_insert(lista1, 1);
    lista1 = list_insert(lista1, 2);
    lista1 = list_insert(lista1, 3);

    lista2 = list_insert(lista2, 2);
    lista2 = list_insert(lista2, 3);
    lista2 = list_insert(lista2, 4);
    lista2 = list_insert(lista2, 5);
    lista2 = list_insert(lista2, 6);

    lista3 = list_insert(lista3, 2);
    lista3 = list_insert(lista3, 3);
    lista3 = list_insert(lista3, 4);
    lista3 = list_insert(lista3, 5);
    lista3 = list_insert(lista3, 6);

    /*
     EFFETTUA UNA STAMPA DELLA LISTA.
     CHIAMA LA FUNZIONE PER CANCELLARE ELEMENTO.
     STAMPA NUOVAMENTE LA LISTA PER VERIFICARE CHE LA CANCELLAZIONE SIA ANDATA A BUON FINE
     */
    list_print(lista1);
    list_print(lista2);
    list_print(lista3);
    
    printf("\nDopo le modifiche\n");
    
    lista1 = list_delete_at_position(lista1,2);
    lista2 = list_delete_at_position(lista2,4);
    lista3 = list_delete_at_position(lista3,7);
    
    list_print(lista1);
    list_print(lista2);
    list_print(lista3);


    TQueue queue1 = queue_create(0);
    queue_add(&queue1, 12);
    queue_add(&queue1, 8);
    queue_add(&queue1, 5);
    queue_add(&queue1, 33);
    queue_add(&queue1, 1);
    queue_add(&queue1, 9);

    /*
     CHIAMA LA FUNZIONE PER CANCELLARE ELEMENTO.
     * SCRIVI IL CODICE PER PRELEVARE TUTTI GLI ELEMENTI DELLA CODA E STAMPARLI
     */
    int k=-1;
        
    do {
        printf("Inserisci la posizione dell'elemento: ");
        scanf("%d",&k);
    } while(k<0);
    
    if(queue_is_empty(&queue1)==0) {
        queue_delete_kth_element(&queue1,k);
    } else {
        printf("\nCoda vuota!");
    };
    
    while(queue_is_empty(&queue1) != 1) {
        printf("%d ",queue_remove(&queue1));
    }


    int dim1 = 9, dim2 = 10;
    TArray array1 = array_create(0);
    TArray array2 = array_create(0);

    TInfo arraynum1[] = {1, 2, 3, 4, 3, 6, 8, 8, 9};
    TInfo arraynum2[] = {23, 2, 4, 8, 4, 18, 8, 21, 33, 2};

    for (int i = 0; i < dim1; i++) {
        array_insert(&array1, arraynum1[i]);
    }

    for (int i = 0; i < dim2; i++) {
        array_insert(&array2, arraynum2[i]);
    }

    /*
     EFFETTUA UNA STAMPA DELL'ARRAY.
     CHIAMA LA FUNZIONE PER STAMPARE ELEMENTI UNICI.
     */

    return (EXIT_SUCCESS);
}

TList list_delete_at_position(TList list, int pos) {
    if(list==NULL) return list;
    
    TList l;
    
    if(pos==0) {
        l=list->link;
        node_destroy(list);
        return l;
    }
    
    list->link = list_delete_at_position(list->link,pos-1);
    
    return list;
}

void queue_delete_kth_element(TQueue *q, int k) {
    
    TQueue q2 = queue_create(0);
    
    int i=0;
    
    while(!queue_is_empty(q)) {
        int n = queue_remove(q);
        if(i!=k) {
            queue_add(&q2,n);
        }
        i++;
    }
    
    while(!queue_is_empty(&q2)) {
        queue_add(q,queue_remove(&q2));
    }
}

void array_print_unique(TArray *array) {
    /*
     INSERISCI IL CODICE
     */
}