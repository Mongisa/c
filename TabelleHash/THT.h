/*
 * THT: hash table a indirizzamento chiuso
 */

#ifndef THT_H
#define THT_H
#include "TList.h"

typedef struct {
    TList *bucket;
    int bucket_number;
} THashTable;

THashTable *hashtable_create (int n);
void hashtable_destroy (THashTable* ht);
void hashtable_insert (THashTable* ht, TKey key, TValue value);
void hashtable_delete (THashTable* ht, TKey key);
TValue *hashtable_search (THashTable* ht, TKey key);
void hashtable_print(THashTable* ht);
void hashtable_print_structure(THashTable* ht);

#endif