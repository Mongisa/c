/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: mongisa
 *
 * Created on 18 settembre 2023, 12.13
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {

    int array[] = {2,23,45,6};

    for (int i=0; i<4; i++) {
        printf("%p \n",&array[i]);
    };
    
    printf("\n");
            
    int *p;
            
    for(p=array; p < array + 4;p++) {
        printf("%p \n",p);
    }
    
    return (EXIT_SUCCESS);
}

