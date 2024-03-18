#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TBST.h"

bool confronta_binarytree(TBinaryTree, TBinaryTree);

void attraversa_dispari(TBinaryTree);
void attraversa_pari(TBinaryTree);

void binarytree_print_between(TBinaryTree, TInfo, TInfo);

TBTNode* lowest_common_ancestor(TBinaryTree, TInfo, TInfo);

void second_largest_util(TBinaryTree, int*);

void second_largest(TBinaryTree);

int one_child(TBinaryTree);

TBTNode *binarytree_parent(TBinaryTree bt, TBTNode *node);

TBinaryTree binarytree_invert(TBinaryTree tree);

int main(int argc, char** argv) {

    TBinaryTree tree = binarytree_create();
    TBinaryTree tree2 = binarytree_create();
    TBinaryTree tree3 = binarytree_create();
    
    /*tree = binarytree_insert(tree, 6);
    tree = binarytree_insert(tree, 1);
    tree = binarytree_insert(tree, 10);
    tree = binarytree_insert(tree, 8);
    tree = binarytree_insert(tree, 9);
    
    tree2 = binarytree_insert(tree2, 6);
    tree2 = binarytree_insert(tree2, 1);
    tree2 = binarytree_insert(tree2, 10);
    tree2 = binarytree_insert(tree2, 8);
    tree2 = binarytree_insert(tree2, 9);*/

    tree = binarytree_insert(tree, 8); //inserire 6 per testare oneChild
    tree = binarytree_insert(tree, 6);
    tree = binarytree_insert(tree, 1);
    /*tree = binarytree_insert(tree, 10);
    tree = binarytree_insert(tree, 8);
    tree = binarytree_insert(tree, 9);*/
    tree = binarytree_insert(tree, 18);
    tree = binarytree_insert(tree, 1);
    tree = binarytree_insert(tree, 16);
    tree = binarytree_insert(tree, 21);
    //tree = binarytree_insert(tree, 7);
    tree = binarytree_insert(tree, 3);

    tree2 = binarytree_insert(tree2, 10);
    tree2 = binarytree_insert(tree2, 20);
    tree2 = binarytree_insert(tree2, 30);
    tree2 = binarytree_insert(tree2, 15);
    tree2 = binarytree_insert(tree2, 5);
    tree2 = binarytree_insert(tree2, 14);
    tree2 = binarytree_insert(tree2, 18);
    tree2 = binarytree_insert(tree2, 1);
    tree2 = binarytree_insert(tree2, 16);
    tree2 = binarytree_insert(tree2, 21);
    tree2 = binarytree_insert(tree2, 7);
    tree2 = binarytree_insert(tree2, 3);

    printf("\nStampo il primo albero a video:\n");
    binarytree_print_structure(tree);

    /*printf("\n\nStampo il secondo albero a video:\n");
    binarytree_print_structure(tree2);*/

    /*
     * confronta_binarytree
     */
    printf("\n\nConfronto i due alberi binari:\n");
    if (confronta_binarytree(tree, tree2))
        printf("i due alberi sono uguali\n");
    else
        printf("i due alberi non sono uguali\n");

    /*
     * attraversa_pari
     */
    printf("\nNodi di livello pari: ");
    attraversa_pari(tree);

    /*
     * binarytree_print_between
     * TInfo min = 7, max = 15;
     */
    TInfo min = 9, max = 16;
    printf("\n\nElementi tra %d e %d: ", min, max);
    binarytree_print_between(tree, min, max);

    /*
     * lowest_common_ancestor
     */
    printf("\n\nCerco il primo antenato comune tra %d e %d.", min, max);
    TBTNode *n = lowest_common_ancestor(tree, min, max);
    if (n != NULL)
        printf("\nPrimo antenato comune tra %d e %d: %d", min, max, n->info);
    else
        printf("\nNon ci sono antenati comuni tra %d e %d", min, max);

    /*
     * secondLargest
     */
    printf("\n\nIl secondo nodo con valore maggiore è: ");
    second_largest(tree);
    
    /*
     * oneChild
     */
    printf("\n\nIl numero di nodi con un solo figlio è: %d\n", one_child(tree));

    /*
     * binarytree_parent
     */
    /*int i = 9;
    printf("\n\nCerco il padre di %d:\n", i);
    n = binarytree_parent(tree, binarytree_search(tree, i));
    if (n != NULL)
        printf("il padre di %d è: %d\n", i, n->info);
    else
        printf("%d non appartiene all'albero\n", i);*/
    
    binarytree_print_structure(tree);
    
    tree = binarytree_invert(tree);
    
    binarytree_print_structure(tree);


    tree = binarytree_destroy(tree);
    tree2 = binarytree_destroy(tree2);


    return (EXIT_SUCCESS);
}

