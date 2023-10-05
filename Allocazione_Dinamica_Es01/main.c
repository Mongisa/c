/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: mongisa
 *
 * Created on 25 settembre 2023, 11.45
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {

    int n;
    int *p;
    
    printf("Inserisci la grandezza del vettore: ");
    scanf("%d",&n);

    p = (int*)malloc(n * sizeof(int));
    
    if(p == NULL) {
        printf("Errore durante l'allocazione!");
        exit(EXIT_FAILURE);
    }
        
    printf("Vettore allocato con successo! \t [%p]\n",p);
    
    for(int i=0;i<n;i++) { //Input
        printf("Inserisci numero [%d]: ",i+1);
        scanf("%d",&p[i]);
    }
    
    for(int i=0;i<n;i++) { //Output
        printf("%d\t",*(p+i));
    }
    
    printf("\nInserisci la nuova taglia del vettore: ");
    scanf("%d",&n);
    
    p = (int*) realloc(p,sizeof(int)*n);
    
    if(p == NULL) {
        printf("Errore durante l'allocazione!");
        exit(EXIT_FAILURE);
    }
    
    printf("Nuovo indirizzo [%p]", p);
    
    free(p); //Pulizia memoria
    
    return (EXIT_SUCCESS);
    
}