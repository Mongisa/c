/* 
 * File:   main.c
 * Author: mongisa
 *
 * Created on 12 dicembre 2023, 14:10
 */

#include <stdio.h>
#include <stdlib.h>
#include "THT.h"
#include "TInfo.h"
#include "TList.h"

void esercizio1 (THashTable*,TKey);
TList esercizio2(THashTable*,TKey,TKey);
void esercizio3(THashTable*,TList);

int main(int argc, char** argv) {

    THashTable* ht = hashtable_create(2);
    
    hashtable_insert(ht, 0, 1);
    hashtable_insert(ht, 1, 4);
    hashtable_insert(ht, 2, 2);
    hashtable_insert(ht, 3, 3);
    
    printf("Stampa struttura: \n");
    hashtable_print_structure(ht);
    printf("\n");
    
    //ESERCIZIO 1
    TKey key = 4;
    esercizio1(ht,key);
    
    printf("Stampa struttura modificata: \n");
    hashtable_print_structure(ht);
    printf("\n");
    
    //ESERCIZIO 2
    TKey min = 3;
    TKey max = 4;
    TList list = esercizio2(ht,min,max);
    printf("Lista ordinata per chiave tra %d e %d:\n",min,max);
    list_print(list);
    printf("\n");
    
    //ESERCIZIO 3
    TList l = list_create();
    
    for(int i=3;i<7;i++) {
        TInfo info = {i,i+3};
        l = list_insert(l,info);
    }
    printf("Stampa lista: \n");
    list_print(l);
    printf("\n");
    
    esercizio3(ht,l);
    printf("Stampa struttura modificata: \n");
    hashtable_print_structure(ht);
    
    return (EXIT_SUCCESS);
}

void esercizio1 (THashTable* ht,TKey key) {
    TValue *v = hashtable_search(ht, key);
    
    if(v == NULL){
        
        hashtable_insert(ht, key, 1);
        
    } else {
        (*v)++;
    }
}

TList esercizio2(THashTable* ht,TKey min,TKey max) {
    TList list = list_create();
    
    for(int bucket_i=0;bucket_i<ht->bucket_number;bucket_i++) {
        for (TNode *node = ht->bucket[bucket_i]; node != NULL; node = node->link)
            if((*node).info.key>=min && (*node).info.key<=max)
            {
                list = list_insert(list,(*node).info);
            }
    }
    
    return list;
}

void esercizio3(THashTable* ht,TList list) {
    for(TNode *node = list; node != NULL; node = node->link) {
        if(hashtable_search(ht,(*node).info.key) == NULL)
            hashtable_insert(ht,(*node).info.key,(*node).info.value);
    }
}