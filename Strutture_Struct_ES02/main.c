/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: mongisa
 *
 * Created on 24 settembre 2023, 13.59
 */

#include <stdio.h>
#include <stdlib.h>

#define DIM 30

typedef struct alunnoSt {
    char nome[30];
    char cognome[30];
    int voto;
} alunnoTy;

void leggi(int N, alunnoTy *vet);
int media(int N, alunnoTy *vet);

int main(int argc, char** argv) {
    int N,med;
    
    alunnoTy alunniAr[DIM];

    printf("Inserisci numero studenti: ");
    scanf("%d",&N);
    
    while (N > DIM) {
        printf("Inserisci numero studenti (<25): ");
        scanf("%d",&N);
    };
        
    leggi(N,alunniAr);
    
    med = media(N,alunniAr);
    
    for(int i=0;i<N;i++) {
        printf("%s %s %d \n",alunniAr[i].cognome,alunniAr[i].nome, alunniAr[i].voto);
    };
    
    printf("Voto medio: %d",med);

    return (EXIT_SUCCESS);
};

void leggi(int N, alunnoTy *vet) {
    for(int i=0;i<N;i++) {
        printf("[%d] Inserisci nome: ",i+1);
        scanf("%s", (vet+i)->nome);
        
        printf("[%d] Inserisci cognome: ",i+1);
        scanf("%s", (vet+i)->cognome);
        
        printf("[%d] Inserisci voto: ",i+1);
        scanf("%d", &(vet+i)->voto);
    }
};

int media(int N, alunnoTy *vet) {
    int med = 0;
    
    for(int i=0; i<N; i++) {
        med += (vet+i)->voto;
    }
    
    return (int)(med/N);
};