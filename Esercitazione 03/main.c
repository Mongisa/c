/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: Fabrizio
 *
 * Created on 15 ottobre 2023, 20.39
 */

#include <stdio.h>
#include <stdlib.h>
#include "TArray.h"
#include "TInfo.h"

void addElementPosArray(TArray *, int, TInfo);
void arrayPrintRec(TArray *);
void arrayCumulate(TArray *);

/*
 * 
 */
int main() {
    TArray a = arrayCreate(6);
    TInfo value = 10;
    int index = 10;
    a.item[0] = 1;
    a.item[1] = 5;
    a.item[2] = 7;
    a.item[3] = 0;
    a.item[4] = 9;
    a.item[5] = 3;


    printf("Array: ");
    arrayPrint(&a);
    printf("\n");
    arrayCumulate(&a);
    printf("Array cumulato: ");
    arrayPrintRec(&a);
    printf("\n");
    addElementPosArray(&a, index, value);
    printf("Array dopo l'aggiunta di un elemento: ");
    arrayPrintRec(&a);
    printf("\n");

}

void arrayCumulate(TArray *a) {
    if(a->length<=1) return;
    
    a->length--;
    
    arrayCumulate(a);
    
    a->length++;
    
    a->item[a->length - 1] += a->item[a->length - 2];
}

void arrayPrintRec(TArray *a) {
    if(a->length==0) return;
    
    a->length--;
    
    arrayPrintRec(a);
    
    a->length++;
    
    infoPrint(a->item[a->length - 1]);
}

void addElementPosArray(TArray *a, int index, TInfo value) {
    if(index<0) return;
    
    if(index>a->length+1) {
        arrayResize(a,index+1);
        a->item[index]=value;
        return;
    }
    
    if(a->length==a->size) {
        arrayResize(a,a->length+1);
    }
    
    for(int i=a->length-1;i>index;i--) {
        a->item[i] = a->item[i-1];
    }
    
    a->item[index]=value;
}