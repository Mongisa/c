#include <stdio.h>
#include <stdlib.h>
#include "THT.h"
#include "TBST.h"

/*  E' tempo di saldi in libreria!!! I libri salvati in un albero binario (elenco1), 
 *  ogni elemento TInfo è costituito da una key di tipo numerico (univoca) 
 *  da un Value costituito dal campo Titolo e Prezzo.
 * 
 *  (1111: Anna Karenina, prezzo: 23.00€)
 *  (1238: L'amore ai tempi del colera, prezzo: 21.00€)
 *  (1321: Le mille e una notte, prezzo: 20.12€)
 *  (1445: Il processo, prezzo: 17.25€)
 *  (2234: Madame Bovary, prezzo: 18.00€)
 *  (2372: Orgoglio e pregiudizio, prezzo: 9.50€)
 *  (3432: Finzioni, prezzo: 12.75€)
 *  (4223: Delitto e castigo, prezzo: 27.10€)
 *  (6643: Il vecchio e il mare, prezzo: 13.00€)
 *
 *
 *  FUNZIONE 1
 *  Funzione RICORSIVA che prende tutti i libri dall'elenco 1 e li inserisce
 *  in elenco2 se il prezzo del libro è inferiore o uguale al limit, altrimenti 
 *  applica uno sconto percentuale pari alla variabile sconto e, se il prezzo 
 *  scontato è inferiore o uguale a limit, lo inserisce. La funzione deve lasciare
 *  elenco1 inalterato.
 * 
 *  OUTPUT ATTESO:
 *  (3432: Finzioni, prezzo: 12.75€)
 *  (6643: Il vecchio e il mare, prezzo: 13.00€)
 *  (2372: Orgoglio e pregiudizio, prezzo: 9.50€)
 *  (2234: Madame Bovary, prezzo: 14.40€)
 *  (1445: Il processo, prezzo: 13.80€)
 *
 * 
 *  FUNZIONE 2
 *  Funzione che stampa in ordine crescente i libri presenti in elenco2.
 *  
 *  OUTPUT ATTESO:
 *  (2372: Orgoglio e pregiudizio, prezzo: 9.50€)
 *  (3432: Finzioni, prezzo: 12.75€)
 *  (6643: Il vecchio e il mare, prezzo: 13.00€)
 *  (1445: Il processo, prezzo: 13.80€)
 *  (2234: Madame Bovary, prezzo: 14.40€)
 */

void BST_to_HT(TBinaryTree,THashTable*,float,int);
void HT_print_in_order(THashTable*);

int main(int argc, char** argv) {
    
    TBinaryTree elenco1 = binarytree_create();
    THashTable *elenco2 = hashtable_create(3);
    
    elenco1 = binarytree_insert(elenco1,(TInfo){1321, "Le mille e una notte",20.12});
    elenco1 = binarytree_insert(elenco1, (TInfo){2372, "Orgoglio e pregiudizio", 9.5});
    elenco1 = binarytree_insert(elenco1, (TInfo){3432, "Finzioni",12.75});
    elenco1 = binarytree_insert(elenco1, (TInfo){4223, "Delitto e castigo",27.10});
    elenco1 = binarytree_insert(elenco1, (TInfo){1445, "Il processo",17.25});
    elenco1 = binarytree_insert(elenco1, (TInfo){2234, "Madame Bovary",18});
    elenco1 = binarytree_insert(elenco1, (TInfo){1238, "L'amore ai tempi del colera",21});
    elenco1 = binarytree_insert(elenco1, (TInfo){6643, "Il vecchio e il mare",13});
    elenco1 = binarytree_insert(elenco1, (TInfo){1111, "Anna Karenina",23});
    
    printf("Stampa elenco1: \n");
    binarytree_visit(elenco1);
    
    float sconto = 0.2;
    int limit = 15;
    
    BST_to_HT(elenco1,elenco2,sconto,limit);
    
    printf("\nStampa elenco2:\n");
    //hashtable_print(elenco2);
    
    HT_print_in_order(elenco2);
    
    binarytree_destroy(elenco1);
    hashtable_destroy(elenco2);
    
    return (EXIT_SUCCESS);
}

/*  FUNZIONE 1
 *  Funzione RICORSIVA che prende tutti i libri dall'elenco 1 e li inserisce
 *  in elenco2 se il prezzo del libro è inferiore o uguale al limit, altrimenti 
 *  applica uno sconto percentuale pari alla variabile sconto e, se il prezzo 
 *  scontato è inferiore o uguale a limit, lo inserisce. La funzione deve lasciare
 *  elenco1 inalterato.
 */
void BST_to_HT(TBinaryTree elenco1,THashTable* elenco2,float sconto,int limit) {
    
    if(elenco1 == NULL)
        return;
    
    BST_to_HT(elenco1 -> left, elenco2, sconto, limit);
    BST_to_HT(elenco1 -> right, elenco2, sconto, limit);
    
    if (elenco1 -> info.value.prezzo <= limit)
        hashtable_insert(elenco2, elenco1->info.key, elenco1->info.value);
    else if( (elenco1->info.value.prezzo)*(1-sconto) <= limit){
        elenco1->info.value.prezzo = (elenco1->info.value.prezzo)*(1-sconto);
        hashtable_insert(elenco2, elenco1->info.key, elenco1->info.value);
    }
    
}

/* FUNZIONE 2
 * Funzione che stampa in ordine crescente i libri presenti in elenco2.
 */
void HT_print_in_order(THashTable* elenco2) {
    TBinaryTree matteo = binarytree_create();
     
    int i;
    TNode *n;
    for (i = 0; i < elenco2->bucket_number; i++)
        for (n = elenco2->bucket[i]; n != NULL; n = n->link) {
            matteo = binarytree_insert(matteo,n->info);
    }
    
    binarytree_visit(matteo);
}