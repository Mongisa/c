/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: mongisa
 *
 * Created on 30 ottobre 2023, 19:29
 */

#include <stdio.h>
#include <stdlib.h>
#include "TList.h"
#include "TInfo.h"

TList scambiaElementiDuplica(TList l);
TList scambiaValoriDuplica(TList l);

int main(int argc, char** argv) {

    TList l1 = list_create();
    TList l2 = list_create();
    
    //Popolo l1
    l1 = list_insert_end(l1,4);
    l1 = list_insert_end(l1,6);
    l1 = list_insert_end(l1,2);
    l1 = list_insert_end(l1,3);
    l1 = list_insert_end(l1,9);
    
    //Popolo l2
    l2 = list_insert_end(l2,4);
    l2 = list_insert_end(l2,6);
    l2 = list_insert_end(l2,2);
    l2 = list_insert_end(l2,3);
    l2 = list_insert_end(l2,9);
    l2 = list_insert_end(l2,10);
    
    printf("Lista 1: ");
    list_print(l1);
    
    printf("Lista 2: ");
    list_print(l2);
    printf("\n");
    
    l1 = scambiaElementiDuplica(l1);
    l2 = scambiaValoriDuplica(l2);
    
    printf("Lista 1: ");
    list_print(l1);
    
    printf("Lista 2: ");
    list_print(l2);
    
    return (EXIT_SUCCESS);
}

TList scambiaElementiDuplica(TList l) {
    if(!l) return l;
    
    if(l->link == NULL) {
        list_insert_end(l,l->info);
        return l;
    }
    
    TList tmp = l;
    
    l = l->link;
    tmp->link = l->link;
    l->link = tmp;
    
    l->link->link = scambiaElementiDuplica(l->link->link);
    
    return l;
}

TList scambiaValoriDuplica(TList l) {
    if(!l) return l;
    
    if(l->link == NULL) {
        list_insert_end(l,l->info);
        return l;
    }
    
    TInfo tmp = l->info;
    
    l->info = l->link->info;
    l->link->info = tmp;
    
    scambiaValoriDuplica(l->link->link);
    
    return l;
}