/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: mongisa
 *
 * Created on 10 ottobre 2023, 16.50
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bipoloSt {
    char* nome[2];
    int nodo1;
    int nodo2;
    int valore;
};

typedef struct bipoloSt bipoloTy;

void getBranches(bipoloTy* c,int n);

int main(int argc, char** argv) {
    
    int n;
    bipoloTy *circ;
    
    printf("Inserisci numero di bipoli: ");
    scanf("%d",&n);
    
    circ = (bipoloTy*)malloc(n*sizeof(bipoloTy));
    
    if(circ == NULL) {
        printf("Errore durante allocazione memoria dinamica!");
        exit(1);
    }
    
    getBranches(circ,n);
    
    return (EXIT_SUCCESS);
}

void getBranches(bipoloTy* c,int n) {
    
    for(int i=1;i<=n;i++) {
        char stringa[30];
        
        printf("[%d] Inserisci stringa bipolo: ",i);
        scanf("%s",stringa);
        
        char* nome = strtok(stringa," ");
        
        printf("%s",token);
        
        token = strtok(NULL," ");
        
        return;
    }
}