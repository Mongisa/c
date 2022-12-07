#include <stdio.h>
#define SIZE 100

int multipli(int m, int n, int v[]);

int main() {
    int n,m, num;
    int v[SIZE];
    
    printf("Inserisci il numero: ");
    scanf("%d", &m);
    
    printf("Inserisci la fine dell'intervallo: ");
    scanf("%d", &n);
    
    if(n > SIZE) {
        printf("Il numero massimo di multipli non può superare %d", SIZE);
        return 0;
    }
    
    num = multipli(m, n, v);
    
    printf("Numero multipli: %d\n", num);
    
    for(int i=0; i<num; i++) {
        printf("%d ", v[i]);
    }
    
    return 0;
}

int multipli(int m, int n, int v[]) {

    int i;
    
    for(i = 0; (i+1)*m<=n; i++) {
        v[i] = m*(i+1);
    }
    
    return i;
}