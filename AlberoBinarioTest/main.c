#include <stdio.h>
#include <stdlib.h>
#include "TBST.h"

/*
 * 
 */
int main(int argc, char** argv) {

    TBinaryTree bt = binarytree_create();
    
    bt = binarytree_insert(bt,27);
    bt = binarytree_insert(bt,74);
    bt = binarytree_insert(bt,65);
    bt = binarytree_insert(bt,60);
    bt = binarytree_insert(bt,16);
    bt = binarytree_insert(bt,97);
    bt = binarytree_insert(bt,83);
    bt = binarytree_insert(bt,86);
    bt = binarytree_insert(bt,95);
    bt = binarytree_insert(bt,47);
    bt = binarytree_insert(bt,72);
    bt = binarytree_delete(bt,27);
    bt = binarytree_delete(bt,74);
    
    printf("Altezza: %d\n",binarytree_height(bt));
    binarytree_print_structure(bt);
    
    return (EXIT_SUCCESS);
}

