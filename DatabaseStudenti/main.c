/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: mongisa
 *
 * Created on 26 settembre 2023, 9.47
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studenteSt {
    char matricola[15];
    char nome[30];
    char cognome[30];
} studenteTy;

typedef struct esameSt {
    char matricola[15];
    char esame[30];
    int voto;
} esameTy;

void inserisciStudente(int i,studenteTy* databaseStudenti);
void inserisciEsame(int i_studente,int i_voto,esameTy* databaseEsami, studenteTy* databaseStudenti);
int studenteEqual(studenteTy,studenteTy);
int setNome(studenteTy* indirizzo,char* nome);
int setCognome(studenteTy* indirizzo,char* cognome);
int setMatricola(studenteTy* indirizzo,char* matricola);
int somma(studenteTy studente, esameTy* databaseEsami, int esami_totali);


int main(int argc, char** argv) {
    int n_studenti,n_esami;
    int dim_esami;
    studenteTy *databaseStudenti;
    esameTy *databaseEsami;
    
    printf("Inserisci numero studenti da inserire: ");
    scanf("%d",&n_studenti);
    
    while(n_studenti<=0) {
        printf("Inserisci un numero valido: ");
        scanf("%d",&n_studenti);
    }
    
    dim_esami = 2*n_studenti;
    
    databaseStudenti = malloc(n_studenti * sizeof(studenteTy));
    databaseEsami = malloc(dim_esami * sizeof(esameTy));
    
    if(databaseStudenti == NULL) {
        printf("Errore durante l'allocazione!");
        exit(1);
    }
    
    if(databaseEsami == NULL) {
        printf("Errore durante l'allocazione!");
        exit(1);
    }
    
    for(int i=0;i<n_studenti;i++) {
        inserisciStudente(i,databaseStudenti);
        
        printf("Quanti esami vuoi inserire? ");
        scanf("%d",&n_esami);
        
        if(n_esami > 2) {
            dim_esami += (n_esami-2);
            databaseEsami = realloc(databaseEsami, dim_esami);
            
            if(databaseEsami == NULL) {
                printf("Errore durante l'allocazione!");
                exit(1);
            }
        }
    
        for(int k=0;k<n_esami;k++) {
            inserisciEsame(i,k,databaseEsami, databaseStudenti);
        }
    }
    
    //
    
    for(int i_studente=0;i_studente<n_studenti;i_studente++) {
        studenteTy studente;
        
        strcpy(&studente.nome,databaseStudenti[i_studente].nome);
        strcpy(&studente.cognome,databaseStudenti[i_studente].cognome);
        strcpy(&studente.matricola,databaseStudenti[i_studente].matricola);
        
        int sum = somma(studente, databaseEsami, dim_esami);
        
        printf("Nome: %s | Cognome: %s | Matricola: %s | Somma voti: %d\n",studente.nome,studente.cognome,studente.matricola,sum);
    }
    
    free(databaseStudenti);
    free(databaseEsami);
    
    return (EXIT_SUCCESS);
}

void inserisciStudente(int i,studenteTy* databaseStudenti) {
    int n;
    studenteTy studente1,studente2;
    int confronto = 1;
    
    do {
        if(confronto == 1) {
            printf("Inserisci matricola: ");
            scanf("%s",studente1.matricola);
        } else  {
            printf("La matricola è già presente!\n");
            printf("Inserisci matricola: ");
            scanf("%s",studente1.matricola);
        }
    
        for(int k=0;k<i;k++) {
            strcpy(studente2.matricola,(databaseStudenti+k)->matricola);
        
            confronto = studenteEqual(studente1,studente2);
        }
    
    } while(confronto==0);
    
    printf("Inserisci nome: ");
    scanf("%s",&studente1.nome);
    
    setNome(&(databaseStudenti+i)->nome,&studente1.nome);
    
    printf("Inserisci cognome: ");
    scanf("%s",&studente1.cognome);
    
    setCognome(&(databaseStudenti+i)->cognome,&studente1.cognome);
    
    setMatricola(&(databaseStudenti+i)->matricola,&studente1.matricola);
    
}

void inserisciEsame(int i_studente,int i_voto,esameTy* databaseEsami, studenteTy* databaseStudenti) {
    
    printf("Inserisci nome dell'esame[%d]: ",i_voto+1);
    scanf("%s",&databaseEsami[i_voto].esame);
    
    printf("Inserisci voto[%d]: ",i_voto+1);
    scanf("%d",&databaseEsami[i_voto].voto);
        
    strcpy(&databaseEsami[i_voto].matricola,databaseStudenti[i_studente].matricola);
    
    printf("Esame inserito con successo!\n");
}

int studenteEqual(studenteTy studente1,studenteTy studente2) {  
    return strcmp(studente1.matricola,studente2.matricola);
}

int setNome(studenteTy* indirizzo,char* nome) {
    
    strcpy(indirizzo,nome);
    
    return 1;
}

int setCognome(studenteTy* indirizzo,char* cognome) {
    
    strcpy(indirizzo,cognome);
    
    return 1;
}

int setMatricola(studenteTy* indirizzo,char* matricola) {
    
    strcpy(indirizzo,matricola);
    
    return 1;
}

int somma(studenteTy studente, esameTy* databaseEsami, int esami_totali) {
    int sum = 0;
    
    for(int i=0;i<esami_totali;i++) {
        if(strcmp(studente.matricola, databaseEsami[i].matricola) == 0) {
            sum += databaseEsami[i].voto;
        }
    }
    
    return sum;
}