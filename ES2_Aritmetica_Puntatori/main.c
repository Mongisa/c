/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: mongisa
 *
 * Created on 18 settembre 2023, 22.03
 */

#include <stdio.h>
#include <stdlib.h>
#define DIM 100
int ins_numeri(int *indirizzo);
int stampa_numeri(int *indirizzo, int acc);
/*
 * 
 */
int main(int argc, char** argv) {
    int array[DIM];
    
    int *p = array;
    
    int acc = ins_numeri(p);
    stampa_numeri(p,acc);
    
    return (EXIT_SUCCESS);
}

int ins_numeri(int *indirizzo) {
    
    int input,acc=0;
    int *last = indirizzo + DIM;
    
    printf("Inserisci un numero: ");
    scanf("%d",&input);
    
    *indirizzo = input;
    indirizzo++;
    acc++;
    
    while(input != 0 && acc < DIM) {
        printf("Inserisci un numero: ");
        scanf("%d",&input);
        if(input != 0) {
           *indirizzo = input;
            indirizzo++;
            acc++;
        }
    };

    return acc;
};

int stampa_numeri(int *indirizzo, int acc){
    for(int i = 0;i<acc;i++) {
        printf("%d \n",*indirizzo);
        indirizzo++;
    }
};

