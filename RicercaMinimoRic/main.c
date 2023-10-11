/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: mongisa
 *
 * Created on 11 ottobre 2023, 18.09
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define DIM 7

typedef int infoTy;

int ricercaMinimoRic(infoTy vet[], int n);
bool less(infoTy a, infoTy b) {
    if(a < b) {
        return true;
    } else {
        return false;
    }
}

int main(int argc, char** argv) {

    infoTy vet[DIM] = {2,3,-50,1,0,3,-20};

    printf("Il minimo valore ha indice %d\n",ricercaMinimoRic(vet, DIM));

    return (EXIT_SUCCESS);
}

int ricercaMinimoRic(infoTy vet[], int n){ 

    if(n==1) return 0; //CASO BASE

    int min_I = ricercaMinimoRic(vet,n-1); //DIVIDE ET IMPERA
    
    if(less(vet[min_I],vet[n-1])) { //COMBINA
        return min_I;
    } else {
        return n-1;
    }

};

/*int ricercaMinimoRic(infoTy vet[], int n){ //VERSIONE RIDOTTA

    if(n==1) return 0;

    int min_I = ricercaMinimoRic(vet,n-1);

    return (less(vet[min_I],vet[n-1])) ? min_I : n-1;

};*/