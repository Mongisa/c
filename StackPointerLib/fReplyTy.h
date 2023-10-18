/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   fReplyTy.h
 * Author: mongisa
 *
 * Created on 18 ottobre 2023, 19.44
 */

#ifndef FREPLYTY_H
#define FREPLYTY_H

#include <stdbool.h>
#include "infoTy.h"

typedef struct fReplySt { //Valore di ritorno di alcune funzioni
    bool check;
    infoTy res;
} fReplyTy;

#endif /* FREPLYTY_H */

