/*
 * THT: hash table a indirizzamento chiuso
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "THT.h"
#include "TInfo.h"

/* PRE: buckets > 0
 */
THashTable *hashtable_create(int buckets) {
    int i;
    THashTable *p = (THashTable *) malloc(sizeof (THashTable));
    assert(p != NULL);
    assert(buckets > 0);
    p->bucket_number = buckets;
    p->bucket = (TList *) malloc(sizeof (TList) * buckets);
    assert(p->bucket != NULL);
    for (i = 0; i < buckets; i++)
        p->bucket[i] = list_create();
    return p;
}

void hashtable_destroy(THashTable* ht) {
    for (int i = 0; i < ht->bucket_number; i++)
        ht->bucket[i] = list_destroy(ht->bucket[i]);
    free(ht->bucket);
    free(ht);
}

unsigned hash(TKey key) {
    return (unsigned) key;
}

TValue *hashtable_search(THashTable* ht, TKey key) {
    unsigned h = hash(key) % ht->bucket_number;
    TInfo info;
    info.key = key;
    TNode *node = list_search(ht->bucket[h], info);
    if (node == NULL)
        return NULL;
    else
        return &node->info.value;
}

void hashtable_insert(THashTable* ht, TKey key, TValue value) {
    TInfo info;
    info.key = key;
    info.value = value;
    unsigned h = hash(key) % ht->bucket_number;
    //list_print(ht->bucket[h]);
    TNode *node = list_search(ht->bucket[h], info);
    if (node == NULL) {
        ht->bucket[h] = list_insert(ht->bucket[h], info);
    } else
        node->info = info;

}

void hashtable_delete(THashTable* ht, TKey key) {
    TInfo info;
    info.key = key;
    unsigned h = hash(key) % ht->bucket_number;
    ht->bucket[h] = list_delete(ht->bucket[h], info);
}

void hashtable_print(THashTable * ht) {
    int i;
    TNode *n;
    for (i = 0; i < ht->bucket_number; i++)
        for (n = ht->bucket[i]; n != NULL; n = n->link) {
            info_print(n->info);
        }
}

void hashtable_print_structure(THashTable * ht) {
    for (int i = 0; i < ht->bucket_number; i++) {
        printf("Bucket %2d-> ", i);
        for (TNode *node = ht->bucket[i]; node != NULL; node = node->link)
            info_print(node->info);
        printf("\n");
    }
}