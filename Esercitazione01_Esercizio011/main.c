/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: mongisa
 *
 * Created on 24 settembre 2023, 20.22
 */

#include <stdio.h>
#include <stdlib.h>

#define DIM 10

int massimo(int *x);

int main(int argc, char** argv) {

    int numeriAr[DIM];
    
    for(int i=0; i<DIM ;i++) {
        printf("Inserisci numero %d: ",i+1);
        scanf("%d",&numeriAr[i]);
    }
    
    return (EXIT_SUCCESS);
}

int massimo(int *x) {
    
}