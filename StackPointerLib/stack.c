#include "stack.h"

stackTy s_create() {
    stackTy sp;
    sp.n=0;
    return sp;
}

void s_destroy(stackTy* sp) {
    sp->n = 0;
}

bool s_isEmpty(stackTy* sp) {
    return sp->n==0;
}

bool s_isFull(stackTy* sp) {
    return sp->n==CAPACITY;
}

fReplyTy s_pop(stackTy* sp) {
    fReplyTy r;
    
    if(s_isEmpty(sp) == true) {
        r.check = false;
        r.res = 0;
        return r;
    }
    
    r.check = true;
    r.res = sp->a[sp->n-1];
    sp->n--;
    
    return r;
}

fReplyTy s_push(stackTy* sp) {
    fReplyTy r;
    
    if(s_isFull(sp) == true) {
        r.check = false;
        r.res = 0;
        return r;
    }
    
    r.check = true;
    r.res = 0;
    
    sp->a[sp->n-1];
    sp->n++;
    
    return r;
}

void printStack(stackTy* sp) {
    printf("\n");
    for(int i=0;i<sp->n;i++) {
        printf("%d ",sp->a[i]);
    }
}