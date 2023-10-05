/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: mongisa
 *
 * Created on 2 ottobre 2023, 18.15
 */

#include <stdio.h>
#include <stdlib.h>

int fattoriale(int n);
/*
 * 
 */
int main(int argc, char** argv) {

    int n;
    
    printf("Inserisci numero: ");
    scanf("%d",&n);
    
    printf("%d",fattoriale(n));
    
    return (EXIT_SUCCESS);
}

int fattoriale(int n) {

    if(n==0) {
        return 1;
    } else if (n==1) {
        return 1;
    } else {
        return n*fattoriale(n-1);
    }

}

