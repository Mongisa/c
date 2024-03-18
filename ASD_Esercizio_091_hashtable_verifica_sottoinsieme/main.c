#include <stdio.h>
#include <stdlib.h>
#include "THT.h"

int subset_with_hash_table(int *, int *, int, int);

int main(int argc, char** argv) {
    int T[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int S[4] = {0, 2, 3, 9};
    int R[4] = {1, 2, 3, 10};

    int sizeT = sizeof (T) / sizeof (T[0]);
    int sizeS = sizeof (S) / sizeof (S[0]);
    int sizeR = sizeof (R) / sizeof (R[0]);

    if (subset_with_hash_table(T, S, sizeT, sizeS))
        printf("S è un sottoinsieme di T");
    else
        printf("S non è un sottoinsieme di T");

    printf("\n");

    if (subset_with_hash_table(T, R, sizeT, sizeR))
        printf("R è un sottoinsieme di T");
    else
        printf("R non è un sottoinsieme di T");
    return (EXIT_SUCCESS);
}

int subset_with_hash_table(int *insieme1, int *insieme2, int size_insieme1, int size_insieme2) {
    if(size_insieme2 > size_insieme1) return 0;
    
    THashTable* ht = hashtable_create(size_insieme2);
    
    for(int i=0;i<size_insieme1;i++) {
        TKey key = insieme1[i];
        hashtable_insert(ht,key,1);
    }
    
    int check = 0;
    
    for(int i=0;i<size_insieme2;i++) {
        TKey key = {insieme2[i]};
        TValue *v = hashtable_search(ht,key);
        if(v==NULL) return 0;
    }
    
    
    return 1;
}