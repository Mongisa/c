#include <stdio.h>
#include <stdlib.h>
#include "TList.h"
#include "TStack.h"

TList listInvertStack(TList);

int main(int argc, char** argv) {

    TList l = list_create();
    
    l = list_insert_end(l,3);
    l = list_insert_end(l,10);
    l = list_insert_end(l,-10);
    l = list_insert_end(l,100);
    
    printf("Lista: ");
    list_print(l);
    
    l = listInvertStack(l);
    
    printf("Lista m: ");
    list_print(l);
    
    return (EXIT_SUCCESS);
}

TList listInvertStack(TList l) {
    
    TStack s = stack_create();
    
    TList curr = l;
    
    while(curr) {
        stack_push(&s,curr->info);
        curr = curr->link;
    }
    
    l = list_destroy(l);
    
    l = list_create();
    
    while(!stack_is_empty(&s)) {
        l = list_insert_end(l,stack_pop(&s));
    }
    
    stack_destroy(&s);

    return l;
}
