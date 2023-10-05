/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: mongisa
 *
 * Created on 2 ottobre 2023, 11.24
 */

#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, char partenza, char intermedio, char destinazione);

/*
 * 
 */
int main(int argc, char** argv) {
    int n;
    
    printf("Inserisci n: ");
    scanf("%d",&n);
        
    hanoi(n,'A','B','C');
        
    return (EXIT_SUCCESS);
}

void hanoi(int n,char partenza, char intermedio, char destinazione) {
    
    if(n==1) {
        printf("\nSposta %c su %c",partenza,destinazione);
    } else {
        hanoi(n-1,partenza,destinazione,intermedio);
        printf("\nSposta %c su %c",partenza,destinazione);
        hanoi(n-1,intermedio,partenza,destinazione);
    }
}