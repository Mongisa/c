#include <stdio.h>
#include <stdlib.h>
#include "THT.h"

int verifica_somma_hash_table(int *, int, int);

int main(int argc, char** argv) {
    int T[10] = {1, 2, 4, 3, 5, 9, 7, 8, 10, 6};

    int sizeT = sizeof (T) / sizeof (T[0]);
    int sum = 19; //55

    if (verifica_somma_hash_table(T, sizeT, sum))
        printf("Tutto Ok");
    else
        printf("Non vi sono numeri");


    return (EXIT_SUCCESS);
}

int verifica_somma_hash_table(int *T, int sizeT, int sum) {
    if(sizeT == 1 || sizeT == 0) return 0;
    
    THashTable* ht = hashtable_create(5);
    
    for(int i=0;i<sizeT;i++) {
        TKey key = {T[i]};
        hashtable_insert(ht,key,1);
    }
    
    for (int i = 0; i < ht->bucket_number; i++) {
        for (TNode *node = ht->bucket[i]; node != NULL; node = node->link) {
            int diff = sum - (*node).info.key;
            if(diff>0 && diff != (*node).info.key) {
                TValue *v = hashtable_search(ht,diff);
                if(v) return 1;
            }
        }     
    }
    return 0;
}