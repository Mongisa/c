#include <stdio.h>
#include <stdlib.h>
#include "TQueue.h"
#include "TList.h"
#include "TInfo.h"

void listInvertQueueRec(TList,TQueue*);

int main(int argc, char** argv) {
    
    TList l = list_create();
    TQueue q = queue_create(0);
    
    l = list_insert(l,4);
    l = list_insert(l,10);
    l = list_insert(l,-1);
    l = list_insert(l,30);
    l = list_insert(l,27);
    
    printf("Lista: ");
    list_print(l);
    
    listInvertQueueRec(l,&q);
    
    while(!queue_is_empty(&q)) {
        infoPrint(queue_remove(&q));
    }
    
    printf("\n");
    printf("Lista m: ");
    list_print(l);
    
    return (EXIT_SUCCESS);
}

void listInvertQueueRec(TList l,TQueue* q) {
    if(!l) return;
    
    queue_add(q,l->info);
    
    listInvertQueueRec(l->link,q);
    
    l->info = queue_remove(q);
}