/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: mongisa
 *
 * Created on 25 settembre 2023, 11.15
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct alunnoSt {
    char nome[30];
    char cognome[30];
    int voto;
} alunnoTy;

int main(int argc, char** argv) {
    
    alunnoTy* p = (alunnoTy*)malloc(10*sizeof(alunnoTy));
    
    if(p == NULL) {
        printf("Errore durante l'allocazione");
        exit(EXIT_FAILURE);
    }
    
    printf("%d\n",(int)(sizeof(alunnoTy)));
    printf("%p\n",p);
    printf("%p\n",p+1);
    
    return (EXIT_SUCCESS);
}

