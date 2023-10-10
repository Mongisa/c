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
    if(n==0) {
        return -1;
    }
    int chosen = n/2;
    
    if(equal(v[chosen],k)) {
        return chosen;
    }
    
    if(less(v[chosen],k)) {
        int ret = ricBinRic(v+chosen+1,n-(chosen+1),k);
        if(ret==-1) return ret;
        
        return ret+chosen+1;       
    } 
    return ricBinRic(v,chosen,k);
}