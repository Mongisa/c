/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: mongisa
 *
 * Created on 3 ottobre 2023, 9.59
 */

#include <stdio.h>
#include <stdlib.h>

struct hanoiSt  {
    int *o;
    int *i;
    int *d;
    int n;
};

//void hanoi(int n,int dim, int* orig, int* dest, int* interm);
void hanoi(struct hanoiSt s);
struct hanoiSt creaTorri(int n);
void pulisciTorre (int *t,int n);
void rilasciaTorri (struct hanoiSt s);
void printTorri (struct hanoiSt s);
void printTorre(int *t,int n);
//void muoviAnello(int* partenza, int* destinazione, int dim);

int main(int argc, char** argv) {

    int n;
    
    printf("Inserisci n: ");
    scanf("%d",&n);
    
    struct hanoiSt s = creaTorri(n);
    printTorri(s);
    //hanoi(s.n,s.n,s.o,s.i,s.d);
    hanoi(s);
    printTorri(s);
    rilasciaTorri(s);
    
    return (EXIT_SUCCESS);
}

/*void hanoi(int n,int dim, int* orig, int* interm, int* dest) {
    if (n==1) {
        muoviAnello(orig,dest,dim);
    } else {
        hanoi(n-1,dim,orig,dest,interm);
        muoviAnello(orig,dest,dim);
        hanoi(n-1,dim,interm,orig,dest);
    }
}*/

//Codice Visconti
void hanoi(struct hanoiSt s) {
    if(s.n == 1) { //CASO BASE
        s.d[0]=s.o[0];
        s.o[0]=0;
        return;
    } 
    
    struct hanoiSt s2=s;
    s2.n--;
    s2.d=s2.i;
    s2.i=s.d;
    s2.o++; //Abbiamo rimosso il blocco n (l'anello più grande)
    hanoi(s2);
    
    //Dobbiamo ora spostare l'ultimo anello O->D
    s2=s;
    s2.n=1;
    hanoi(s2);
    s2=s;
    s2.n--;
    s2.o=s2.i;
    s2.i=s.o;
    s2.d++; //Solo così è libera la torre di destinazione
    hanoi(s2);
}

struct hanoiSt creaTorri(int n) {
    
    struct hanoiSt s;
    
    s.o=(int *)malloc(n*sizeof(int));
    s.i=(int *)malloc(n*sizeof(int));
    s.d=(int *)malloc(n*sizeof(int));
    
    s.n = n;
    
    pulisciTorre(s.i,n);
    pulisciTorre(s.d,n);
    
    for(int i=0;i<n;i++) { //Riempie la torre o con gli anelli
        s.o[i]=n-i;
    }
    
    return s;
}

void pulisciTorre (int *t,int n) {
    for(int i=0;i<n;i++) {
        t[i]=0;
    }
}

void rilasciaTorri (struct hanoiSt s) {
    free(s.o);
    free(s.i);
    free(s.d);
}

void printTorri (struct hanoiSt s) {
    printf("\nTorre O = "); printTorre(s.o,s.n);
    printf("\nTorre I = "); printTorre(s.i,s.n);
    printf("\nTorre D = "); printTorre(s.d,s.n);
}

void printTorre(int *t,int n) {
    for(int i=0;i<n;i++) {
        //if(t[i] != 0) {
            printf(" %d ",t[i]);
        //}
    }
}

/*void muoviAnello(int* partenza, int* destinazione,int dim) {
    int i_p=0;
    int i_d=0;

    int v = dim;

    for(int i=0;i<dim;i++) {
        if(partenza[i] < v && partenza[i] != 0) {
            v=partenza[i];
            i_p=i;
        }
    }

    while (destinazione[i_d] != 0) {
        i_d++;
    }

    destinazione[i_d] = partenza[i_p];
    partenza[i_p] = 0;
}*/