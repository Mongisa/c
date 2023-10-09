/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: mongisa
 *
 * Created on 9 ottobre 2023, 11.54
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {

    struct intSt {
        int a;
        int b;
        int somma(int a,int b);
    };
    
    struct intSt c;
    
    c.a=1;
    c.b=3;
    
    printf("%d",c.somma());
    
    return (EXIT_SUCCESS);
}

