/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: antoniopiodamico
 *
 * Created on 19 ottobre 2023, 14.18
 */

#include <stdio.h>
#include <stdlib.h>
#include "TArray.h"
#include "TInfo.h"
#include "TStack.h"
#include <string.h> //Serve per operazioni sulle stringe

#define CAP 5

char* reverse_string(char* string);

/*
 * 
 */

int main(int argc, char** argv) {
    
    //TStack pila = stackCreate(); è inutile creare la pila nel main
    
    char string[30];
    char* rev_string;

    /*int num;
    
    printf("Riempiamo la pila!\n");
    for(int i=0; i<CAP; i++) {
        printf("Inserisci l'elemento numero %d", i+1);
        scanf("%d", &num);
        stackPush(&pila, num);//stackPush(*pila, num); Devi passare il puntatore per questo &pila
    }*/ //Non devi prendere interi ma una stringa
    
  
    
    /*printf("Ecco la pila invertita!\n");
    for(int i=0; i<CAP; i++){
        printf("%d\t", pila_rev[i]);
    }*/
    
    printf("Inserisci una stringa: ");
    scanf("%s",string); //Salviamo la stringa nel vettore
    
    rev_string = reverse_string(string); //chiamiamo la funzione immettendo come parametro il puntatore della stringa
    
    printf("Stringa invertita: %s",rev_string);
    
    return (EXIT_SUCCESS);
}

char* reverse_string(char* string) {
    
    char rev_string[30];
    
    TStack pila = stackCreate(); //creo qui la pila
    
    int str_length = strlen(string); //La funzione restituisce la lunghezza della stringa
    
    for(int i=0;i<str_length;i++) {
        stackPush(&pila,string[i]);
    }
    
    for(int i=0;i<str_length;i++) {
        rev_string[i] = stackPop(&pila);
    }
    
    stackDestroy(&pila); //Distruggo lo stack tanto non ci serve più
    
    return rev_string;
}