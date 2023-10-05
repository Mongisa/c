#include <stdio.h>
#include <stdbool.h>
#define MAX 100

int array_leggi(int vet[], int dim_fis);
int array_verifica_ordinato (int vet[], int r);
int array_cerca_multipli(int vet[], int r, int *x, int *conta);

int main()
{
    int vet[MAX];
    int riemp, x, n, conta=0;

    riemp = array_leggi(vet, MAX);
    printf("la dimensione del vettore è: %d\n", riemp);
    
    n = array_verifica_ordinato (vet, riemp);
    if(n<0)
        printf("Il vettore è ordinato in maniera crescente.\n");
    else
    	  printf("Il vettore non è ordinato in maniera crescente.\n");

    if (array_cerca_multipli(vet, riemp, &x, &conta))
        printf("Il numero di multipli di %d è: %d", x, conta);
    else 
        printf("Non ci sono multipli di %d", x);
}


/* Il sottoprogramma legge dallo standard input (ossia da tastiera) una sequenza di numeri
   interi non negativi; i valori letti vengono progressivamente memorizzati nel vettore 
   passato tramite il parametro vet; l'acquisizione si interrompe quando viene raggiunta
   la dimensione fisica di vet oppure quando viene inserito il valore 999. 
   Il sottoprogramma restituisce la dimensione logica di vet.*/

int array_leggi(int vet[],  int dim_fis){
    int curr,riemp=0;
    
    printf("Inserisci un valore non negativo (inserisci 999 per terminare): ");
    scanf("%d", &curr);
    
    while(riemp < dim_fis && curr != 999) {
        if(curr >= 0) {
            vet[riemp] = curr;
            riemp++;
        }
        
        printf("Inserisci un valore non negativo (inserisci 999 per terminare): ");
        scanf("%d", &curr);
    }
    
    return riemp;
}

/* Si chiede d'implementare un sottoprogramma che partendo da una sequenza memorizzata 
all'interno di un array vet e la sua dimensione logica specificata attraverso il parametro r
verifica che l'array sia ordinato in maniera crescente.
Il sottoprogramma restisce un valore negativo se l'array è ordinato in maniera crescente.
*/
int array_verifica_ordinato (int vet[], int r){
    int i, curr, succ;
    
    for(i=0;i<r-1;i++) {
        curr = vet[i];
        succ = vet[i+1];
        
        if(curr > succ) {
            return 1;
        }
    }
    
    return -1;
 }

/*Il sottoprogramma chiede all’utente di inserire un numero (x) compreso tra 1-100 
e ricerca i multipli di tale numero nel vettore. Per ogni occorrenza stampa la posizione 
in cui è stato trovato e conta il numero di elementi trovati (conta).
Il sottoprogramma restituisce 1 se ha trovato almeno un elemento, 0 altrimenti*/

int array_cerca_multipli (int vet[], int r, int *val, int *conta){
    int i,flag=0;
    
    printf("Inserisci un numero compreso tra 1-100: ");
    scanf("%d", &*val);
    
    while(*val < 1 || *val > 100) {
        printf("Inserisci un numero compreso tra 1-100: ");
        scanf("%d", &*val);
    }
    
    for(i=0;i<r;i++) {
        if(vet[i] % *val == 0) {
            printf("Trovato multiplo di %d in posizione %d \n", *val, i);
            *conta += 1;
            flag = 1;
        }
    }
    
    return flag;
}