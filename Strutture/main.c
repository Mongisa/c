/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: mongisa
 *
 * Created on 19 settembre 2023, 8.49
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Manipolazione stringhe

typedef struct alunnoSt {
    char nome[30];
    char cognome[30];
    int voto;
} alunnoTy;

int main(int argc, char** argv) {
    
    int n;
    char cog_ricerca[30];
    alunnoTy alunni[20];
    
    printf("Inserisci numero di alunni: ");
    scanf("%d",&n);
    
    for(int i=0; i<n; i++) {
        printf("Inserisci nome: ");
        scanf("%s",alunni[i].nome);
        printf("Inserisci cognome: ");
        scanf("%s",alunni[i].cognome);
        printf("Inserisci voto: ");
        scanf("%d",&alunni[i].voto);
    }
    
    printf("Inserisci cognome da ricercare: ");
    scanf("%s",cog_ricerca);
    
    for(int i=0; i<n; i++) {
        int check = strcmp(cog_ricerca,alunni[i].cognome);
        
        if(!check) {
            printf("[%d] Cognome: %s - Nome: %s - Voto: %d \n",(i+1),alunni[i].cognome,alunni[i].nome,alunni[i].voto);
        }
    }
    
    
    return (EXIT_SUCCESS);
}

