/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: mongisa
 *
 * Created on 25 settembre 2023, 16.21
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {

    int r,c;
    int **p,*q;
        
    printf("Inserisci numero di righe: ");
    scanf("%d",&r);
    
    printf("Inserisci numero di colonne: ");
    scanf("%d",&c);
    
    p = (int**)malloc(r * sizeof(int*));
    
    if(p == NULL) {
        printf("Errore durante l'allocazione!");
        exit(1);
    }
    
    for(int i=0;i<r;i++) {
        q = (int*)malloc(c * sizeof(int));
        
        if(q == NULL) {
            printf("Errore durante l'allocazione!");
            exit(1);
        }
        
        p[i] = q;
        printf("Allocata r%d\n",i+1);
    }
    
    for(int i=0;i<r;i++) { //Stampa vettore contenente gli indirizzi
        printf("%p\t",p[i]);
    }
    
    printf("\n");
    
    for(int rig=0;rig<r;rig++) {
        for(int col=0;col<c;col++) {
            printf("Inserisci [%d][%d]: ",rig+1,col+1);
            scanf("%d",&p[rig][col]);
        }
    }
    
    for(int rig=0;rig<r;rig++) {
        for(int col=0;col<c;col++) {
            printf("%d \t",p[rig][col]);
        }
        printf("\n");
    }
    
    //Deallocamento spazio
    for(int i=0;i<r;i++) {
        free(p[i]);
        //printf("\nDeallocata r%d",i+1);
    }
    
    free(p);
    //printf("\nDeallocato vettore colonna");
    
    return (EXIT_SUCCESS);
}