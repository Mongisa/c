/* 
 * File:   main.c
 * Author: Fabrizio Torre
 *
 * Created on 19 ottobre 2023, 23.10
 */

#include <stdio.h>
#include <stdlib.h>
#include"TStack.h"
#include"TQueue.h"
#include"TList.h"
#include"utilita.h"


/*
 * ESERCIZIO 1:
 * Implementare la funzione ricorsiva TList list_insert_before_first_odd(TList *list, TInfo x)
 * che, applicata ad una lista di interi, inserisca un nuovo valore ‘x’ 
 * immediatamente prima del primo valore dispari; se la lista non contiene elementi dispari, 
 * la funzione inserisce ‘x’ come ultimo elemento della lista. 
 * 
 * Esempi:
 * lista: 11 12 13 14 - n: 72 --> 72 11 12 13 14
 * lista: 12 13 14 20 - n: 39 --> 12 39 13 14 20
 * lista: 7 10 14 18  - n: 10 --> 10 7 10 14 18
 * lista: 2 10 14 18  - n: 42 --> 2 10 14 18 42
 */
TList list_insert_before_first_odd(TList, TInfo);

/*
 * ESERCIZIO 2:
 * Implementare la funzione iterativa void array_rotate(TArray *, int)
 * che, ricevuti un array ed un valore n, ruoti l'array di n posizioni.
 *
 * Precondizione:
 *  - arraylist correttamente inizilizzato
 *  - n >= 0
 * 
 * Esempi:
 * array: 0 3 6 9 12 14 18 20 22 25 27
 * n = 4
 * dalla 4a posizione i valori dell'array sono: 12 14 18 20 22 25 27
 * prima della 4a posizione i valori dell'array sono: 0 3 6 9
 * dopo aver ruotato, l'array è: 12 14 18 20 22 25 27 0 3 6 9
 */
void array_rotate(TArray *, int);


/*
 * ESERCIZIO 3:
 * Implementare la funzione iterativa TQueue queue_get_even_elements(TQueue *)
 * che ricevuta una coda restituisca una nuova coda contenente gli elementi
 * in posizione pari della prima. La funzione lascia la prima coda inalterata. 
 * 
 * Se la coda in input è vuota la funzione restituirà una coda vuota.
 * 
 * Si consiglia di utilizzare una seconda coda di appoggio.
 * Provare a fornire anche un’implementazione ricorsiva della funzione.
 * 
 * Esempi:
 *    INPUT:  queue1:11 14 15 12 18 19 13 16 17 20 
 *    OUTPUT: queue2:14 12 19 16 20 
 */
TQueue queue_get_even_elements(TQueue *);
TQueue queue_get_even_elements_ric(TQueue *);

/*
 * ESERCIZIO 4:
 * Implementare la funzione iterativa TInfo stack_remove_min_value(TStack *)
 * che ricevuto in ingresso uno stack restituisca il suo elemento minimo.
 * 
 * Si consiglia di utilizzare un secondo stack di appoggio.
 * Provare a fornire anche un’implementazione ricorsiva della funzione.
 * 
 * PRECONDIZIONE
 * - lo stack non deve essere vuoto
 * 
 * Esempi:
 * stack: 1 3 2 5 4 7  --> Valore minimo dello stack: 1  --> stack: 3 2 5 4 7
 * stack: 3 2 5 4 7    --> Valore minimo dello stack: 2  --> stack: 3 5 4 7 
 * stack: 3 5 4 7      --> Valore minimo dello stack: 3  --> stack: 5 4 7
 */
TInfo stack_remove_min_value_ric(TStack *);

/*
 * 
 */
