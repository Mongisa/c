/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: mongisa
 *
 * Created on 16 ottobre 2023, 23.43
 */

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

/*
 * 
 */
int main(int argc, char** argv) {
    stackTy sp;
    fReplyTy res;
    sp = s_create();
    
    res = s_pop(&sp);
    
    if(!res.check) {
        printf("Fallita");
    };
    
    return (EXIT_SUCCESS);
}

