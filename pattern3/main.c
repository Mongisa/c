#include <stdio.h>
#include <stdbool.h>
#define MAX 100

void array_leggi(int vet[], int dim_log);
int cerca_somma (int p[], int n, int*valore);
int stampa_max(int p[], int n, int *pos_secondo);

int main()
{
    int vet[MAX];
    int dim, trovato, pos, val;
   
    printf("Inserisci la dim del vettore minore di: %d\n", MAX);
    scanf("%d", &dim);
    array_leggi(vet, dim);
    
    trovato = cerca_somma(vet, dim, &val);   
    
    if(trovato)
        printf("Il valore trovato uguale alla somma degli altri valori dell'array è %d \n", val);
    else
        printf("Nessun valore dell'array è uguale alla somma degli altri valori dell'array \n");
   
   val = stampa_max(vet, dim, &pos);   
     printf ("Il secondo valore massimo è : %d in posizione %d\n", val, pos);
    
return 0;

}

/* Il sottoprogramma legge dallo standard input (ossia da tastiera) una sequenza di numeri
   interi diversi da 0; i valori letti vengono progressivamente memorizzati nel vettore 
   passato tramite il parametro vet; l'acquisizione si interrompe quando viene raggiunta
   la dimensione logica di vet (passata tramite il parametro dim_log).
*/
void array_leggi(int vet[], int dim_log){
    int curr,riemp=0;
    
    while(riemp < dim_log) {
        
        printf("Inserisci un valore: ");
        scanf("%d", &curr);
        
        
        if(curr != 0) {
            vet[riemp] = curr;
            riemp++;
        }
    }
}


/* Il sottoprogramma dato in input un array di interi, 
verifica se c’è una cella il cui contenuto è uguale alla 
somma del contenuto di tutte le altre celle. 
 * Se ci sono più celle restituisce  la prima trovata 
 * attraverso la variabile val passata per riferimento.
*/
int cerca_somma (int p[], int n, int*val){
    int i,j,acc,flag=0;
    
    for(i=0;i<n;i++) {
        acc=0;
        for(j=0;j<n;j++) {
            if(j != i) {
                acc += p[j];
            }
        }
        
        if(acc == p[i]) {
            *val = p[i];
            flag = 1;
        }
    }
    
    return flag;
}

/* Il sottoprogramma dato in input un array di interi,
 stampare il valore del massimo valore contenuto nell’array e 
 restituisce in output il primo valore trovato che è il secondo valore più grande, 
 la cui posizione è passata per riferimento attraverso la variabile pos_secondo.
*/
int stampa_max(int p[], int n, int *pos_secondo){
    int max, max_pos, max2, i, flag=0;
    
    //Ricerca massimo
    
    max_pos = 0;
    max = p[max_pos];
    
    for(i=0;i<n;i++) {
        if(p[i] > max) {
            max_pos = i;
            max = p[max_pos];
        }
    }
    
    printf("Il massimo ha valore %d (posizione %d) \n", max, max_pos);
    
    //Ricerca secondo valore massimo
    
    for(i=0; i<n; i++) {
        if(flag != 0) {
            if(i != max_pos && max2 < p[i]) {
                *pos_secondo = i;
                max2 = p[*pos_secondo];
            }
        } else if(i != max_pos) {
            flag = 1;
            *pos_secondo = i;
            max2 = p[*pos_secondo];
        }
    }
    
    return max2;
}