/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: mongisa
 *
 * Created on 10 ottobre 2023, 9.04
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 15

typedef int infoTy;

bool equal (infoTy v, infoTy k) {
    return v==k;
}

bool less (infoTy v, infoTy k) {
    return v<=k;
}

int ricBinRic(infoTy *v, int n, infoTy k);

int main(int argc, char** argv) {

    int res;
    
    infoTy vet[15] = {3,5,7,8,9,12,15,16,18,29,36,39,45,48,56};
    
    res = ricBinRic(vet,MAX,56);
    
    if(res >= 0) {
        printf("L'elemento ha indice [%d]",res);
    } else {
        printf("Elemento non trovato!");
    }
    
    return (EXIT_SUCCESS);
}

int ricBinRic(infoTy *v, int n, infoTy k) {
    if(n==0) { //CASO BASE INIZIO
        return -1;
    }
    int chosen = n/2;
    
    if(equal(v[chosen],k)) {
        return chosen;
    } //CASO BASE FINE
    
    if(less(v[chosen],k)) { //COMBINA
        int ret = ricBinRic(v+chosen+1,n-(chosen+1),k); //DIVIDE ET IMPERA
        if(ret==-1) return ret; //COMBINA
        
        return ret+chosen+1; //COMBINA 
    } 
    int ret = ricBinRic(v,chosen,k); //DIVIDE ET IMPERA
    return ret; //COMBINA
}