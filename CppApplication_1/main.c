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

long fibonacci(int n);

int main(int argc, char** argv) {

    int n;
    long f;

    printf("Inserisci n: ");
    scanf("%d",&n);

    f = fibonacci(n);

    printf("Il numero di Fibonacci di n=%d è: %ld",n,f);

    return (EXIT_SUCCESS);
}

long fibonacci (int n) {
    if(n==0 || n==1) 
        return n;

    return fibonacci(n-1)+fibonacci(n-2);
}