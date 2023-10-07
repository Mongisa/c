/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: mongisa
 *
 * Created on 7 ottobre 2023, 11.19
 */

#include <stdio.h>
#include <stdlib.h>

unsigned long int fibonacci(int n);

int main(int argc, char** argv) {

    int n;
    unsigned long int f;

    printf("Inserisci n: ");
    scanf("%d",&n);

    f = fibonacci(n);

    printf("Il numero di Fibonacci di n=%d è: %ld",n,f);

    return (EXIT_SUCCESS);
}

unsigned long int fibonacci (int n) {
    if(n==0) {
        return 0;
    } else if (n==1) {
        return 1;
    }

    return fibonacci(n-1)+fibonacci(n-2);
}