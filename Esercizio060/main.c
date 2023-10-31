/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: mongisa
 *
 * Created on 31 ottobre 2023, 10:35
 */

#include <stdio.h>
#include <stdlib.h>
#include "TQueue.h"
#include "TInfo.h"

void rev(TQueue* q);
void rev_rec(TQueue* q);

int main(int argc, char** argv) {

    TQueue q = queue_create(6);
    
    //queue_add(&q,4);
    //queue_add(&q,3);
    //queue_add(&q,1);
    //queue_add(&q,10);
    //queue_add(&q,2);
    //queue_add(&q,6);
    
    TQueue q2 = q;
    
    printf("Coda: ");
    while(!queue_is_empty(&q2)) {
        infoPrint(queue_remove(&q2));
    }
    
    printf("\n");
    
    rev(&q);
    
    printf("Coda: ");
    while(!queue_is_empty(&q)) {
        infoPrint(queue_remove(&q));
    }
    
    return (EXIT_SUCCESS);
}

void rev(TQueue* q) {
    TArray a = array_create(0);
    
    while(!queue_is_empty(q)) {
        array_insert(&a,queue_remove(q));
    }
    
    for(int i=array_length(&a);i>0;i--) {
        queue_add(q,array_get(&a,i-1));
    }
    
    array_destroy(&a);
}

void rev_rec(TQueue* q) {
    if(queue_is_empty(q)) return; //CASO BASE
    TInfo tmp = queue_remove(q);
    rev_rec(q);
    queue_add(q,tmp);
}