bool confronta_binarytree(TBinaryTree t1, TBinaryTree t2) {
    if(!t1 && !t2) return true;
    if(!t1 || !t2) return false;
    
    /*if(t1->info != t2->info) return false;
    if(!confronta_binarytree(t1->left,t2->left)) return false;
    if(!confronta_binarytree(t1->right,t2->right)) return false;
    return true;*/
    
    return (t1->info == t2->info) && confronta_binarytree(t1->left,t2->left) && confronta_binarytree(t1->right,t2->right);
}

void attraversa_pari(TBinaryTree t) {
    if(!t) return;
    info_print(t->info);
    attraversa_dispari(t->left);
    attraversa_dispari(t->right);
}

void attraversa_dispari(TBinaryTree t) {
    if(!t) return;
    attraversa_pari(t->left);
    attraversa_pari(t->right);
}

void binarytree_print_between(TBinaryTree bt, TInfo min, TInfo max) {
    if(!bt) return;
    
    if(info_less(min,bt->info) || info_equal(min,bt->info)) binarytree_print_between(bt->left,min,max);
    if(!info_less(bt->info,min) && !info_greater(bt->info,max))
        info_print(bt->info);
    if(info_greater(max,bt->info)) binarytree_print_between(bt->right,min,max);
}

TBTNode* lowest_common_ancestor(TBinaryTree bt, TInfo info1, TInfo info2) {
    if(!bt) return NULL;
    
    if((info_less(info1,bt->info) || info_equal(info1,bt->info)) && (info_less(info2,bt->info) || info_equal(info2,bt->info))) {
        return lowest_common_ancestor(bt->left,info1,info2);
    } else if(info_greater(info1,bt->info) && info_greater(info2,bt->info)){
        return lowest_common_ancestor(bt->right,info1,info2);
    } else if(binarytree_search(bt,info1) && binarytree_search(bt,info1)) {
        return bt;
    }
}

/* 
 * Una funzione di utilita' per trovare il 2° elemento più grande in un albero BST.
 */
void second_largest_util(TBinaryTree root, int *c) {
    if (root == NULL || *c >= 2) {
        return;
    }

    // Visita in-order inversa (destra, radice, sinistra)
    second_largest_util(root->right, c);

    // Incrementa il conteggio dei nodi visitati
    (*c)++;

    // Se il conteggio raggiunge 2, stampa il secondo elemento più grande
    if (*c == 2) {
        info_print(root->info);
        return;
    }

    second_largest_util(root->left, c);
}

/*
 *  Funzione per trovare il 2° elemento più grande in un albero BST.
 */
void second_largest(TBinaryTree bt) {
    // Inizializza il conteggio dei nodi visitati a 0
    
    int c = 0;

    // Si noti che c è passato per riferimento
    second_largest_util(bt, &c);

}

int one_child(TBinaryTree bt) {
    if(!bt) return 0;
  
    if(bt->left && !bt->right) {
        return 1+one_child(bt->left);
    } else if(bt->right && !bt->left){
        return 1+one_child(bt->right);
    }
    
    return one_child(bt->left)+one_child(bt->right);
}

TBTNode *binarytree_parent(TBinaryTree bt, TBTNode *node) {
    
}

TBinaryTree binarytree_invert(TBinaryTree tree) {
    if(!tree->left && !tree->right) return tree;
    
    TBTNode *tmp = tree->left;
    
    tree->left = tree->right ? binarytree_invert(tree->right) : NULL;
    tree->right = tmp ? binarytree_invert(tmp) : NULL;
    
    return tree;
}