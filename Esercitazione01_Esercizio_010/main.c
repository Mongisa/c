/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: mongisa
 *
 * Created on 24 settembre 2023, 20.08
 */

#include <stdio.h>
#include <stdlib.h>

void ordina (int *pa, int *pb);

int main(int argc, char** argv) {
    
    int n1,n2;

    printf("Inserisci primo numero: ");
    scanf("%d",&n1);
    
    printf("Inserisci secondo numero: ");
    scanf("%d",&n2);
    
    ordina(&n1,&n2);
    
    printf("%d %d", n1, n2);
    
    return (EXIT_SUCCESS);
}

void ordina (int *pa, int *pb) {
    int temp;
    
    if(*pa > *pb) {
        temp = *pa;
        *pa = *pb;
        *pb = temp;
    }
    
}