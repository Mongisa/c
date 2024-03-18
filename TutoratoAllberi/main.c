/* 
 * File:   main.c
 * Author: mongisa
 *
 * Created on 17 gennaio 2024, 16:03
 */

#include <stdio.h>
#include <stdlib.h>
#include "TBST.h"
#include "TInfo.h"


void prodottoNodi(TBinaryTree,TInfo*,TInfo*);
int maxDifferenza(TBinaryTree);
int isPieno(TBinaryTree);
int countNodeLevel(TBinaryTree,int);
/*
 * 
 */
int main(int argc, char** argv) {

    TBinaryTree tree = binarytree_create();
    tree = binarytree_insert(tree,8);
    tree = binarytree_insert(tree,12);
    tree = binarytree_insert(tree,7);
    tree = binarytree_insert(tree,32);
    tree = binarytree_insert(tree,15);
    tree = binarytree_insert(tree,3);
    tree = binarytree_insert(tree,6);
    tree = binarytree_insert(tree,32);
    
    TInfo prodottoPari = 0;
    TInfo prodottoDispari = 0;
    
    prodottoNodi(tree,&prodottoPari,&prodottoDispari);
    
    printf("Prodotto pari: %d, Prodotto dispari: %d\n",prodottoPari,prodottoDispari);
    
    int diff = maxDifferenza(tree);
    
    printf("Massima differenza: %d\n",diff);
    
    if(isPieno(tree)) {
        printf("L'albero è pieno\n");
    } else {
        printf("L'albero non è pieno\n");
    }
    
    binarytree_print_structure(tree);
    
    int l;
    
    printf("Inserire il livello: ");
    scanf("%d",&l);
    
    int ammount = countNodeLevel(tree,l);
    
    printf("Ci sono %d nodi",ammount);
    
    return (EXIT_SUCCESS);
}

void prodottoNodi(TBinaryTree tree,TInfo* prodottoPari,TInfo* prodottoDispari) {
    if (tree != NULL) {
        prodottoNodi(tree->left,prodottoPari,prodottoDispari);
        prodottoNodi(tree->right,prodottoPari,prodottoDispari);
        if(tree->info % 2 == 0) {
            if(*prodottoPari==0) (*prodottoPari)++;
            *prodottoPari = *prodottoPari*(tree->info);
        } else {
            if(*prodottoDispari==0) (*prodottoDispari)++;
            *prodottoDispari = *prodottoDispari*(tree->info);
        }
    }
}

int maxDifferenza(TBinaryTree bt) {
    if(bt == NULL) return -1;
    
    int dif1=0,dif2=0,difl=0,difr=0;
    
    dif1 = maxDifferenza(bt->left); 
    dif2 = maxDifferenza(bt->right);
    
    if(bt->left) {
        difl = bt->info - bt->left->info;
    }
    
    if(bt->right) {
        difr =  bt->right->info - bt->info;
    }
    
    if(dif1 > dif2 && dif1 > difl && dif1 > difr) {
        return dif1;
    } else if(dif2 > dif1 && dif2 > difl && dif2 > difr) {
        return dif2;
    } else if(difr > dif1 && difr > dif2 && difr > difl) {
        return difr;
    } else {
        return difl;
    }
}

int isPieno(TBinaryTree bt) {
    if(bt == NULL) return 1;
    
    if((bt->left && bt->right) ||(!bt->left && !bt->right)) return 0;
    
    int left = isPieno(bt->left);
    int right = isPieno(bt->right);
    
    return left && right;
}

int countNodeLevel(TBinaryTree tree,int k) {
    if(tree == NULL) return 0;
    
    int left = 0;
    int right = 0;
    
    if(k != 0) {
        k--;
        left = countNodeLevel(tree->left,k);
        right = countNodeLevel(tree->right,k);
        return left+right;
    }
    
    return left+right+1;
}