int main(int argc, char** argv) {
    /*TList lista1 = list_create();
    TList lista2 = list_create();
    TList lista3 = list_create();
    TList lista4 = list_create();
    lista1 = list_insert(lista1, 11);
    lista1 = list_insert(lista1, 12);
    lista1 = list_insert(lista1, 13);
    lista1 = list_insert(lista1, 14);

    lista2 = list_insert(lista2, 20);
    lista2 = list_insert(lista2, 12);
    lista2 = list_insert(lista2, 13);
    lista2 = list_insert(lista2, 14);

    lista3 = list_insert(lista3, 10);
    lista3 = list_insert(lista3, 18);
    lista3 = list_insert(lista3, 14);
    lista3 = list_insert(lista3, 7);

    lista4 = list_insert(lista4, 10);
    lista4 = list_insert(lista4, 18);
    lista4 = list_insert(lista4, 14);
    lista4 = list_insert(lista4, 2);

    printf("Stampo lista1: ");
    list_print(lista1);
    printf("\nStampo lista1 dopo inserimento: ");
    lista1 = list_insert_before_first_odd(lista1, 72);
    list_print(lista1);

    printf("\nStampo lista2: ");
    list_print(lista2);
    printf("\nStampo lista2 dopo inserimento: ");
    lista2 = list_insert_before_first_odd(lista2, 39);
    list_print(lista2);

    printf("\nStampo lista3: ");
    list_print(lista3);
    printf("\nStampo lista3 dopo inserimento: ");
    lista3 = list_insert_before_first_odd(lista3, 10);
    list_print(lista3);

    printf("\nStampo lista4: ");
    list_print(lista4);
    printf("\nStampo lista4 dopo inserimento: ");
    lista4 = list_insert_before_first_odd(lista4, 42);
    list_print(lista4);

    TArray array1 = array_create(0);
    int ruota_da = 4;

    array_insert(&array1, 0);
    array_insert(&array1, 3);
    array_insert(&array1, 6);
    array_insert(&array1, 9);
    array_insert(&array1, 12);
    array_insert(&array1, 14);
    array_insert(&array1, 18);
    array_insert(&array1, 20);
    array_insert(&array1, 22);
    array_insert(&array1, 25);
    array_insert(&array1, 27);

    printf("\n\\-------------------------------------------------------\\\n");

    printf("\nStampo array1\n");
    array_print(&array1);

    printf("\nStampo array1 dopo una rotazione di %d elementi\n", ruota_da);
    array_rotate(&array1, ruota_da);
    array_print(&array1);*/


    TQueue queue1 = queue_create(0);
    TQueue queue2;
    queue_add(&queue1, 11);
    queue_add(&queue1, 14);
    queue_add(&queue1, 15);
    queue_add(&queue1, 12);
    /*queue_add(&queue1, 18);
    queue_add(&queue1, 19);
    queue_add(&queue1, 13);
    queue_add(&queue1, 16);
    queue_add(&queue1, 17);
    queue_add(&queue1, 20);*/

    queue2 = queue_get_even_elements_ric(&queue1);
    printf("\n\\-------------------------------------------------------\\\n");
    printf("\nStampo queue1:");
    while (!queue_is_empty(&queue1)) {
        info_print(queue_remove(&queue1));
    }
    printf("\nStampo queue2:");
    
    while(!queue_is_empty(&queue2)) {
        info_print(queue_remove(&queue2));
    }

    /*TStack stack = stack_create();
    stack_push(&stack, 7);
    stack_push(&stack, 4);
    stack_push(&stack, 5);
    stack_push(&stack, 2);
    stack_push(&stack, 3);
    stack_push(&stack, 1);
    printf("\n\n\\-------------------------------------------------------\\\n");
    printf("\nElementi dello stack:\n");
    print_stack(stack);
    printf("\nValore minimo dello stack: %d\n", stack_remove_min_value_ric(&stack));
    printf("Elementi dello stack dopo aver rimosso il valore minimo:\n");
    print_stack(stack);
    printf("\nValore minimo dello stack: %d\n", stack_remove_min_value_ric(&stack));
    printf("Elementi dello stack dopo aver rimosso il valore minimo:\n");
    print_stack(stack);

    printf("\nValore minimo dello stack: %d\n", stack_remove_min_value_ric(&stack));
    printf("Elementi dello stack dopo aver rimosso il valore minimo:\n");
    print_stack(stack);*/

    return (EXIT_SUCCESS);
}

TList list_insert_before_first_odd(TList list, TInfo x) {
    int check=0;
    
    if(!list) return NULL;
    
    if(list->info%2==1) {
        TList node = node_create(x);
        node->link = list;
        check=1;
        return node;
    }
    
    list->link = list_insert_before_first_odd(list->link,x);
    
    if(!(list->link) && check==0) {
        TList node = node_create(x);
        list->link = node;
    }   
    
    return list;
}

void array_rotate(TArray *array, int ruota_da) {
    ruota_da = ruota_da%array_length(array);

    TArray tmp = array_create(ruota_da);
    
    /*COPIO GLI N=RUOTA_DA VALORI IN UN ARRAY TEMPORANEO*/
    for(int i=0;i<ruota_da;i++) {
        int curr = array_get(array,i);
        array_set(&tmp,i,curr);
    }
        
    /*SHIFTO GLI ELEMENTI DI *ARRAY A SINISTRA DI N=RUOTA_DA*/
    for(int i=ruota_da;i<array_length(array);i++) {
        int curr = array_get(array,i);
        array_set(array,i-ruota_da,curr);
    }
    
    /*SPOSTO GLI ELEMENTI DALL'ARRAY TEMPORANEO (TMP) NEL PRINCIPALE*/
    for(int i=0;i<array_length(&tmp);i++) {
        int curr = array_get(&tmp,i);
        array_set(array,(array_length(array)-ruota_da)+i,curr);
    }
    
    array_destroy(&tmp);
}

/*ESERCIZIO 3 ITERATIVO*/
TQueue queue_get_even_elements(TQueue *queue) {
    TQueue tmp = queue_create(0);
    TQueue pari = queue_create(0);
    
    while(!queue_is_empty(queue)) {
        TInfo curr = queue_remove(queue);
        queue_add(&tmp,curr);
    }
    
    int i = 1;
    
    while(!queue_is_empty(&tmp)) {
        TInfo curr = queue_remove(&tmp);
        queue_add(queue,curr);
        
        if(i%2==0) {
            queue_add(&pari,curr);
        }
        i++;
    }
    
    queue_destroy(&tmp);
    
    return pari;
}

/*ESERCIZIO 3 RICORSIVO*/
TQueue queue_get_even_elements_ric(TQueue *queue) {
    TQueue pari = queue_create(0);
    TStack tmp = stack_create();
    
    if(queue_is_empty(queue)) return pari; 
    
    TInfo curr = queue_remove(queue);
    
    pari = queue_get_even_elements_ric(queue);
    
    int size = queue_size(queue);
    
    queue_add(queue,curr);
        
    if(size%2==1) {
        queue_add(&pari,curr);
    }
    
    return pari;
}

/*ESERCIZIO 4 RICORSIVO*/
TInfo stack_remove_min_value_ric(TStack *stack) {
    /*CASO BASE*/
    if(!stack_is_empty(stack)) {
        int curr = stack_pop(stack);
        if(stack_is_empty(stack)) {
            return curr;
        } else {
            stack_push(stack,curr);
        }           
    }
    
    /*DIVIDE*/
    TInfo curr = stack_pop(stack);
    
    /*IMPERA*/
    TInfo res = stack_remove_min_value_ric(stack);
    
    /*COMBINA*/
    if(info_less(curr,res)) {
        stack_push(stack,res);
        return curr;
    } else {
        stack_push(stack,curr);
        return res;
    };
}
