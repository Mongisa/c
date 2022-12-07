#include <stdio.h>

void swap(int *a, int *b) {
    int c;
    
    c = *a;
    *a = *b;
    *b = c;
    
    return;
}

int main() {
    int a = 10;
    int b = 20;
    swap(&a, &b);
            
    printf("a: %d\n", a);
    printf("b: %d", b);
}