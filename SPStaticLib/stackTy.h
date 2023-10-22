/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   header.h
 * Author: mongisa
 *
 * Created on 16 ottobre 2023, 22.01
 */

#ifndef HEADER_H
#define HEADER_H

#define CAPACITY 100

#include <stdbool.h>
#include "infoTy.h"
#include "fReplyTy.h"

typedef struct stackSt {
    int n;
    infoTy a[CAPACITY];
} stackTy;

stackTy s_create(void); //Crea lo stack
void s_destroy(stackTy*); //Distrugge lo stack
fReplyTy s_push(stackTy*,infoTy); //Aggiunge un elemento alla testa dello stack
fReplyTy s_pop(stackTy*); //Elimina un elemento dalla testa dello stack e lo ritorna
fReplyTy s_top(stackTy*); //Da in output l'elemento in testa allo stack senza eliminarlo
bool s_isEmpty(stackTy*); //Ritorna TRUE se lo stack è vuoto
bool s_isFull(stackTy*); //Ritorna TRUE se lo stack è pieno

#endif /* HEADER_H */