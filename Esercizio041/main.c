/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: mongisa
 *
 * Created on 30 ottobre 2023, 19:00
 */

#include <stdio.h>
#include <stdlib.h>
#include "TStack.h"
#include <string.h>
#include <stdbool.h>

void getString(char* str);
void pushInStack(TStack* s,char* str);
bool contaParentesi(TStack* s);

int main(int argc, char** argv) {

    char str[30];
    TStack s = stack_create();
    
    getString(str);
    pushInStack(&s,str);
    
    if(contaParentesi(&s)) {
        printf("La sintassi è corretta");
    } else {
        printf("La sintassi non è corretta!");
    }
    
    return (EXIT_SUCCESS);
}

void getString(char* str) {
    
    printf("Inserisci espressione: ");
    scanf("%s",str);
    
}

void pushInStack(TStack* s,char* str) {
    int str_length = strlen(str);
    
    for(int i=0;i<str_length;i++) {
        stack_push(s,str[i]);
    }
}

bool contaParentesi(TStack* s) {
    int c_tonde = 0;
    int c_quadre = 0;
    int c_graffe = 0;
    
    while(!stack_is_empty(s)) {
    
    char c = stack_pop(s);
    
    switch(c) {
        case '(':
            if(c_tonde < 0) c_tonde++;
            break;
        case ')':
            c_tonde--;
            break;
        case '[':
            if(c_quadre < 0) c_quadre++;
            break;
        case ']':
            c_quadre--;
            break;
        case '{':
            if(c_graffe < 0) c_graffe++;
            break;
        case '}':
            c_graffe--;
            break;
    }
    }
    
    return (c_tonde == 0 && c_quadre == 0 && c_graffe == 0) ? true : false;
}