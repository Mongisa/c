/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: mongisa
 *
 * Created on 9 ottobre 2023, 19.24
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 50

struct studenteSt {
    char nome[MAX];
    char cognome[MAX];
    int voto;
};

typedef struct studenteSt studenteTy;

void leggi(int n,studenteTy* vet);
int media(int n,studenteTy* vet);
void stampa(int n,studenteTy* vet, int media);

int main(int argc, char** argv) {
    
    int N;
    studenteTy *vet;
    
    printf("Inserisci n: ");
    scanf("%d",&N);
    
    vet = (studenteTy*)malloc(N*sizeof(studenteTy));
    
    leggi(N,vet);
    
    stampa(N,vet,media(N,vet));
    
    return (EXIT_SUCCESS);
   
}

void leggi(int n,studenteTy *vet) {
    for(int i=0;i<n;i++) {
        printf("[%d] Inserisci nome: ",i+1);
        scanf("%s",vet[i].nome);
        
        printf("[%d] Inserisci cognome: ",i+1);
        scanf("%s",vet[i].cognome);
        
        printf("[%d] Inserisci voto: ",i+1);
        scanf("%d",&vet[i].voto);
    }
}

int media(int n,studenteTy* vet) {
    int media = 0;
    
    for(int i=0;i<n;i++) {
        media += vet[i].voto;
    }
    
    return (int)(media/n);
}

void stampa(int n,studenteTy* vet, int media) {
    
    for(int i=0;i<n;i++) {
        printf("[%d] Nome: %s Cognome: %s Voto: %d\n",i+1,vet[i].nome,vet[i].cognome,vet[i].voto);
    }
    
    printf("Media voti: %d", media);
}