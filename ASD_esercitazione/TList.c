/*
 * TList: lista ordinata
 */

#include <stdio.h>
#include <stdlib.h>
#include "TList.h"

/* operazioni sui nodi */

TNode *node_create(TInfo info) {
    TNode *new = malloc(sizeof (TNode));
    if (new != NULL) {
        new->info = info;
        new->link = NULL;
    }
    return new;
}

void node_destroy(TNode *node) {
    free(node);
}

/* operazioni sulle liste */

TList list_create() {
    return NULL;
}

TList list_destroy(TList list) {
    TNode *node;
    while (list != NULL) {
        node = list;
        list = list->link;
        node_destroy(node);
    }
    return list;
}

void list_print(TList list) {
    if (list != NULL) {
        info_print(list->info);
        list_print(list->link);
    } else
        printf("\n");
}

TNode *list_search(TList list, TInfo info) {
    if (list == NULL || info_greater(list->info, info))
        return NULL;
    if (info_equal(list->info, info))
        return list;
    return list_search(list->link, info);
}

TList list_insert(TList list, TInfo info) {
    if (list == NULL || info_greater(list->info, info)) {
        TNode *newnode = node_create(info);
        if(newnode == NULL) exit(1);
        newnode->link = list;
        return newnode;
    }
    list->link = list_insert(list->link, info);
    return list;
}

TList list_delete(TList list, TInfo info) {
    if (list == NULL || info_greater(list->info, info))
        return list;
    if (info_equal(list->info, info)) {
        TList m = list->link;
        node_destroy(list);
        return m;
    }
    list->link = list_delete(list->link, info);
    return list;
}